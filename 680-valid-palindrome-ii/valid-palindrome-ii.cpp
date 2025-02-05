class Solution {
public:

    bool checkPalindrome(string str, int s, int e){
        while(s<=e){
            if(str[s]==str[e]){
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }


    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i<=j){
            //same
            if(s[i]==s[j]){
                i++;
                j--;
            }
            //different
            else{
                //s[i]!=s[j]
                //iss case mai delete krke deakho
                //2 option
                //i ya phir j 
                bool ansOne = checkPalindrome(s,i+1,j);
                // agar i ko delete kiya toh next string i+1 se j hogi 

                bool ansTwo = checkPalindrome(s, i,j-1);
                bool finalAns= ansOne || ansTwo;
                return finalAns;

            }
        }
        // valid palindrome without deletion
        return true;
        
    }
};