#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"
#include "Simulation.h"

class Simulation;

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    int getCoalitionId() const;
    void step(Simulation &);
    void setId(int id);
    void setCoalitionId(int id);
    void setPartyId(int id);

private:
    int mAgentId;
    int mPartyId;
    int mCoalitionId;
    SelectionPolicy *mSelectionPolicy;
};
