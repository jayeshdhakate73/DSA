class Solution {
public:
    bool cancocoeatbananawithkspeed(vector<int>& piles, int k, int h) {
        long long int totalhourstakenbycocotoeat = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhourstakenbycocotoeat += ceil(piles[i] / (double)k);
        }
        return totalhourstakenbycocotoeat <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int k = mid;

            if (cancocoeatbananawithkspeed(piles, k, h)) {
                ans = k;
                e = mid - 1; // Fix the incorrect assignment
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
