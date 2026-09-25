class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;

        unordered_map<char, int> mp;
        priority_queue<int> pq;

        for (char ch : tasks) {
            mp[ch]++;
        }

        for (auto i : mp) {
            pq.push(i.second);
        }

        while (!pq.empty()) {
            vector<int> temp;
            int count = 0;

            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();

                    freq--;
                    temp.push_back(freq);
                    count++;
                }
            }

            for (int f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            if (pq.empty()) {
                time += count;
            } else {
                time += n + 1;
            }
        }

        return time;
    }
};