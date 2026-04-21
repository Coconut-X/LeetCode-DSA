class NumArray {
public:

    vector<int> tree;
    vector<int> nums;
    int n;
    int left(int node){
        return 2*node + 1;
    }
    int right(int node){
        return 2*node + 2;
    }
    void build(vector<int>&nums, vector<int>&tree, int node, int l, int r){
        if(l == r){
            tree[node] = nums[l];
            return;
        }
        int m = (l + r)/2;

        build(nums, tree, left(node), l, m);
        build(nums, tree, right(node), m+1, r);
        tree[node] = tree[left(node)] + tree[right(node)];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        tree.resize(4*nums.size());
        build(nums, tree, 0, 0, nums.size() - 1);
    }
    void upd(vector<int>&nums,int idx, int node,  int val, int start, int end){
        if(start == end){
            nums[idx] = val;
            tree[node] = val;
            return;
        }

        int m = (start+end)/2;

        if(idx <= m)
            upd(nums, idx, left(node), val, start, m);
        else
            upd(nums, idx, right(node), val, m + 1, end);
        tree[node] = tree[left(node)] + tree[right(node)];
    }
    void update(int index, int val) {
        
        upd(nums, index,0,val,0, n - 1);
    }
    
    int query(vector<int>& tree, int node, int start, int end, int l, int r){
        if(r < start or end < l) return 0;
        if(l <= start and end <= r) return tree[node];

        int m = (start + end) / 2;
        return query(tree, left(node), start, m, l, r) + query(tree, right(node), m+1, end, l, r);
    }


    int sumRange(int left, int right) {
        return query(tree, 0,0, n - 1,left,right);
    }


};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */