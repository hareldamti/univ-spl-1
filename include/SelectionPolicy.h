#pragma once
#include <vector>
using std::vector;
class Simulation;
class Agent;

class SelectionPolicy {
    public:
        virtual const int choosePartyId(Simulation &s, Agent &agent) = 0;
        virtual ~SelectionPolicy();

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        virtual const int choosePartyId(Simulation &s, Agent &agent);
        virtual ~MandatesSelectionPolicy();

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        virtual const int choosePartyId(Simulation &s, Agent &agent);
        virtual ~EdgeWeightSelectionPolicy();
};