class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum%3!=0) return false;
        int part = sum/3; //sum of one part
        int low = 0, high = arr.size()-1;
        int sleft = 0, sright=0;
        //for arrays like [0,0,0,] [-1,1,1,-1] the part will be zero 
        //ans initially both sleft and sright were zero so it will return true on very first 
        //if statement in while loop, so we add first numbers to them move both indices
        if(part==0) sleft+=arr[low++], sright+=arr[high--];

        while(low<=high){
            
            if(sleft==part and sright==part) return true;
            if(sleft!=part){
                sleft+=arr[low++];

            }
            if(sright!=part){
                sright+=arr[high--];
            }
        }
        return false;
    }
};