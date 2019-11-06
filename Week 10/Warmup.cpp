class Solution {
public:
    bool isValid(string &s) {
        vector<int> jar;
        for(auto it = s.cbegin(); it != s.cend(); ++it) {
            int thing = Solution::toInt(*it);
            if(thing < 0) {
                if(jar.size() == 0) {
                    return false;
                } else {
                    if(jar.back() == -thing) {
                        jar.pop_back();
                    } else {
                        return false;
                    }
                }
            } else if(thing > 0) {
                jar.push_back(thing);
            }
        }
        if(jar.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
    int toInt(char p) {
        int i = 0;
        string s(1, p); 
        if(s == "[" || s == "]") {
            i = 1;
        } else if (s == "{" || s == "}") {
            i = 2;
        } else if (s == "(" || s == ")"){
            i = 3;
        } else if(s == "<" || s == ">") {
            i = 4;
        } else {
            i = 0;
        }
        if(s == "}" || s == "]" || s == ")" || s == ">") {
            i = -i;
        }
        return i;
    }
};