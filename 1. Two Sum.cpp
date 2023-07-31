class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> mapp;
       vector<int> res;
       for (int i = 0; i < nums.size(); i++) {
           if (mapp.find(target - nums[i]) != mapp.end()) {
               res.push_back(mapp[target - nums[i]]);
               res.push_back(i);
               break;
            } else {
                mapp[nums[i]] = i;
            }
        }

       return res;
    }
};
