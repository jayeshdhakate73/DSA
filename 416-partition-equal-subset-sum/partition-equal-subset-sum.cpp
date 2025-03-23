class Solution {
public:
// RECCURSION
    // bool f(int ind , int target , vector<vector<int>> &dp, vector<int> &nums){
    //     if(target==0) return true;
    //     if(ind==0) return target==nums[ind];
    //     if(dp[ind][target]!=-1) return dp[ind][target];

    //     bool take = false;
    //     if(nums[ind]<=target) take = f(ind-1,target-nums[ind],dp,nums);
    //     int notTake = f(ind-1,target,dp,nums);
    //     return dp[ind][target] = (take | notTake);
    // }
    bool canPartition(vector<int>& nums) {
        // int tsum = 0;
        // for(auto n : nums) tsum+=n;
        // if(tsum%2!=0) return false;
        // int target = tsum/2;
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return f(nums.size()-1,target,dp,nums);

        // TABULATION
        int tsum = 0;
        for(auto n : nums) tsum+=n;
        if(tsum%2!=0) return false;
        int target = tsum/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(tsum+1,0));
        for(int i = 0 ; i<nums.size() ; i++) dp[i][0] = true;
        dp[0][nums[0]] = true;

        for(int i = 1 ; i<nums.size() ; i++){
            for(int t = 1 ; t<=target ; t++){
                bool take = false;
                if(nums[i]<=t) take = dp[i-1][t-nums[i]];
                int notTake = dp[i-1][t];
                dp[i][t] = (take | notTake);
            }
        }
        return dp[nums.size()-1][target];

    }
};