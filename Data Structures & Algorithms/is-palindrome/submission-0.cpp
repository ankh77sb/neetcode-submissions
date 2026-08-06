class Solution {
public:
    bool isUpperCase(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    bool isNumber(char c) {
        return (c >= '0' && c <= '9');
    }

    bool isLower(char c) {
        return (c >= 'a' && c <= 'z');
    }

    char toLower(char c) {
        if(isUpperCase(c)) {
            return (c + 32);
        }

        return c;
    }

    bool isAlphanumeric(char c) {
        return isUpperCase(c) || isLower(c) || isNumber(c);
    }

    bool isPalindrome(string s) {

        int n = s.size();

        for(int i = 0, j = n - 1 ; i < j ;) {

            if(!isAlphanumeric(s[i])) {
                i++;
            }else if(!isAlphanumeric(s[j])) {
                j--;
            } else if(isAlphanumeric(s[i]) && isAlphanumeric(s[j])) {
                if(toLower(s[i]) != toLower(s[j])) return false;
                else {
                    i++;
                    j--;
                }
            }

        }

        return true;
        
    }
};
