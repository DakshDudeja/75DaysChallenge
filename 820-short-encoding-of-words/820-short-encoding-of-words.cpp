class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>s1(words.begin(),words.end());
        set<string>s2(words.begin(),words.end());
        for(auto e:s1){
            for(int i=1;i<e.length();i++){
                // delete the substring present in s2
                s2.erase(e.substr(i));//if e is time then for loop will have - ime, me,e 
            }
        }
        int count=0;
        for(auto e:s2){
            count+=e.length();
            count++;//adding 1 for #
        }
        return count;
    }
};