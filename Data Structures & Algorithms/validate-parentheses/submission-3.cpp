class Solution {
public:
    bool isValid(string s) {
        stack<char> closedStack;
        unordered_map<char,char> closedMap = {{'(',')'}, {'{', '}'}, {'[', ']'}};
        for (char c : s) {
            if (closedMap.count(c)) {
                closedStack.push(closedMap[c]);
            } else {
                if (closedStack.empty() || c != closedStack.top()) {
                    return false;
                } else {
                    closedStack.pop();
                }
            }
        }

        if (closedStack.empty()) {
            return true;
        }
        return false;
    }
};
