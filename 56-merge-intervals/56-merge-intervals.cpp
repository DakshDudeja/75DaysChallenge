class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>res;
        int x=in[0][0],y=in[0][1];
        for(int i=1;i<in.size();i++){
            vector<int>temp;
            if(y>=in[i][0] and y<=in[i][1]){
                y=in[i][1];
            }
            
            else if(y<=in[i][0]){
                 temp.push_back(x);
                temp.push_back(y);
                res.push_back(temp);
                x=in[i][0];
                y=in[i][1];
            }
    
        }
        vector<int>temp;
        temp.push_back(x);
        temp.push_back(y);
        res.push_back(temp);
        return res;
    }
};