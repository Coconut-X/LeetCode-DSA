#define all(v) v.begin(),v.end()

class Solution {
public:

    int binarySearch(vector<int>& numbers, int low, int high, int target, int inum)
    {
        int mid = low+ (high-low)/2;
        while(low<high)
        {
            int sum = inum +numbers[mid];
            cout<<sum<<endl;
            if(sum == target){
                return mid;
            }
            if(sum> target){
                high--;
            }
            else
                low++;

            mid = low+ (high-low)/2;
        }
        
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0; int high=numbers.size();
        int mid = low+ (high-low)/2;
        while(low<high)
        {
            int sum = numbers[low]+numbers[high-1];
            if(sum == target){
                return {low+1,high};
            }
            if(sum> target){
                high--;
            }
            else
                low++;

            mid = low+ (high-low)/2;
        }

       
        
        return {};
    }
};
