// O(n^2)
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                int j = i, k = 0;
                while(haystack[j] == needle[k] && k<needle.size()) {
                    j++;
                    k++;
                    if (k == needle.size()) {
                        return i;
                    }
                }
            }
        }

        return -1;
    }
};


// O(n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        int ind = 0;
        
        for(int i=0; i<h; i++) {
            if(haystack[i] == needle[ind]) {
                ind++;
            } else {
                i = i-ind;
                ind=0;
            }
            if(ind == n) {
                return i-n+1;
            }
        }

        return -1;
    }
};
