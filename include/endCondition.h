#ifndef END_CONDITION_H
#define END_CONDITION_H

// Forward declaration of Game class
class Game;

class EndCondition {
    public:
    virtual bool isEnd(Game* game) = 0;
    virtual ~EndCondition() = default;
};

class RoundEndCondition : public EndCondition {
    public:
    RoundEndCondition(int roundNum) : EndCondition(), roundNum(roundNum) {}
    bool isEnd(Game* game) override;
    private:
    int roundNum;
};


class PointsEndCondition : public EndCondition {
    public:
    PointsEndCondition(int points) : EndCondition(), points(points) {}
    bool isEnd(Game* game) override;
    private:
    int points;
};
#endif