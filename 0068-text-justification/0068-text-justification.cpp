#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) { 
        vector<string> cur; 
        vector<string> res; 
        int nol = 0; 

        for (string word : words) { 
           
            if (word.size() + cur.size() + nol > maxWidth) { 
                
                int totalSpaces = maxWidth - nol;
                
                if (cur.size() == 1) {
                    cur[0].append(totalSpaces, ' ');
                } else {
                    int baseSpaces = totalSpaces / (cur.size() - 1);
                    int extraSpaces = totalSpaces % (cur.size() - 1);
                    
                    for (int i = 0; i < cur.size() - 1; i++) {
                        cur[i].append(baseSpaces, ' ');
                        if (i < extraSpaces) {
                            cur[i] += ' '; 
                        }
                    }
                }

                string line = "";
                for (string s : cur) line += s;
                res.push_back(line); 

                cur.clear(); 
                nol = 0; 
            } 

            cur.push_back(word); 
            nol += word.size(); 
        } 

        string ll = ""; 
        for (int i = 0; i < cur.size(); i++) {
            ll += cur[i];
            if (i < cur.size() - 1) ll += " ";
        } 
        
        if (ll.size() < maxWidth) {
            ll.append(maxWidth - ll.size(), ' ');
        } 

        res.push_back(ll); 
        return res; 
    } 
};