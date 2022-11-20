#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getParty_(int partyId)
{
    return mVertices[partyId];
}

vector<int> *Graph::getNeighborsIds(int v) const
{
    vector<int> *neighbors = new vector<int>(0);
    for (int u = 0; u < mVertices.size(); u++)
        if (mEdges[v][u] > 0)
            neighbors->push_back(u);
    return neighbors;
}
