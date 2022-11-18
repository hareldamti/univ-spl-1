#pragma once
#include <vector>
#include "Party.h"
using namespace std;

class Party;

class Coalition {
    public:
        Coalition(const Party &party, int id);
        vector<const Party&> getParties() const;
        int mId;
        int getMandates() const;
        void addParty(Party& party);
        
    private:
        vector<const Party&> mParties;
};
