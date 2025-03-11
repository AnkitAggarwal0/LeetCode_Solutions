class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; 
        int right = s.size() - 1; 

        while (left <=right){
            if(!isalnum(s[left])){
                left++;
            }
            else if (!isalnum(s[right])){
                right--;
            }
            else {
                char lchar = tolower(s[left]); 
                char rchar = tolower(s[right]); 
                if (lchar != rchar) return false; 
                left++; right--;
            }
        }
        return true;
    }
};