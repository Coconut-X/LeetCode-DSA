class Solution {
public:
    int minimumSum(int num) {
        string n = to_string(num);
        sort(n.begin(), n.end());
        string left = "", right = "";

        for(int i = 0; i < n.size(); i++){
            if(i%2==0) left+=n[i];
            else right+=n[i];
        }
        cout<<left<<" "<<right;
        return stoi(right) + stoi(left);
    }
};