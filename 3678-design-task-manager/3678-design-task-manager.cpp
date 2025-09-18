struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[2] != b[2]) {
            return a[2] < b[2];   
        }
        return a[1] < b[1];  
    }
};

class TaskManager {
public:
    unordered_map<int, pair<int,int>> cur;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            cur[taskId] = {userId, priority};
            pq.push(t);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        cur[taskId] = {userId, priority};
        pq.push({userId, taskId, priority});
    }
    
    void edit(int taskId, int newPriority) {
        auto it = cur.find(taskId);
        if (it != cur.end()) {
            int userId = it->second.first;
            cur[taskId] = {userId, newPriority};
            pq.push({userId, taskId, newPriority});
        }
    }
    
    void rmv(int taskId) {
        cur.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            int userId = top[0], taskId = top[1], priority = top[2];
            if (cur.count(taskId) && cur[taskId].first == userId && cur[taskId].second == priority) {
                pq.pop();
                cur.erase(taskId); // executed, so remove
                return userId;
            }
            pq.pop(); // discard stale
        }
        return -1;
    }
};
