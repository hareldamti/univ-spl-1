#pragma once
#include <vector>
#include "Party.h"
using namespace std;

class Party;

class Coalition {
    public:
        Coalition(const Party &party, int id);
        vector<int> getPartiesIds() const;
        int mId;
        int getMandates() const;
        void addParty(int partyId);
        
    private:
        vector<int> mPartiesIds;
};
