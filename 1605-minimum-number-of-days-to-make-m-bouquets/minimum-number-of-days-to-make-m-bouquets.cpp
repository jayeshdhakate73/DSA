class Solution {
public:
    bool CanWeMakeBouquetWithDDays(vector<int>& bloomDay, int m, int k, int day) {
        int counter = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                counter++;
            } 
            if (counter == k) {
                m--;
                counter = 0; 
                if (m == 0) {
                    return true;
                }
            }
            if (bloomDay[i] > day) {
                counter = 0;
            }
        }
        return m == 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int r= (double)m*(double)k;
        if (bloomDay.size() < r)
            return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;  // Initialize with -1 to handle cases where no valid day is found.

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (CanWeMakeBouquetWithDDays(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return ans;
    }
};
