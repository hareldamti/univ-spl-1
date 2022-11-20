#pragma once
#include <vector>
using std::vector;

class Party;
class Simulation;
class Agent;

class JoinPolicy {
    public:
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests) = 0;
        virtual JoinPolicy* clone() = 0;
        virtual ~JoinPolicy() = 0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests);
        virtual MandatesJoinPolicy* clone();
        virtual ~MandatesJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests);
        virtual LastOfferJoinPolicy* clone();
        virtual ~LastOfferJoinPolicy();
};

