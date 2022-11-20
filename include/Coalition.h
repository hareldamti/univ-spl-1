#pragma once
#include <vector>
using namespace std;

class Party;
class Simulation;

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
