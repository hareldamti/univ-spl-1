#pragma once

class SelectionPolicy {
    public:
        virtual int choosePartyId(Simulation &s, Agent &agent) = 0;

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        virtual int choosePartyId(Simulation &s, Agent &agent);

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        virtual int choosePartyId(Simulation &s, Agent &agent);
};