class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& path) {

        int x=0, y=0;

        for(int i=0;i<path.size();i++)
        {   
            if(path[i]=="DOWN")         y++;
            else if(path[i]=="UP")      y--;
            else if(path[i]=="RIGHT")   x++;   
            else if(path[i]=="LEFT")    x--;

        }

        return y*n+x;

        
    }
};