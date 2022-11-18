#pragma once

class SelectionPolicy {
    public:
        virtual Party& chooseParty(Simulation &s, Agent &agent) = 0;

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        virtual Party& chooseParty(Simulation &s, Agent &agent);

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        virtual Party& chooseParty(Simulation &s, Agent &agent);
};