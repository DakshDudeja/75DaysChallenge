class Solution {
public:
    void setZeroes(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int row = 0, col = 0;
        for(int i = 0; i < m; i++){
            if(ar[0][i] == 0){
                row = 1;
				break;
			}
        }
        for(int i = 0; i < n; i++){
            if(ar[i][0] == 0){
                col = 1;
				break;
			}
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(ar[i][j] == 0){
                    ar[i][0] = 0;
                    ar[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(ar[i][0] == 0)
                for(int j = 0; j < m; j++)
                    ar[i][j] = 0;
        }
        for(int i = 1; i < m; i++){
            if(ar[0][i] == 0)
                for(int j = 0; j < n; j++)
                    ar[j][i] = 0;
        }
        if(row == 1){
            for(int i = 0; i < m; i++)
                ar[0][i] = 0;
        }
        if(col == 1){
            for(int i = 0; i < n; i++)
                ar[i][0] = 0;
        }
    }
};
