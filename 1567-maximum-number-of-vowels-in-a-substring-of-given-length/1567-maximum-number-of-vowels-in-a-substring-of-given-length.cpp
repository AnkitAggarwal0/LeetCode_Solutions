class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int currCount = 0, bestCount = 0;

        for (int i = 0; i <k; i++){
            if (isVowel(s[i])) currCount++;
        }
        
        bestCount = currCount;
        for (int i = k; i<s.size(); i++){
            if(isVowel(s[i])) currCount++; 
            if(isVowel(s[i-k])) currCount--; 
            bestCount = std::max(currCount, bestCount); 

            if (bestCount == k) return k;
        }

        return bestCount;
    }
};