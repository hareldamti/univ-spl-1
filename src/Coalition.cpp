#include "Coalition.h"
#include "Simulation.h"
#include "Party.h"

Coalition::Coalition() :mId(-1), mMandates(0), mPartiesIds(){}

Coalition::Coalition(int partyId, int id, Simulation& s) :mId(id), mMandates(0), mPartiesIds()
{
    addParty(s, partyId);
}

vector<int> Coalition::getPartiesIds() const
{
    return mPartiesIds;
}

int Coalition::getMandates() const
{
    return mMandates;
}

void Coalition::addParty(const Simulation &sim, int partyId){
    mPartiesIds.push_back(partyId);
    mMandates += sim.getParty(partyId).getMandates();
}