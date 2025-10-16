class Solution {
public:
    int fillCups(vector<int>& amount) {
        int time = 0;
        //sort(amount.begin(),amount.end());
        int a = amount[0], b = amount[1], c = amount [2];
        while(a or b or c){
            if(!a and !b and c) return time +c;
            if(!a and b and !c) return time +b;
            if(a and !b and !c) return time +a;

            if(a>=b and c>=b) amount[0]--, amount[2]--, time++;
            else if( b>=a and c>=a) amount[1]--, amount[2]--, time++;
            else if(a>=c and b>=c) amount[0]--, amount[1]--, time++;

            a = amount[0], b = amount[1], c = amount [2];
        }
        return time;
    }
   
};