class Solution {
public:
    int trap(vector<int>& height) {
        // O(n) O(n)
        vector<int> maxLeft{};
        vector<int> maxRight{};

        int max = 0;
        for(int i=0; i<height.size(); i++) {
            maxLeft.push_back(max);
            if(height[i] > max)
                max = height[i];
        }

        max = 0;
        for(int i=height.size() - 1; i>=0; i--) {
            maxRight.push_back(max);
            if(height[i] > max)
                max = height[i];
        }

        int water = 0;
        for(int i=0; i<height.size(); i++) {
            if(height[i] < min(maxLeft[i], maxRight[height.size() - i - 1]))
                water += min(maxLeft[i], maxRight[height.size() - i - 1]) - height[i];
        }

        return water;
    }
};

// Constant mem
class Solution {
public:
    // O(n) O(1)
    int trap(vector<int>& height) {
        int l = 0, r = height.size();
        int lmax = height[0], rmax = height[height.size() - 1];
        int water = 0;

        while(l < r) {
            if(lmax < rmax) {
                l++;
                lmax = max(height[l], lmax);
                water += lmax - height[l];
            } else {
                r--;
                rmax = max(height[r], rmax);
                water += rmax - height[r];
            }
        }

        return water;
    }
};
