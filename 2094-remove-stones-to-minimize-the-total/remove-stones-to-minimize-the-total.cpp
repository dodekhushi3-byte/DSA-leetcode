class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;

        for(int pile : piles){
            pq.push(pile);
            sum += pile;
        }

        while(k > 0){
            int temp = pq.top();
            pq.pop();
            int remove = temp / 2;
            sum -= remove;
            temp -= remove;
            pq.push(temp);
            k--;
        }
        return sum;
    }
};