class MyHashSet {
public:
    //unordered_set<int> set;
    vector<bool> set;
    MyHashSet() {
        set.resize(1000001,0);
    }
    
    void add(int key) {
        set[key]=true;
    }
    
    void remove(int key) {
       set[key]=false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */