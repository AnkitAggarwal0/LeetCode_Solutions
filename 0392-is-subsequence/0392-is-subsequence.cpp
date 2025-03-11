class Solution {
public:
    bool isSubsequence(string s, string t) {
        int outer_idx = 0; int found = 0; 
        while(found<s.length() && outer_idx<t.length()){
            if(s[found] == t[outer_idx]){
                found++;
            }
            outer_idx++;
        }
        return found == s.size() ? true:false;
    }
};