class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> diffs;  // Store {absolute difference, element}
        
        for (int i = 0; i < arr.size(); i++) {
            diffs.push_back({abs(arr[i] - x), arr[i]}); 
            //We iterate through each element in arr and calculate the absolute difference between the element arr[i] and x. For each element, we push a pair {difference, element} into the diffs vector. For example, if arr = [1, 3, 5, 7] and x = 4: The differences would be {3, 1}, {1, 3}, {1, 5}, and {3, 7}
        }
        
        // Sort based on absolute difference, if same, sort by element value
        sort(diffs.begin(), diffs.end());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(diffs[i].second);
        }
        
        sort(result.begin(), result.end()); // Ensure result is sorted
        return result;
    }
};
