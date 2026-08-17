class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>cars(position.size(),{0,0});
        stack<double>st;
        int fleet = 0;
        for(int i = 0;i<position.size();i++){
            double time = (double)(target - position[i])/speed[i];
            cars[i].first = position[i];
            cars[i].second = time;
        }
        sort(cars.rbegin(), cars.rend());

        double current = 0;
        for(int i = 0;i<cars.size();i++){
            current = cars[i].second;

            if(st.empty() || current > st.top()){
                fleet++;
                st.push(current);
            }
        }

        return fleet;
    }
};
