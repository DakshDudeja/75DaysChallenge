class Solution {
public:
    struct Node{
        string s;
        int freq;
        Node(string s1,int frq){
            s=s1;
            freq=frq;
        }
    };
    struct comp{
        bool operator()(Node&a,Node&b){
            if(a.freq==b.freq) return a.s > b.s;
            return a.freq<b.freq;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<Node,vector<Node>,comp>pq;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto e:mp)pq.push(Node(e.first,e.second));
        vector<string>res;
        while(k--){
            Node temp=pq.top();
            pq.pop();
            res.push_back(temp.s);
        }
        return res;
    }
};