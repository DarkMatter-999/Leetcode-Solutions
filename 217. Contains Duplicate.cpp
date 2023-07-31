class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mapp;
        for (int num : nums) {
            if(mapp[num] >= 1) {
                return true;
            } else {
                mapp[num]++;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mapp;
        for (int num : nums) {
            if(mapp[num] >= 1) {
                return true;
            } else {
                mapp[num]++;
            }
        }
        return false;
    }
};
