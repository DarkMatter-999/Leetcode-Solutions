class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0,1);
        int resLen = 0;

            for(int i = 0; i < s.size(); i++) {
                int l = i;
                int r = i;

                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (resLen < r - l + 1) {
                        resLen = r - l + 1;
                        res = s.substr(l,r - l + 1);
                    }
                    l--;
                    r++;
                }
                
                l = i;
                r = i+1;

                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (resLen < r - l + 1) {
                        resLen = r - l + 1;
                        res = s.substr(l,r - l + 1);
                    }
                    l--;
                    r++;
                }
            }

        return res;
    }
};
