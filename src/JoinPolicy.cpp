#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"

LastOfferJoinPolicy::LastOfferJoinPolicy(){}


MandatesJoinPolicy::MandatesJoinPolicy(){}
const Agent& MandatesJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    //replacing the old wrong mandates extraction (by party instead of by coalition)
    //need to make it more efficient by not recalculating already brought up coalitions
    int currAgentId = -1, currMandates = -1;
    for(int i = 0; i < requests.size(); i++){
        int coalitionId = (s.getAgents()[requests[i]]).getCoalitionId();
        int iMandates = s.getCoalitions()[coalitionId].getMandates(s);//s.getParty(s.getAgents()[requests[i]].getPartyId()).getMandates();
        if (iMandates > currMandates)
        {
            currAgentId = i;
            currMandates = iMandates;
        }
    }

    return s.getAgents()[currAgentId];
}

MandatesJoinPolicy::~MandatesJoinPolicy() {}

const Agent& LastOfferJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    int agentId = requests[requests.size()-1];
    return s.getAgents()[agentId];
}

LastOfferJoinPolicy::~LastOfferJoinPolicy() {}