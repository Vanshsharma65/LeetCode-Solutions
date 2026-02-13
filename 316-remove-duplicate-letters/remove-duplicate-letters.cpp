#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        vector<bool> visited(26, false);
        string result = ""; 

        for (char c : s) 
        {
            count[c - 'a']--;
            if (visited[c - 'a']) continue;
            while (!result.empty() && c < result.back() && count[result.back() - 'a'] > 0)
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += c;
            visited[c - 'a'] = true;
        }

        return result;
    }
};