class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int time = 0;
        for(int i = 0; i < colors.size()-1;){
            int j = i+1;
            int tmax = neededTime[i];
            while(j < colors.size() and colors[i]==colors[j]){
                if(neededTime[j] < tmax){
                    time+=neededTime[j];
                }
                else{
                    tmax = neededTime[j];
                    time+=neededTime[i];
                    break;
                }
                j++;
            }
            i = j;
        }
        return time;

    }
};