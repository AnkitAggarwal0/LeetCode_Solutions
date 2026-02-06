class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int right = s.size()-1; 
        int left = 0; 

        while(left<right){

            while(left<right && vowels.find(s[left]) == string::npos) left++;
            while(left<right && vowels.find(s[right]) == string::npos) right--;

            if (left<right) std::swap(s[left++], s[right--]);
        }

        return s;
    }
};