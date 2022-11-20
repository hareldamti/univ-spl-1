#include "SelectionPolicy.h"
#include <vector>
#include "Agent.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

const int MandatesSelectionPolicy::choosePartyId(Simulation &s, Agent &agent)
{
    vector<int> *neighbors = s.getGraph().getNeighborsIds(agent.getPartyId());
    
    int currPartyId = -1, currMandates = -1;
    for (int u : *neighbors)
    {
        int uMandates = s.getParty_(u).getMandates();
        if (uMandates > currMandates)
        {
            currPartyId = u;
            currMandates = uMandates;
        }
    }

    delete neighbors;
    return currPartyId;
}

MandatesSelectionPolicy::~MandatesSelectionPolicy(){}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}

const int EdgeWeightSelectionPolicy::choosePartyId(Simulation &s, Agent &agent)
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
    
    return currPartyId;
}

EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){}