#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :mAgentId(agentId), mPartyId(partyId),  mCoalitionId(-1), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(const Agent& other):
    mAgentId(other.getId()),
    mPartyId(other.getPartyId()),
    mCoalitionId(other.getCoalitionId()),
    mSelectionPolicy(other.getSelectionPolicy().clone()){}

Agent::Agent(Agent&& other):
    mAgentId(other.getId()),
    mPartyId(other.getPartyId()),
    mCoalitionId(other.getCoalitionId()),
    mSelectionPolicy(&other.getSelectionPolicy()){
        other.dismissSelectionPolicy();
    }

Agent& Agent::operator=(const Agent& other) {
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    mCoalitionId = other.getCoalitionId();
    if (mSelectionPolicy != nullptr) delete mSelectionPolicy;
    mSelectionPolicy = other.getSelectionPolicy().clone();
    return *this;
}

Agent& Agent::operator=(Agent&& other) {
    if (this != &other){
        mAgentId = other.getId();
        mPartyId = other.getPartyId();
        mCoalitionId = other.getCoalitionId();
        if (mSelectionPolicy != nullptr) delete mSelectionPolicy;
        mSelectionPolicy = &other.getSelectionPolicy();
        other.dismissSelectionPolicy();
    }
    return *this;
}

void Agent::dismissSelectionPolicy() {
    mSelectionPolicy = nullptr;
}


Agent::~Agent(){
    if (mSelectionPolicy != nullptr)
        delete mSelectionPolicy;
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

SelectionPolicy& Agent::getSelectionPolicy() const {
    return *mSelectionPolicy;
}

void Agent::step(Simulation &sim)
{
    int selectedPartyId = (*mSelectionPolicy).choosePartyId(sim, *this);
    if (selectedPartyId != -1) 
        ///TODO: change const in getParty signature
        sim.getParty_(selectedPartyId).addRequest(*this);
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