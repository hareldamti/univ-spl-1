#pragma once
#include "Simulation.h"

class JoinPolicy {
    public:
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests) = 0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests);
};