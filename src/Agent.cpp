#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getCoalitionId() const
{
    return mCoalitionId;
}

void Agent::step(Simulation &sim)
{
    int selectedPartyId = (*mSelectionPolicy).choosePartyId(sim, *this);
    if (selectedPartyId != -1) 
        ///TODO: change const in getParty signature
        sim.getParty(selectedPartyId).addRequest(*this);
    
}

void Agent::setId(int id)
{
    mAgentId = id;
}

void Agent::setPartyId(int id)
{
    mPartyId = id;
}

void Agent::setCoalitionId(int id)
{
    mCoalitionId = id;
}