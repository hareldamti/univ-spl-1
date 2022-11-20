#pragma once
#include <string>
#include <vector>


using std::vector;
using std::string;

class JoinPolicy;
class Agent;
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
    ~Party();

    State getState() const;
    int getMandates() const;
    int getId() const;
    int getTimer() const;
    JoinPolicy& getJoinPolicy() const;
    const string &getName() const;
    const vector<int>& getRequests() const;

    void setState(State state);
    void dismissJoinPolicy();

    void step(Simulation &s);
    void addRequest(const Agent &agent);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    vector<int> mRequests;
};
