class Solution {
public:
    int convertTime(string current, string correct) {
        string currenthours = "";
        currenthours += current[0];
        currenthours += current[1];
        int curhours = stoi(currenthours);

        string currentmins = "" ;
        currentmins += current[3];
        currentmins += current[4];
        int curmins = stoi(currentmins);

        int totalcurmins = curhours*60+curmins; //current time in mins

        string correcthours = "";
        correcthours += correct[0];
        correcthours += correct[1];
        int  corhours = stoi(correcthours);

        string correctmins = "";
        correctmins += correct[3];
        correctmins += correct[4];
        int  cormins = stoi(correctmins);

        int totalcormins = corhours*60+cormins;

        totalcurmins = totalcormins - totalcurmins;

        int op = 0;
        while(totalcurmins-60>=0){
            totalcurmins-=60;
            cout<<totalcurmins<<" ";
            op++;
        }

        while(totalcurmins-15>=0){
            totalcurmins-=15;
            cout<<totalcurmins<<" ";

            op++;
        }

        while(totalcurmins-5>=0){
            totalcurmins-=5;
            cout<<totalcurmins<<" ";

            op++;
        }
        return op + totalcurmins;

    }
};