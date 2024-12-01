class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    int s=arr.size();
    for(int i=0; i<s;i++)
        for(int j=0;j<s;j++)
            if(arr[i]==2*arr[j] and i!=j)
                return true;

    return false;

    }
};