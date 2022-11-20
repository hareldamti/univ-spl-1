#include "Coalition.h"
#include "Simulation.h"
#include "Party.h"

Coalition::Coalition(int partyId, int id) :mId(id)
{
    mPartiesIds.push_back(partyId);
}

vector<int> Coalition::getPartiesIds() const
{
    return mPartiesIds;
}

int Coalition::getMandates(const Simulation &sim)
{
    int mandates = 0;
    unsigned int vecsize = mPartiesIds.size();
    for(unsigned int i = 0; i < vecsize; i++)
    {
        mandates += sim.getParty(mPartiesIds[i]).getMandates();
    }
    return mandates;
}

void Coalition::addParty(int partyId){
    mPartiesIds.push_back(partyId);
}