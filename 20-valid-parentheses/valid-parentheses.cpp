class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            char ch=s[i];

            //ch -> open/close bracket 
            //open -> sirf push krna hai stack mai
            //close -> check krna hai same type ka hai ya nhi 

            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                //muje close bracket mila hai 
                //stack ke top se ch ko check krenge ki same hai ya nhi 
                if(ch==')' && !st.empty() && st.top()=='('){
                    //bracket match
                    st.pop();

                }

                else if(ch==']' && !st.empty() && st.top()=='['){
                    //bracket match
                    st.pop();

                }
                else if(ch=='}' && !st.empty() && st.top()=='{'){
                    //bracket match
                    st.pop();

                }
                else{
                    //bracket not match
                    return false;
                }
            }


        }
        if(st.size()==0){
            return true;
        }
         else{
            return false;
         }
    }
};