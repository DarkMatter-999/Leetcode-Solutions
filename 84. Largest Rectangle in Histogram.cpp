class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<vector<int>> stack{};

        for(int i=0; i<heights.size(); i++) {
            int start = i;
            while(!stack.empty() && stack[stack.size()-1][1] > heights[i]) {
                vector<int> curr = stack.back();
                stack.pop_back();

                maxArea = max(maxArea, curr[1]*(i-curr[0]));
                start = curr[0];
            }
            stack.push_back({start, heights[i]});
        }

        for(int i=0; i<stack.size(); i++) {
            maxArea = max(maxArea, stack[i][1] * ((int)heights.size() - stack[i][0]));
        }

        return maxArea;
    }
};
