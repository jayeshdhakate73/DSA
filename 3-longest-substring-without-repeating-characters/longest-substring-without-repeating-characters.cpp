class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> frequence;
        int start = 0;
        int longest = 0;

        for(int end = 0; end < s.size(); end++) {
            char curChar = s[end];
            frequence[curChar]++;

            while(frequence[curChar] > 1) {
                char headChar = s[start];
                frequence[headChar]--;
                start++;
            }

            longest = max(longest, end - start + 1);
        }

        return longest;
    }
};