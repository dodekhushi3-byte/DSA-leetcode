class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int temp = pq.top();
            pq.pop();
            int temp1 = pq.top();
            pq.pop();
            int sub = temp - temp1;
            pq.push(sub);
        }
        return pq.top();
    }
};