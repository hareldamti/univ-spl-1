#include "Coalition.h"

Coalition::Coalition(const Party &party, int id) :mId(id)
{
    mParties.push_back(party);
}

vector<int>& Coalition::getPartiesIds() const
{
    return mPartiesIds;
}

int Coalition::getMandates() const
{
    int mandates = 0;
    unsigned int vecsize = mParties.size();
    for(unsigned int i = 0; i < vecsize; i++)
    {
        mandates += mParties[i].getMandates();
    }
    return mandates;
}

void addParty(int partyId){
    mParties.push_back(partyId);
}