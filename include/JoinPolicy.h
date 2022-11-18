#pragma once
#include "Simulation.h"

class JoinPolicy {
    public:
        virtual Agent &chooseAgent(Simulation &s, vector<int> &requests) = 0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        virtual Agent &chooseAgent(Simulation &s, vector<int> &requests);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        virtual Agent &chooseAgent(Simulation &s, vector<int> &requests);
};

