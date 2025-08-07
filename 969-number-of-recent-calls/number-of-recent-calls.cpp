class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        //1. push current in queue
        q.push(t);

        //2. pop invalid request , older req, not in range [t-3000,t]
        while(!q.empty() && q.front()<t-3000){
            q.pop();
        }

        //3. return size 
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */