class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {

        int n=courses.size();
        sort(courses.begin(), courses.end(), cmp);  //sort the given array on the basis of lastDay i.e. courses[i][1];

        priority_queue<int> pq;  //build a max heap
        int sum=0;

        for(int i=0;i<n;i++){
            pq.push(courses[i][0]);  //push duration of course in max heap and add it to the sum

            sum+=courses[i][0];

            if(sum>courses[i][1]){  //if at any instance, sum becomes greater than last day for a particula course, then pop and subtract it's duration from the sum
                sum=sum-pq.top();
                pq.pop();
            }
        }
        return pq.size();  //return pq.size
    }
};