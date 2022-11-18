#include "Party.h"

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
    if (mTimer == 0) {
        Agent &selectedAgent = (*mJoinPolicy).chooseAgent(s, mRequests);
        joinCoalition(selectedAgent, s);
    }
    if (mState == CollectingOffers) 
        mTimer -= 1;
}

void Party::joinCoalition(const Agent &agent, Simulation &s) {
    Agent newAgent(agent);
    ///TODO: change agent's fields
    s.addAgent(newAgent);
    agent.getCoalition().addParty(*this);
    mState = Joined;
}

void Party::addRequest(const Agent &agent){
    mRequests.push_back(agent.getPartyId());
    if (mState == Waiting)
        mTimer = 3;
    mState = CollectingOffers;
}
