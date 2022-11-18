#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
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

void Agent::step(Simulation &sim)
{
    Party &selectedParty = (*mSelectionPolicy).chooseParty();
    selectedParty.addRequest(*this);
}

void Agent::setId(int id)
{
    mAgentId = id;
}

void Agent::setPartyId(int id)
{
    mPartyId = id;
}
