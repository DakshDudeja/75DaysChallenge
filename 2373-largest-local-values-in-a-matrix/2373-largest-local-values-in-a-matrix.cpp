class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>res;
        for(int i=0;i+2<grid.size();i++){
            vector<int>temp;
            for(int j=0;j+2<grid[0].size();j++){
                int maxi=0;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        maxi=max(maxi,grid[k][l]);
                    }
                }
                temp.push_back(maxi);
            }
            res.push_back(temp);
        }
        return res;
    }
};