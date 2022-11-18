#include "Party.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    mRequests = vector<int>(0);
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if (mState == CollectingOffers) 
        mTimer -= 1;
    if (mTimer == 0) {
        Agent &selectedAgent = (*mJoinPolicy).chooseAgent(s, mRequests);
        joinCoalition(selectedAgent, s);
    }
}

void Party::joinCoalition(const Agent &agent, Simulation &s) {
    /*we need a way to access party information thorugh agents*/
    // int newId = (s.getAgents()).size();
    // Agent newAgent = Agent(agent);
    // newAgent.setId(newId);
    // newAgent.setPartyId(mId);
    // s.addAgent(newAgent);
    
    
    // TODO: Implement
}

void Party::addRequest(const Agent &agent){
    //if(mState == Waiting) mState = CollectingOffers;
    mRequests.push_back(agent.getPartyId());
}
