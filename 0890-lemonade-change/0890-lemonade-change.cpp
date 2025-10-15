class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;

        for(int i = 0; i < bills.size(); i++){
            int b = bills[i];
            if(b == 5){
                fives++;    //no need to return any change, simply take it 5 dollar bill from customer
            }
            if(b == 10){
                if(fives == 0) return false; 
                fives--; //return one 5 dollar bill
                tens++; //take 10 dollar bill from customer
            }
            if(b == 20){
                if(fives == 0 and tens == 0) return false; //we need atleast one ten and one five for any type of change
                //prioritize giving bigger bills first 
                if(tens >= 1 and fives >= 1) fives--, tens--; //return one bill of 10 and one bill of 5 
                else if(fives >= 3) fives -= 3; //return 3 bills of 5
                else return false;
                twenties++; //take 20 dollar bill from customer
            }
        }
        return true;
    }
};