class Solution {
public:
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
int m=grid.size(), n=grid[0].size();
vector<vector<int>> res(m,(vector<int>(n,INT_MAX)));
    for(int i=0; i<n; i++){
         res[m-1][i]=grid[m-1][i];
    }
    for(int row =m-2; row>=0; row--){
        for(int col=0; col<n;col++){
            for(int nextcol=0; nextcol<n; nextcol++){
                res[row][col] = min(res[row][col], grid[row][col] + res[row+1][nextcol] +                                                      moveCost[grid[row][col]] [nextcol]);
            }
        }
    }
    int result =INT_MAX;
    for(auto el:res[0])
        result = min(result, el);
    return result;
    }
};