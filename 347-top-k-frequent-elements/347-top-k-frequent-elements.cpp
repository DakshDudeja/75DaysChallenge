class Solution {
    struct Node{
        int no;
        int freq;
        Node(int a,int b){    //constructor for value initialisation of each node
            no=a;
            freq=b;
        }
    };
         struct compare{                   //maintains max-heap based on freq.
            bool operator()(Node const&a,Node const&b)
            {  
            return a.freq<b.freq;
            }
        
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto el:nums){
            mp[el]++;
        }
     priority_queue<Node,vector<Node>,compare>heap; //compare defines a max heap based on freq
        
        for(auto it:mp){
            heap.push(Node(it.first,it.second));
        }
        vector<int>ans;
        while(k--){
            Node temp=heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};