class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        int s = arr.size();
        for(int i = 0; i < s - 1; i++) 
        {
            for(int j = 0; j < s - 1 - i; j++) 
            { 
                int c1 = 0, c2 = 0; 
                int num1 = arr[j];
                int num2 = arr[j+1];
              
                 while(num1 != 0) 
                 { 
                    int rem = num1 % 2;
                    num1 /= 2; 
                    if(rem == 1) c1++;
                }

                while(num2 != 0) 
                {
                    int rem = num2 % 2;
                    num2 /= 2; 
                    if(rem == 1) c2++;
                }

                if(c1 > c2 || (c1 == c2 && arr[j] > arr[j+1])) 
                    swap(arr[j], arr[j+1]);
            }
        }
        return arr;


    }
};