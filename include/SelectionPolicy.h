#pragma once
class Simulation;
class Agent;

class SelectionPolicy {
    public:
        virtual const int choosePartyId(Simulation &s, Agent &agent) = 0;

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        virtual const int choosePartyId(Simulation &s, Agent &agent);

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        virtual const int choosePartyId(Simulation &s, Agent &agent);
};