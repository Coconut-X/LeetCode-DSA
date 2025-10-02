#define ll long long
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        ll count = 0;
        ll f = numBottles, e = 0;

        while (1) {
            count += f;
            e += f;
            f = 0;
            if (e < numExchange) {
                return count;
            }

            ll b = 2*numExchange -1;
            ll c = -2*e;
            ll k = (-b+sqrt(b*b -4.0*c))/2;
            if (k <= 0) break;
            ll used = k*numExchange+k*(k-1)/2;
            f+=k;
            e-=used;
            numExchange+=k;
            // maximize k*exc+k*(k-1)/2<=e
            //k*exc+k*(k-1)/2-e <=0
        }
        return count;
    }
};
