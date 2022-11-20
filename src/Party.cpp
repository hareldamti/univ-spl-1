#include "Party.h"
#include "Coalition.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    mRequests = vector<int>();
}

Party::Party(const Party &other) : mId(other.getId()), mName(other.getName()), mMandates(other.getMandates()), mJoinPolicy(other.getJoinPolicy())
{
    mRequests = vector<int>(other.getRequests());
}

Party::Party(Party &&other) : mId(other.getId()), mName(other.getName()), mMandates(other.getMandates()), mJoinPolicy(other.getJoinPolicy())
{
    mRequests = vector<int>(other.getRequests());
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
        const Agent &selectedAgent = (*mJoinPolicy).chooseAgent(s, mRequests);
        Coalition& coalition = s.getCoalitions()[selectedAgent.getCoalitionId()];
        coalition.addParty(mId);
        s.recruitAgent(selectedAgent, *this);
        mState = Joined;
    }
    if (mState == CollectingOffers) 
        mTimer -= 1;
}

void Party::addRequest(const Agent &agent){
    mRequests.push_back(agent.getId());
    if (mState == Waiting) {
        mTimer = 3;
        mState = CollectingOffers;
    }
}

JoinPolicy * Party::getJoinPolicy() const
{
    return mJoinPolicy;
}

const vector<int>& Party::getRequests() const
{
    return mRequests;
}

int Party::getId() const {
    return mId;
}