class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int deficit=0;
        int balance=0;

        for(int i=0; i<gas.size(); i++){
            balance += gas[i] - cost[i];
            //+ve balance -> nothing to worry about 
            //-ve balance -> ye deficit ko darshata hai 
            if(balance<0){
                deficit += abs(balance);
                start = i+1;
                balance =0;

            }
        }
        if(balance - deficit >=0){
            return start;
        }
        return -1;
    }
};