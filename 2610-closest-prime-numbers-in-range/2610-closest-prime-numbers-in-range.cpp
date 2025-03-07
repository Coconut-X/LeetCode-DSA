// class Solution {
// public:
//     vector<int> closestPrimes(int left, int right) {

//         vector<bool> sieve(right-left +2,1);

//         auto mark=[](int num){
//             for(int x=2;x<=9;x++){
//                 if(num%x==0)
//                     return true;
//             }
//             return false;
//         };
//         //jahan 1 wahan prime

//         // sieve[2]=1;
//         // sieve[3]=1;
//         // sieve[5]=1;
//         // sieve[7]=1;



//         for(int i=left;i<=right;i++)
//         {
//             if(mark(i))sieve[i]=0; //not prime
//         }
        
//         int l=left;
//         while(l<=7){
//             if(l!=1 and l!=4 and l!=6)
//                 sieve[l]=1;
//             l++;
//         }

//         int a=-1,b=-1;
//         int m=INT_MAX;

//         for(int i=0;i<sieve.size() - 1;i++)
//         {
//             for(int j=i+1;j<sieve.size();j++)
//             {
//                 if(sieve[i]!=sieve[j] and sieve[i]+sieve[j]==2)
//                 {
//                     int t = j - i;
//                     if(t < m)
//                     {
//                         m=t;
//                         a=i, b=j;
//                     }
//                 }
//             }
//         }

//         return {a,b};
//     }
// };

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (long long p = 2; p * p <= right; p++) {
            if (isPrime[p]) {
                for (long long i = p * p; i <= right; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int minDiff = INT_MAX;
        int a = -1, b = -1;

        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                a = primes[i];
                b = primes[i + 1];
            }
        }

        return {a, b};
    }
};