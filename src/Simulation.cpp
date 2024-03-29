#include "Simulation.h"

///TODO: DEBUG
#include <iostream>
using namespace std;


Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions()
{
    mCoalitions = vector<Coalition>();
    for (long unsigned int i=0; i<mAgents.size(); i++){
        Agent &agent = mAgents[i];
        Coalition coalition(agent.getPartyId(), i, *this);
        mCoalitions.push_back(coalition);
        agent.setCoalitionId(i);
    }
}

void Simulation::step()
{
    for (int i = 0; i < mGraph.getNumVertices(); i++){
        Party& party = getParty_(i);
        party.step(*this);
    }
    for (Agent &agent : mAgents){
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    if(mAgents.size() == mGraph.getNumVertices())
        return true;

    for(const Coalition& coalition: mCoalitions)
        if(coalition.getMandates() >= 61)
            return true;
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party& Simulation::getParty_(int partyId)
{
    return mGraph.getParty_(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> PbyC;
    for(const Coalition & coalition: mCoalitions)
    {
        vector<int> c(coalition.getPartiesIds());
        PbyC.push_back(c);
    }
    return PbyC;
}

vector<Coalition>& Simulation::getCoalitions()
{
    return mCoalitions;
}

void Simulation::recruitAgent(const Agent& agent, Party& newParty)
{
    Agent newAgent(agent);
    newAgent.setId(mAgents.size());
    newAgent.setPartyId(newParty.getId());
    mAgents.push_back(newAgent);
}
