#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int minFreq[26];  // To store minimum frequency of each character

        // Initialize minFreq with large number
        for (int i = 0; i < 26; i++) {
            minFreq[i] = 1000;
        }

        // For each word in the list
        for (int w = 0; w < words.size(); w++) {
            int freq[26] = {0};  // Frequency of characters in current word

            // Count frequency of each character in current word
            for (int i = 0; i < words[w].size(); i++) {
                char ch = words[w][i];
                freq[ch - 'a']++;
            }

            // Update minFreq with minimum frequency
            for (int i = 0; i < 26; i++) {
                if (freq[i] < minFreq[i]) {
                    minFreq[i] = freq[i];
                }
            }
        }

        // Build result from minFreq
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minFreq[i]; j++) {
                string s = "";
                s += (char)(i + 'a');
                result.push_back(s);
            }
        }

        return result;
    }
};
