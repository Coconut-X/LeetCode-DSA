class Solution {
public:
    bool divisorGame(int n) {
        if(n==2) return true;
        if(n==1) return false;

        return divisorGame(n-2);
    }
};