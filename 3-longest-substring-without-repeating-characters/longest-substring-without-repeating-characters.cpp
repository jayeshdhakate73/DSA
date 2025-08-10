class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            m[ch]++;
            count++;

            // If duplicate found → reset from this point
            if (m[ch] > 1) {
                // Move i back to the next position after the first occurrence
                int j = i - count + 1;
                while (j <= i) {
                    m[s[j]]--;
                    if (s[j] == ch) break;
                    j++;
                }
                count = i - j;
            }

            if (count > maxCount) {
                maxCount = count;
            }
        }

        return maxCount;
    }
};
