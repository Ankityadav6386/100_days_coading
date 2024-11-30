class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubArraysLessOrEqualToK(nums,k) - countSubArraysLessOrEqualToK(nums,k-1);
    }
    int countSubArraysLessOrEqualToK(vector<int> &nums, int k) {
        if(k==0) return 0;
        unordered_map<int,int> mp;
        int count = 0, i=0, j=0, n=nums.size();
        while(j<n) {
            mp[nums[j]]++;
            while(i<j && mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            count+= j-i+1;
            j++;
        }

        return count;
    }
};