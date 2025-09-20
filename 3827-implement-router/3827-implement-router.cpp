class Router {
public:
    int limit;
    deque<array<int,3>> packets; // {source,destination,timestamp}
    unordered_map<long long,bool> present;
    unordered_map<int, vector<int>> destToTimes; // destination -> sorted timestamps
    long long nextId = 0;

    Router(int memoryLimit) {
        limit = memoryLimit;
        present.reserve(1024);
        present.max_load_factor(0.7f);
    }

    long long encode(int a,int b,int c) {
        return ((long long)a<<40) ^ ((long long)b<<20) ^ (long long)c;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source,destination,timestamp);
        if (present.count(key)) return false;

        if ((int)packets.size() == limit) {
            auto old = packets.front(); packets.pop_front();
            long long oldKey = encode(old[0],old[1],old[2]);
            present.erase(oldKey);
            auto &vec = destToTimes[old[1]];
            auto it = lower_bound(vec.begin(), vec.end(), old[2]);
            if (it != vec.end() && *it == old[2]) vec.erase(it);
        }

        packets.push_back({source,destination,timestamp});
        present[key] = true;

        auto &vec = destToTimes[destination];
        vec.insert(lower_bound(vec.begin(), vec.end(), timestamp), timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        auto p = packets.front(); packets.pop_front();
        long long key = encode(p[0],p[1],p[2]);
        present.erase(key);
        auto &vec = destToTimes[p[1]];
        auto it = lower_bound(vec.begin(), vec.end(), p[2]);
        if (it != vec.end() && *it == p[2]) vec.erase(it);
        return {p[0],p[1],p[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &vec = destToTimes[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return int(it2 - it1);
    }
};
