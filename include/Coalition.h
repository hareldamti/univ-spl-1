#pragma once
#include <vector>
using namespace std;

class Coalition {
    public:
        vector<int> getParties();
        int getMandates();
    private:
        vector<int> mParties;
};