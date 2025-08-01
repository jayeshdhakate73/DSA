class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //process first window
        for(int i=0; i<k; i++){
            int ele=nums[i];
            //ye element queue ke aandar insert hoga he hoga
            //abhi tak jitne queue bani hue hai 
            //unme se check krlo kitne faltu elements hai
            //aur unko pop karwa do
            //faltu->curr elements se chhote elements
            // int dqIndex = dq.front();
            while(!dq.empty() && nums[dq.back()] < ele){
                dq.pop_back();
            }
            //current element insert krna he hai
            dq.push_back(i);
        }
        //get answer for first window
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);

        //process remaining windows 
        for(int i=k; i<nums.size(); i++){
            //removal
            if(!dq.empty() && dq.front() < i-k+1){
                dq.pop_front();
            }
            //addition
            int ele=nums[i];
            
            while(!dq.empty() && nums[dq.back()] < ele){
                dq.pop_back();
            }
            //current element insert krna he hai
            dq.push_back(i);

            //answer
            int index = dq.front();
            int ansElement = nums[index];
            ans.push_back(ansElement);
        }
        return ans;
    }
};