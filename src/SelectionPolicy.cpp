#include "SelectionPolicy.h"
#include "Simulation.h"

SelectionPolicy::SelectionPolicy(){}
SelectionPolicy::SelectionPolicy(const SelectionPolicy& other) {}
SelectionPolicy::SelectionPolicy(SelectionPolicy&& other) {}
SelectionPolicy& SelectionPolicy::operator=(const SelectionPolicy& other) {return *this;}
SelectionPolicy& SelectionPolicy::operator=(SelectionPolicy&& other) {return *this;}
SelectionPolicy::~SelectionPolicy(){}

MandatesSelectionPolicy::MandatesSelectionPolicy(){}
MandatesSelectionPolicy::MandatesSelectionPolicy(const MandatesSelectionPolicy& other) {}
MandatesSelectionPolicy::MandatesSelectionPolicy(MandatesSelectionPolicy&& other) {}
MandatesSelectionPolicy& MandatesSelectionPolicy::operator=(const MandatesSelectionPolicy& other) {return *this;}
MandatesSelectionPolicy& MandatesSelectionPolicy::operator=(MandatesSelectionPolicy&& other) {return *this;}
MandatesSelectionPolicy::~MandatesSelectionPolicy(){}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy& other) {}
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(EdgeWeightSelectionPolicy&& other) {}
EdgeWeightSelectionPolicy& EdgeWeightSelectionPolicy::operator=(const EdgeWeightSelectionPolicy& other) {return *this;}
EdgeWeightSelectionPolicy& EdgeWeightSelectionPolicy::operator=(EdgeWeightSelectionPolicy&& other) {return *this;}
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){}

///TODO: Delete above


MandatesSelectionPolicy* MandatesSelectionPolicy::clone(){ return new MandatesSelectionPolicy; }
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone(){ return new EdgeWeightSelectionPolicy; }

const int MandatesSelectionPolicy::choosePartyId(Simulation &s, Agent &agent)
{
    vector<int> *neighbors = s.getGraph().getNeighborsIds(agent.getPartyId());
    
    int currPartyId = -1, currMandates = -1;
    for (int u : *neighbors)
    {
        Party& p = s.getParty_(u);
        if (p.getState() != Joined)
        {
            bool requested = false;
            for (int idx : p.getRequests()) if (idx == agent.getId()) requested = true;
            if (!requested) {
                int uMandates = p.getMandates();
                if (uMandates > currMandates)
                {
                    currPartyId = u;
                    currMandates = uMandates;
                }
            }
        }
    }

    delete neighbors;
    return currPartyId;
}

const int EdgeWeightSelectionPolicy::choosePartyId(Simulation &s, Agent &agent)
{
    int v = agent.getPartyId();
    vector<int> *neighbors = s.getGraph().getNeighborsIds(v);
    
    int currPartyId = -1, currWeight = -1;
    for (int u : *neighbors)
    {
        Party& p = s.getParty_(u);
        if (p.getState() != Joined)
        {
            bool requested = false;
            for (int idx : p.getRequests()) if (idx == agent.getId()) requested = true;
            if (!requested) {
                int uWeight = s.getGraph().getEdgeWeight(v, u);
                if (uWeight > currWeight)
                {
                    currPartyId = u;
                    currWeight = uWeight;
                }
            }
        }
    }
    delete neighbors;
    
    return currPartyId;
}
