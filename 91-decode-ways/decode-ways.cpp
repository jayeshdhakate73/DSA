class Solution {
public:
    int numDecodings(string s) {
        const int n = s.length();
        int dp1 = 1, dp2 = 0;
        for(int i = n - 1; i >= 0; --i){
            int dp = 0;
            char ch = s[i];
            if(ch != '0'){
                dp += dp1;
                if(i + 1 < n && (ch == '1' || (ch == '2' && s[i + 1] <= '6'))) dp += dp2;
            }
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};