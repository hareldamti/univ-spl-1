#pragma once
#include <vector>
#include "Party.h"
#include "Simulation.h"
using namespace std;

class Party;

class Coalition {
    public:
        Coalition(int partyId, int id);
        vector<int> getPartiesIds() const;
        int mId;
        int getMandates(Simulation &sim);
        void addParty(int partyId);
        
    private:
        vector<int> mPartiesIds;
};
