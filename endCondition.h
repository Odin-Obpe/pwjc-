#ifndef END_CONDITION_H
#define END_CONDITION_H

class EndCondition {
    public:
    virtual bool isEnd(int currentRound) = 0;
    virtual ~EndCondition() = default;
};

class RoundEndCondition : public EndCondition {
    public:
    RoundEndCondition() : EndCondition() {}
    bool isEnd(int currentRound) override {
        return currentRound == 12;
    }
};

#endif