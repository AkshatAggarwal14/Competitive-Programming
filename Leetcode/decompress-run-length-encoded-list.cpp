#include <bits/stdc++.h>

#include <Akshat.hpp>
using namespace std;

vector<int> decompressRLElist(vector<int>& nums) {
    map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < (int)nums.size(); i += 2)
        for (int j = 0; j < nums[i]; ++j)
            ans.emplace_back(nums[i + 1]);

    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    for (auto x : decompressRLElist(a)) cout << x << " ";
    return 0;
}