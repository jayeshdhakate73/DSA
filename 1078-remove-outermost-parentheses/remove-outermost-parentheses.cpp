class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth=0;
        for(auto x:s){
            if(x=='('){
                if(depth>0){
                    ans+='(';
                    
                }
                depth++;
            }
            else if(x==')'){
                depth--;
                if(depth>0){
                    ans+=')';
                }
            }
        }
        return ans;
    }
};