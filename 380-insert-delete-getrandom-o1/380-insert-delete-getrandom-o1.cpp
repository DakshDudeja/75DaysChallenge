class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    unordered_set<int>st;
    bool insert(int val) {
        if(st.count(val)) return false;
        else
            st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.count(val)){
            st.erase(val);
            return true;}
        else
            return false;
    }
    
    int getRandom() {
      return *next(st.begin(),rand()%st.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */