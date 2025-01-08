class Solution {
public:
    unordered_map<int,int> tri;

    int tribonacci(int n) {
        if(n<=2) return n!=0;
        return (tri[n]? tri[n]: tri[n]=tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3) );
    }
};