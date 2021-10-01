class DetectSquares {
public:
    unordered_map<int, vector<int>> x;
    unordered_map<int, vector<int>> y;
    map<vector<int>, int> amount;

    DetectSquares() {}
    
    void add(vector<int> point) {
        if((amount[point] += 1) == 1){
            x[point[0]] = (point);
            y[point[1]] = (point);
        }
    }
    
    int count(vector<int> point) {
        if(x.find(point[0]) == x.end() || y.find(point[1]) == y.end()){
            return 0;
        }
        int ans = 0;
        for(auto entry : amount){
            if(entry.first.at(0) == point[0] || entry.first.at(1) == point[1]){
                continue;
            }
            if(abs(entry.first.at(0) - point[0]) != abs(entry.first.at(1) - point[1])){
                continue;
            }
            vector<int> tmp1 = {point[0], entry.first.at(1)};
            vector<int> tmp2 = {entry.first.at(0), point[1]};
            ans += amount[tmp1] * amount[tmp2] * entry.second;
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */