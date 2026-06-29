class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;        
        for (const string& x : patterns) {
            if (word.find(x) != string::npos) {
                cnt++;
            }
        }
        return cnt;
    }
};