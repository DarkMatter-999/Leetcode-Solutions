class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char,int> sm;
        map<char,int> tm;
        for (int i=0; i<s.length(); i++) {
            sm[s[i]]++;
            tm[t[i]]++;
        }

        for(char c: s) {
            if(sm[c] != tm[c]) return false;
        }

        return true;
    }
};
