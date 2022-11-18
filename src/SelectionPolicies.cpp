#include "SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

const Party& MandatesSelectionPolicy::chooseParty(Simulation &s, Agent &agent)
{
    vector<int> *neighbors = s.getGraph().getNeighborsIds(agent.getPartyId());
    
    int currPartyId = -1, currMandates = -1;
    for (int u : *neighbors)
    {
        int uMandates = s.getParty(u).getMandates();
        if (uMandates > currMandates)
        {
            currPartyId = u;
            currMandates = uMandates;
        }
    }

    delete neighbors;
    
    ///TODO: check if reference can be NULL
    if (currPartyId == -1) return NULL;
    return s.getParty(currPartyId);
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}

const Agent& EdgeWeightSelectionPolicy::chooseParty(Simulation &s, Agent &agent)
{
    int v = agent.getPartyId();
    vector<int> *neighbors = s.getGraph().getNeighborsIds(v);
    
    int currPartyId = -1, currWeight = -1;
    for (int u : *neighbors)
    {
        int uWeight = s.getGraph().getEdgeWeight(v, u);
        if (uWeight > currWeight)
        {
            currPartyId = u;
            currWeight = uWeight;
        }
    }

    delete neighbors;
    
    ///TODO: check if reference can be NULL
    if (currPartyId == -1) return NULL;
    return s.getParty(currPartyId);
}
