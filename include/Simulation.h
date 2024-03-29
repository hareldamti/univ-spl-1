#pragma once

#include <vector>
#include "Agent.h"
#include "Party.h"
#include "Coalition.h"
#include "Graph.h"

using std::vector;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party& getParty_(int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<Coalition>& getCoalitions();
    void recruitAgent(const Agent& agent, Party& party);
    
private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};
