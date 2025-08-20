class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int t=0; t<timePoints.size(); t++){
            int h=stoi(timePoints[t].substr(0,2));
            int m=stoi(timePoints[t].substr(3,2));
            minutes.push_back(h*60+m);
        }
        sort(minutes.begin(),minutes.end());

        int ans=INT_MAX;
        int n=minutes.size();

        for(int i=1; i<n; i++){
            ans = min(ans, minutes[i]-minutes[i-1]);
        }

        ans = min(ans, 1440 - (minutes[n-1] - minutes[0]));

        return ans;
    }
};