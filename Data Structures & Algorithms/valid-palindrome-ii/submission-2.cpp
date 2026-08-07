class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j ; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {

        int n = s.size();
        int done = false;
        for(int i = 0, j = n - 1; i < j; ) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                return isPalindrome(s.substr(i+1,j - i)) || isPalindrome(s.substr(i,j - i));
            }
        }

        return true;
        
    }
};