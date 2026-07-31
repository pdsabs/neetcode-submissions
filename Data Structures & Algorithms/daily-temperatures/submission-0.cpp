class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);
        if (temperatures.size() == 1) return res;

        stack<pair<int,int>> needWarmer;

        for (int i = 0; i < temperatures.size(); i++) {
            int curr = temperatures[i];
            while (!needWarmer.empty() && curr > needWarmer.top().first) {
                auto& [temp, idx] = needWarmer.top();
                needWarmer.pop();

                res[idx] = i - idx;
            }
            needWarmer.push({curr, i});
        }
        return res;
    }
};
