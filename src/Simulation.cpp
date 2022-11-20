#include "Simulation.h"


Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // for(auto & agent : mAgents)
    // {
    //     Coalition c = Coalition(graph.getParty(agent.getId()));
    //     mCoalitions.push_back(c);
    // }
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::initializeCoalitions(){
    for (int i=0; i<mAgents.size(); i++){
        Agent &agent = mAgents[i];
        Coalition coalition(agent.getPartyId(), i);
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
    // TODO implement this method
    if(mAgents.size() == mGraph.getNumVertices()) return true;

    for(Coalition coalition: mCoalitions)
    {
        if(coalition.getMandates(*this) >= 61)
            return true;
            
    }
    
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

Party& Simulation::getParty_(int partyId) const
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

vector<Coalition> Simulation::getCoalitions()
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
