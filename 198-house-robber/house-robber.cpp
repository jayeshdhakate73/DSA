// class Solution {
// public:
//     int Solve(vector<int>& nums,int n, int i){
    //     //base case
    //     if(i>=n){
    //         return 0;
    //     }

    //     //include
    //     int incAns=nums[i] + Solve(nums,n,i+2);
    //     //exclude
    //     int excAns=0 + Solve(nums,n,i+1);
    //     int finalAns=max(incAns,excAns);
    //     return finalAns;

    // }


    // int rob(vector<int>& nums) {
    //     int i=0;
    //     int ans = Solve(nums, nums.size(), i);
    //     return ans;
    // }
    // };

    class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];        
    }
};
    
    
