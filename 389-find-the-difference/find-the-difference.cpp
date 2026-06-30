class Solution {
public:
    char findTheDifference(string s, string t) {
        char addedChar = 0;
        for (char c : s) {
            addedChar ^= c;
        }
        for (char c : t) {
            addedChar ^= c;
        }
        
        return addedChar;
    }
};