#pragma once
#include <vector>
#include "Party.h"
using namespace std;


class Coalition {
    public:
        Coalition(const Party &party);

        vector<const &Party> getParties() const;
        int getMandates() const;
        
    private:
        vector<const &Party> mParties;
};
