/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int t) {
        map<int, int> mp;
        int tofind1, tofind2, flag = 0;
        for (int i = 0; i < nums.size(); ++i) mp[nums[i]]++;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == t * 2 and mp[nums[i]] >= 2) {
                tofind1 = nums[i];
                flag = 1;
            } else if (mp[t - nums[i]] >= 1) {
                tofind1 = nums[i], tofind2 = t - nums[i];
            }
        }
        vector<int> ans;
        if (flag) {
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] == tofind1) ans.push_back(i);
        } else {
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] == tofind1 or nums[i] == tofind2) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
