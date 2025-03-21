class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string res= "";
        sort(str.begin(),str.end());

        string first= str[0];
        string last= str[str.size()-1];

        for(int i=0;i<first.size();i++) {
            if(first[i] != last[i])
                return res;

            res += first[i];
        }

        return res;
    }
};