#include "JoinPolicy.h"

LastOfferJoinPolicy::LastOfferJoinPolicy(){}

const Agent& LastOfferJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    int agentId = requests[requests.size()-1];
    return s.getAgents()[agentId];
}

MandatesJoinPolicy::MandatesJoinPolicy(){}
const Agent& MandatesJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    
    int currAgentId = -1, currMandates = -1;
    for(int i = 0; i < requests.size(); i++){
        int iMandates = s.getParty(s.getAgents()[requests[i]].getPartyId()).getMandates();
        if (iMandates > currMandates)
        {
            currAgentId = i;
            currMandates = iMandates;
        }
    }

    return s.getAgents()[i];
}