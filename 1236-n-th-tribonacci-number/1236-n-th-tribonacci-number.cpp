class Solution {
public:

    unordered_map<int,int> tri;

    int tribonacci(int n) {
        
        if(n==0) return 0;
        if(n==1 or n==2) return 1;

        if(tri[n]) return tri[n];

        int a= tribonacci(n-1);
        int b= tribonacci(n-2);
        int c= tribonacci(n-3);
        tri[n]=a+b+c;
        return tri[n];

    }
};