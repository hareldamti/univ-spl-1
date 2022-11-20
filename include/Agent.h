#pragma once


class Graph;
class Coalition;
class Simulation;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& other);
    Agent(Agent&& other);
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other);
    ~Agent();

    int getPartyId() const;
    int getId() const;
    int getCoalitionId() const;
    SelectionPolicy& getSelectionPolicy() const;

    void setId(int id);
    void setCoalitionId(int id);
    void setPartyId(int id);
    void dismissSelectionPolicy();

    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    int mCoalitionId;
    SelectionPolicy *mSelectionPolicy;
};
