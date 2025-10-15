class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        int count = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        for(int i = 0; i< players.size(); i++){
            auto it = lower_bound(trainers.begin(), trainers.end(), players[i]);
            if(it==trainers.end()) continue;
            count++;
            trainers[it - trainers.begin()] =  -1;
        }
        return count;
    }
};