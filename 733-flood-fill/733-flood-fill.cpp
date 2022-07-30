class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     if(image[sr][sc]==newColor) return image;
        int m=image.size();
        int n=image[0].size();
        int color = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=color) continue;
            
            image[i][j]=newColor;
            q.push({i+1,j});
            q.push({i,j+1});
            q.push({i-1,j});
            q.push({i,j-1});

        }
    return image;
    }
};