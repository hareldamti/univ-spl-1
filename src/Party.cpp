#include "Party.h"
#include "Coalition.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
    mId(id),
    mName(name),
    mMandates(mandates),
    mJoinPolicy(jp),
    mState(Waiting),
    mTimer(3),
    mRequests(){}

Party::Party(const Party &other) :
    mId(other.getId()),
    mName(other.getName()),
    mMandates(other.getMandates()),
    mJoinPolicy(other.getJoinPolicy().clone()),
    mState(other.getState()),
    mTimer(other.getTimer()),
    mRequests(other.getRequests()){}


Party::Party(Party &&other) :
    mId(other.getId()),
    mName(other.getName()),
    mMandates(other.getMandates()),
    mJoinPolicy(other.getJoinPolicy().clone()),
    mState(other.getState()),
    mTimer(other.getTimer()),
    mRequests(other.getRequests()){}


Party& Party::operator=(const Party &other){
    mId = other.getId();
    mName = other.getName();
    mMandates = other.getMandates();
    if (mJoinPolicy != nullptr) delete mJoinPolicy;
    mJoinPolicy = other.getJoinPolicy().clone();
    mState = other.getState();
    mTimer = other.getTimer();
    mRequests = other.getRequests();
    return *this;
}

Party& Party::operator=(Party &&other){
    mId = other.getId();
    mName = other.getName();
    mMandates = other.getMandates();
    if (mJoinPolicy != nullptr) delete mJoinPolicy;
    mJoinPolicy = other.getJoinPolicy().clone();
    mState = other.getState();
    mTimer = other.getTimer();
    mRequests = other.getRequests();
    other.dismissJoinPolicy();
    return *this;
}


void Party::step(Simulation &s)
{
    if (mState == CollectingOffers) {
        mTimer -= 1;
        if (mTimer == 0) {
            const Agent &selectedAgent = (*mJoinPolicy).chooseAgent(s, mRequests);
            Coalition& coalition = s.getCoalitions()[selectedAgent.getCoalitionId()];
            coalition.addParty(s, mId);
            s.recruitAgent(selectedAgent, *this);
            mState = Joined;
        }
    }
}

void Party::addRequest(const Agent &agent){
    mRequests.push_back(agent.getId());
    if (mState == Waiting) {
        mTimer = 3;
        mState = CollectingOffers;
    }
}

State Party::getState() const
{
    return mState;
}

int Party::getMandates() const
{
    return mMandates;
}

int Party::getTimer() const
{
    return mTimer;
}

JoinPolicy& Party::getJoinPolicy() const{
    return *mJoinPolicy;
}

const string& Party::getName() const
{
    return mName;
}

const vector<int>& Party::getRequests() const
{
    return mRequests;
}

int Party::getId() const {
    return mId;
}

void Party::setState(State state)
{
    mState = state;
}

void Party::dismissJoinPolicy() {
    mJoinPolicy = nullptr;
}

Party::~Party() {
    if (mJoinPolicy != nullptr)
        delete mJoinPolicy;
}