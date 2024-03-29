#pragma once
#include <vector>
#include "Party.h"
class Simulation;

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party& getParty_(int partyId);
    vector<int> *getNeighborsIds(int v) const;
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
