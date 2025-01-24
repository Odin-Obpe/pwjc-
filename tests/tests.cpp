#include <catch2/catch_test_macros.hpp>
#include "Strategy.h"
#include "Player.h"

TEST_CASE("AlwaysCooperateStrategy") {
    AlwaysCooperateStrategy strategy;
    Player player;
    Player enemyPlayer;
    CHECK(strategy.execute(&player, &enemyPlayer) == Move::Cooperation);
}


TEST_CASE("AlwaysRivalryStrategy") {
    AlwaysRivalryStrategy strategy;
    Player player;
    Player enemyPlayer;
    CHECK(strategy.execute(&player, &enemyPlayer) == Move::Rivalry);
}

TEST_CASE("PointAdd") {
    AlwaysCooperateStrategy strategy;
    AlwaysRivalryStrategy enemyStrategy;
    Player coopPlayer1 = Player(1, &strategy);
    Player rivalPlayer1 = Player(2, &enemyStrategy);
    Player coopPlayer2 = Player(3, &strategy);
    Player rivalPlayer2 = Player(4, &enemyStrategy);
    coopPlayer1.fight(&rivalPlayer1);
    CHECK(coopPlayer1.points == 0);
    CHECK(rivalPlayer1.points == 5);
    coopPlayer1.fight(&coopPlayer2);
    CHECK(coopPlayer1.points == 3);
    CHECK(coopPlayer2.points == 3);
    rivalPlayer1.fight(&rivalPlayer2);
    CHECK(rivalPlayer1.points == 6);
    CHECK(rivalPlayer2.points == 1);

}