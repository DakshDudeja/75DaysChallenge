class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),comp);
        
        int total_duration=0;
        priority_queue<int>pq;
        for(int i=0;i<c.size();i++){
            
            int curr_duration= c[i][0];
            int deadline= c[i][1];
            
            total_duration +=curr_duration;
            
           pq.push(curr_duration);
            
            if(total_duration > deadline){
                // we want to skip this course or
                //try to skip the course which is taken and has maximum duration;
                
                total_duration-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};