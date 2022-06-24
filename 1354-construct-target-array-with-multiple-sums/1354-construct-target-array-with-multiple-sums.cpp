class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long int n=target.size();
        long long sum=0;
        for(auto e:target){
            pq.push(e);
            sum+=e;
        }
        while(pq.top()!=1){
            int temp=pq.top();
            cout<<temp<<" ";
            sum-=temp;
            if(sum==0 || sum>=pq.top())return false;
            pq.pop();
            temp=temp%sum;
            if(temp==0 && sum!=1)return false;
            sum+=temp;
            pq.push(temp);
        }
        return true;
    }
};