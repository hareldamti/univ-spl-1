#include "Coalition.h"

Coalition::Coalition(const Party &party)
{
    mParties.push_back(party);
}

vector<const Party> Coalition::getParties() const
{
    vector<const Party> coalMembers = vector<const Party>(mParties);
    return coalMembers;
}

int Coalition::getMandates() const
{
    int mandates = 0;
    unsigned int vecsize = mParties.size();
    for(unsigned int i = 0; i < vecsize; i++)
    {
        mandates +=mParties[i].getMandates();
    }
    return mandates;
}