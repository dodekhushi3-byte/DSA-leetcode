class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        if(n == 0){
            return {};
        }
        set<int> s(arr.begin() ,arr.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(int num : s){
             mp[num] = rank++;
        }

        for(int element : arr){
            result.push_back(mp[element]);
        }
        return result;
    }
};