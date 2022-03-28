class RandomizedSet {
public:
    vector<int>t;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())return false;
        
        else{
        t.push_back(val);
        mp[val]=(t.size()-1);
        return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        
        int last=t.back();
        int s=mp[val];
        t[s]=t.back();
        t.pop_back();
        mp[last]=mp[val];
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return t[rand()%t.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */