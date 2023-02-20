class Solution {
public:

    bool isVowel(char c){
        char toLower = tolower(c);
        return toLower == 'a' || toLower == 'e' || toLower == 'i' || toLower == 'o' || toLower == 'u';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if(isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left], s[right]);
                left++, right--;
                continue;
            }
            if(!isVowel(s[left])) left++;
            if(!isVowel(s[right])) right--;
        }
        return s;
    }
};