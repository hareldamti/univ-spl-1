#pragma once

class Party;
class Simulation;
class Agent;

class JoinPolicy {
    public:
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests) = 0;
        virtual ~JoinPolicy();
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests);
        virtual ~MandatesJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        virtual const Agent &chooseAgent(Simulation &s, vector<int> &requests);
        virtual ~LastOfferJoinPolicy();
};

