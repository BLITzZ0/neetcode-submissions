class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 0;
        vector<pair<int, double>>cars(position.size(), {0 , 0});

        for(int i = 0;i<position.size();i++){
            cars[i].first = position[i];
            cars[i].second = (double)(target - position[i])/speed[i];
        }

        sort(cars.rbegin(), cars.rend());
        double lastTime = 0;
        for(int i = 0;i<cars.size();i++){
            if(cars[i].second > lastTime){
                fleet++;
                lastTime = cars[i].second;
            }
        }

        return fleet;
    }
};
