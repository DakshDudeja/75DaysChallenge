class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        
        while(n-- >1){
            string temp;
            int cnt=1;
            for(int i=0;i<res.size();i++){
                
                if(res[i]==res[i+1]){
                    cnt=1;
                    while(res[i]==res[i+1]){
                        cnt++;
                        i++;
                    }
                }
                else{
                    cnt=1;
                }
                temp+=to_string(cnt)+res[i];
            }
            res=temp;
        }
        return res;
    }
};