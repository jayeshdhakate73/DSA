class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];

            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }

            else if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }

            else if(ch=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }

            else if(ch==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
        
    }
};