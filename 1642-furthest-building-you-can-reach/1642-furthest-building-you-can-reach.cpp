class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int>pq;
        int i=0;
        for(i;i<h.size()-1;i++){
            if(h[i+1]<=h[i])continue;
            int diff = h[i+1]-h[i];
            if(diff<=bricks){
                bricks=bricks-diff;
                pq.push(diff);
            }
            else if(ladders>0){
                if(pq.size()){
                    int x =pq.top();
                    if(x>diff){
                        bricks+=x;
                        pq.pop();
                        pq.push(diff);
                        bricks=bricks-diff;
                }
                }
                 ladders--;
                    
            }
            else
                break;
        }
        return i;
    }
};