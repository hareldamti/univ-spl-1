#include "JoinPolicy.h"

LastOfferJoinPolicy::LastOfferJoinPolicy(){}

const Agent& LastOfferJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    int partyId = requests[requests.size()-1];
    for(const Agent & agent : s.getAgents())
    {
        if(agent.getPartyId() == partyId)
        {
            return agent;
        }
    }
}