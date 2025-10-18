class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        while(a or b or c){
            //if only one type of stone is left return score
            if(!a and !b and c) return score ;
            if(!a and b and !c) return score ;
            if(a and !b and !c) return score ;

            //if one water is zero it will never be chosen because other two will be non zero
            //pick the two greatest, remove them by one from their pile and increment score
            
            if(a>=b and c>=b) a--, c--, score++;
            else if( b>=a and c>=a) b--, c--, score++;
            else if(a>=c and b>=c) a--, b--, score++;
        }
        return score;
    }
};