class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, pair<int, int>>> temp;
        for(int i = 0; i < n; i++){
            temp.push_back({matrix[i][0], {i, 0}});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

        int data;
        int i;
        int j;
        pair<int, pair<int, int>> ans;
        while(k--){
            ans = p.top();
            p.pop();
            data = ans.first;
            i = ans.second.first;
            j = ans.second.second;
            if(j+1 < m){
                p.push({matrix[i][j+1], {i, j+1}});
            }
        }
        return data;
    }
};