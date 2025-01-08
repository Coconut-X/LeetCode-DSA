class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;       //to remove duplicate vaues
        unordered_map<int, bool> m1, m2;// for fast checking in sets
        vector<int> d1,d2;

        for(auto i : nums1)
            n1.insert(i);
        
        for(auto i : nums2)
            n2.insert(i);

        unordered_set<int>::iterator itr;
        
        for(itr=n1.begin();itr!=n1.end();itr++)
            m1[*itr]=true;

        for(itr=n2.begin();itr!=n2.end();itr++)
            m2[*itr]=true;
        
        for(itr=n1.begin();itr!=n1.end();itr++)
            if(!m2[*itr]) d1.push_back(*itr);

        for(itr=n2.begin();itr!=n2.end();itr++)
            if(!m1[*itr]) d2.push_back(*itr);

        return {d1,d2};

    }
};