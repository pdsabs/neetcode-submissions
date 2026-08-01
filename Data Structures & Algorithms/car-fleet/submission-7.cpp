class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty()) return 0;
        
        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend()); //desc

        stack<double> times;
        for (const auto& [pos, sp] : cars) {
            double time = (double)(target - pos) / sp;
            if (times.empty() || time > times.top()) {
                times.push(time);
            }
        }

        return times.size();
    }
};
