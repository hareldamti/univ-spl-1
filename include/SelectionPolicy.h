#pragma once
#include <vector>
using std::vector;
class Simulation;
class Agent;

class SelectionPolicy {
    public:
        SelectionPolicy();
        SelectionPolicy(const SelectionPolicy& other);
        SelectionPolicy(SelectionPolicy&& other);
        virtual SelectionPolicy& operator=(const SelectionPolicy& other);
        virtual SelectionPolicy& operator=(SelectionPolicy&& other);
        
        virtual SelectionPolicy* clone() = 0;
        virtual const int choosePartyId(Simulation &s, Agent &agent) = 0;
        
        virtual ~SelectionPolicy();

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        MandatesSelectionPolicy(const MandatesSelectionPolicy& other);
        MandatesSelectionPolicy(MandatesSelectionPolicy&& other);
        virtual MandatesSelectionPolicy& operator=(const MandatesSelectionPolicy& other);
        virtual MandatesSelectionPolicy& operator=(MandatesSelectionPolicy&& other);
        
        virtual MandatesSelectionPolicy* clone();
        virtual const int choosePartyId(Simulation &s, Agent &agent);
        
        virtual ~MandatesSelectionPolicy();

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy& other);
        EdgeWeightSelectionPolicy(EdgeWeightSelectionPolicy&& other);
        virtual EdgeWeightSelectionPolicy& operator=(const EdgeWeightSelectionPolicy& other);
        virtual EdgeWeightSelectionPolicy& operator=(EdgeWeightSelectionPolicy&& other);
        
        virtual EdgeWeightSelectionPolicy* clone();
        virtual const int choosePartyId(Simulation &s, Agent &agent);
        
        virtual ~EdgeWeightSelectionPolicy();
};