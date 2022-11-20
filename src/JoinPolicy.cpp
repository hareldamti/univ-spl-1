#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"


LastOfferJoinPolicy::LastOfferJoinPolicy(){}
MandatesJoinPolicy::MandatesJoinPolicy(){}

JoinPolicy::~JoinPolicy(){}
MandatesJoinPolicy::~MandatesJoinPolicy() {}
LastOfferJoinPolicy::~LastOfferJoinPolicy() {}


MandatesJoinPolicy* MandatesJoinPolicy::clone() { return new MandatesJoinPolicy; }
LastOfferJoinPolicy* LastOfferJoinPolicy::clone() { return new LastOfferJoinPolicy; }

const Agent& MandatesJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    int currAgentId = -1, currMandates = -1;
    for(long unsigned int i = 0; i < requests.size(); i++){
        int coalitionId = (s.getAgents()[requests[i]]).getCoalitionId();
        int iMandates = s.getCoalitions()[coalitionId].getMandates();
        if (iMandates > currMandates)
        {
            currAgentId = i;
            currMandates = iMandates;
        }
    }

    return s.getAgents()[currAgentId];
}

const Agent& LastOfferJoinPolicy::chooseAgent(Simulation &s, vector<int> &requests)
{
    int agentId = requests[requests.size()-1];
    return s.getAgents()[agentId];
}

