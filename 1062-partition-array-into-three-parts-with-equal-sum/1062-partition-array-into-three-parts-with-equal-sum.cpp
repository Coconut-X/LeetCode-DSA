class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        cout<<"Sum: "<<sum<<endl;
        int part = sum/3;
        
        if(sum%3!=0) return false;
        //if(part!=test) return false;
        cout<<"hi"<<endl;
        int low = 0, high = arr.size()-1;
        int sleft = 0, sright=0;
        if(part==0) sleft+=arr[low++], sright+=arr[high--];
        while(low<=high){
            
            if(sleft==part and sright==part) return true;
            if(sleft!=part){
                sleft+=arr[low++];

            }
            if(sright!=part){
                sright+=arr[high--];
            }
            cout<<sleft<<"  "<<sright<<endl;
        }
        return false;
    }
};