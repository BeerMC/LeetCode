template<typename T>
T cmax(const T &x, const T &y){
    if(x>y){
        return x;
    }
    return y;
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        reverse(properties.begin(), properties.end());
        int size = properties.size();
        int ans = 0;
        int m = -1;
        for(int i = 0; i < size; i++){
            int j = i;
            while(j + 1 < size && properties[i][0] == properties[j+1][0]){
                j++;
            }
            for(int k = i; k <= j; k++){
                if(properties[k][1] < m){
                    ans++;
                }
            }
            for(int k = i; k <= j; k++){
                m = cmax(properties[k][1], m);
            }
            i = j;
        }
        return ans;
    }
};