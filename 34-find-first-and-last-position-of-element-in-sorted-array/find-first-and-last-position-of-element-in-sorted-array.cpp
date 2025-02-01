class Solution {
public:
void findFirstOccurance(vector<int>arr,int n,int target, int &ansIndex){ // pass by reference actual value pass hogi 
    int s=0;
    int e=n-1;
    int mid= s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            //store and compute 
            ansIndex=mid;
            // first occurence ki baat ho rhi hai toh vo left mai he hopgi  
            // left mai jao 
             e=mid-1;
        }
        if(target>arr[mid]){
            s=mid+1;
        }
        else if(target<arr[mid]){
            e=mid-1;
        }
        //ye mai bhul jaata hu 
        mid= s + (e-s)/2;
    }

}

void findLastOccurance(vector<int>arr,int n,int target, int &ansIndex){ // pass by reference actual value pass hogi 
    int s=0;
    int e=n-1;
    int mid= s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            //store and compute 
            ansIndex=mid;
            // last occurence ki baat ho rhi hai toh vo right mai he hopgi  
            // right mai jao 
             s=mid+1;
        }
        if(target>arr[mid]){
            s=mid+1;
        }
        else if(target<arr[mid]){
            e=mid-1;
        }
        //ye mai bhul jaata hu 
        mid= s + (e-s)/2;
    }
}
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int firstOccIndex=-1;
        findFirstOccurance(arr,n,target,firstOccIndex);

        int lastOccIndex=-1;
        findLastOccurance(arr,n,target,lastOccIndex);

        vector<int> temp(2);
        temp[0]=firstOccIndex;
        temp[1]=lastOccIndex;
        return temp;
        
    }
};