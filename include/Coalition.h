#pragma once
#include <vector>
using namespace std;

class Party;
class Simulation;

class Coalition {
    public:
        Coalition();
        Coalition(int partyId, int id, Simulation& s);
        vector<int> getPartiesIds() const;
        int getMandates() const;
        void addParty(const Simulation &sim, int partyId);

    private:
        int mId;
        int mMandates;
        vector<int> mPartiesIds;
};
