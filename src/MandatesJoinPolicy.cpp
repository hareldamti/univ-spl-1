#include "JoinPolicy.h"

MandatesJoinPolicy::MandatesJoinPolicy(){}
const Agent& MandatesJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    
    int choice = 0;
    for(int i = 0; i < requests.size(); i++){
        if((s.getParty(requests[i])).getMandates() > (s.getParty(requests[choice])).getMandates())
            choice = i;
    }
    for(const Agent & agent : s.getAgents())
    {
        if(agent.getPartyId() == choice)
        {
            return agent;
        }
    }
}