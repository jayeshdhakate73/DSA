class Solution {
public:

    bool isPalindrome(string str, int s, int e){
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

    bool validPalindrome(string str) {
        int n=str.length();
        int i=0; 
        int j=n-1;

        while(i<=j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else{
                bool ansOne = isPalindrome(str,i+1,j);
                bool ansTwo = isPalindrome(str,i,j-1);
                bool finalAns = ansOne || ansTwo;
                return finalAns;
            }

        }
        return true;
    }
};