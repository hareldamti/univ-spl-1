#pragma once

class JoinPolicy {
    public:
        virtual Agent &chooseAgent(Simulation &s, vector<int> &requests) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};