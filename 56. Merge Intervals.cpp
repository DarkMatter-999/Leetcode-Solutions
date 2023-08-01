class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end()); // O(nlogn)

        vector<vector<int>> output{};

        if(inter.size() == 0)
            return output;

        int currlow = inter[0][0],currhigh = inter[0][1];
        for(int i=1; i<inter.size(); i++) {
            if(inter[i][0] <= currhigh) {
                currhigh = max(currhigh, inter[i][1]);
            } else {
                output.push_back(vector<int>{currlow, currhigh});
                currlow = inter[i][0];
                currhigh = inter[i][1];
            }
        }
        output.push_back(vector<int>{currlow, currhigh});

        return output;
    }
};
