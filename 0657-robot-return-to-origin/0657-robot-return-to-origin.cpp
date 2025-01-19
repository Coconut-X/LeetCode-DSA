class Solution {
public:
    bool judgeCircle(string moves) {

        int x=0, y=0;

        auto direction=[&](const char c){
            if(c=='L')x--;
            else if(c=='R') x++;
            else if(c=='U') y++;
            else            y--;
        };

        for(auto c: moves)
            direction(c);
        
        return x==0 and y==0;
        
    }
};