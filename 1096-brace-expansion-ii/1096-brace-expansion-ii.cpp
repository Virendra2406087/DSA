class Solution {
public:
    // Parses one complete expression until '}' or end
    set<string> solve(string &s, int &i) {
        set<string> result;

        // Current concatenated results
        set<string> curr;
        curr.insert("");

        while(i < s.size() && s[i] != '}') {

            // Union
            if(s[i] == ',') {
                result.insert(curr.begin(), curr.end());

                curr.clear();
                curr.insert("");

                i++;
            }

            // Bracket expression
            else if(s[i] == '{') {
                i++;

                set<string> inside = solve(s, i);

                // Skip '}'
                i++;

                set<string> next;

                // Concatenate curr with inside
                for(string a : curr) {
                    for(string b : inside) {
                        next.insert(a + b);
                    }
                }

                curr = next;
            }

            // Normal character
            else {
                char ch = s[i];

                set<string> next;

                for(string x : curr) {
                    next.insert(x + ch);
                }

                curr = next;

                i++;
            }
        }

        // Add last term
        result.insert(curr.begin(), curr.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};