#include "Simulation.h"
#include "Coalition.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // for(auto & agent : mAgents)
    // {
    //     Coalition c = Coalition(graph.getParty(agent.getId()));
    //     mCoalitions.push_back(c);
    // }
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    for (int i = 0; i < mGraph.getNumVertices(); i++){
        Party party = getParty(i);
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

    for(auto & coalition: mCoalitions)
    {
        if(coalition.getMandates() >= 61)
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

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> PbyC;
    for(const Coalition & coalition: mCoalitions)
    {
        vector<int> c;
        
        for(auto & p : coalition.getParties())
        {
            c.push_back(p.getId());
        }

        PbyC.push_back(c);
    }
    return PbyC;
}

vector<Coalition> Simulation::getCoalitions()
{
    return mCoalitions;
}

void Simulation::addAgent(Agent& agent)
{
    mAgents.push_back(agent);
}
