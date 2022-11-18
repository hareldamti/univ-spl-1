#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setId(int id);
    void setPartyId(int id);

private:
    int mAgentId;
    int mPartyId;
    // Coalition *mCoalition;
    SelectionPolicy *mSelectionPolicy;
};
