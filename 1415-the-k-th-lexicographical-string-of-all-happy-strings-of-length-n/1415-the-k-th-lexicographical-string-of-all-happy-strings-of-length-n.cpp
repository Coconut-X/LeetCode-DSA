class Solution {
public:
    vector<string>a;
    void make(string s, int n){
        if(s.size() == n){
            a.push_back(s);
            return;
        }
        if(s == ""){
            s = "a";
            make(s,n);
            s = "b";
            make(s,n);
            s = "c";
            make(s,n);
        }
        else{
            if(s[s.size() - 1] == 'a'){
                string ns = s+"b";
                make(ns,n);
                ns = s+"c";
                make(ns,n);
            }
            if(s[s.size() - 1] == 'b'){
                string ns = s+"a";
                make(ns,n);
                ns = s+"c";
                make(ns,n);
            }
            if(s[s.size() - 1] == 'c'){
                string ns = s+"b";
                make(ns,n);
                ns = s+"a";
                make(ns,n);
            }
            
        }
    }

    string getHappyString(int n, int k) {
        string s = "";
        make(s,n);
        sort(a.begin(), a.end());
        cout <<k<<endl;
        if(k>a.size()) return "";
        return a[k - 1];
    }
};