class Solution {
public:
    string removeDuplicates(string s) {
        //initialize answer string as empty string 
        string ans="";
        int n =s.length();

        for(int i=0; i<n; i++){
            char currentChar = s[i];
            if(ans.empty()){
                //agar string empty seedha push kro 
                ans.push_back(currentChar);
            }
            //rightmost char of ans = ans.back()
            else if(currentChar == ans.back()){
                ans.pop_back();
            }
            else if(currentChar != ans.back()) {
                ans.push_back(currentChar);
            }
        }
        return ans;


    }
};