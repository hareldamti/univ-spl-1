#pragma once
#include <string>
#include "Agent.h"
using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    Party(const Party &other);
    Party(Party&& other);
    Party& operator=(const Party& other);
    Party& operator=(Party&& other);
    

    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getId() const;
    void step(Simulation &s);
    const string &getName() const;
    ///TODO: Delete
    //void joinCoalition(const Agent &agent, Simulation &s);
    void addRequest(const Agent &agent);
    JoinPolicy& getJoinPolicy() const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    vector<int> mRequests;
};
