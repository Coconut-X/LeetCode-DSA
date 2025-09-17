struct Food {
    string name;
    int rating;
};

struct Compare {
    bool operator()(const Food &a, const Food &b) const {
        if (a.rating == b.rating)
            return a.name > b.name;
        return a.rating < b.rating;
    }
};

class FoodRatings {
public:
    unordered_map<string, priority_queue<Food, vector<Food>, Compare>> cuisineHeap;

    unordered_map<string, string> foodCuisine;

    unordered_map<string, int> latestRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodCuisine[foods[i]] = cuisines[i];
            latestRating[foods[i]] = ratings[i];
            cuisineHeap[cuisines[i]].push({foods[i], ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        latestRating[food] = newRating;
        cuisineHeap[cuisine].push({food, newRating});
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisineHeap[cuisine];
        while (!pq.empty()) {
            Food top = pq.top();
            if (latestRating[top.name] != top.rating) {
                pq.pop();
            } else {
                return top.name;
            }
        }
        return ""; 
    }
};