#pragma once
#include <vector>
using namespace std;

class Party;

class Coalition {
    public:
        Coalition(int partyId, int id);
        vector<int> getPartiesIds() const;
        int mId;
        int getMandates(const Simulation &sim) const;
        void addParty(int partyId);
        
    private:
        vector<int> mPartiesIds;
};
