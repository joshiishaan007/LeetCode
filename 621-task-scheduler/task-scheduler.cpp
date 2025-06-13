class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<int,int> um;
        priority_queue<int> pq;
        int count = 0, prev = -1, total = 0;

        for(int i=0; i<tasks.size(); i++){
            um[tasks[i]-'A']++;
        }

        for(auto [a,b]: um){
            pq.push(b);
            total += b;
        }

        count = (n+1)*(pq.top()-1)+1;
        prev = pq.top();
        pq.pop();

        while(!pq.empty()){
            int m = pq.top();
            if(prev == m){
                count += 1;
            }
            pq.pop();
        }

        return count < total ? total : count;
    }
};