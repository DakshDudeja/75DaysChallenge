class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int s=0,e = A.size()-1;
        while(s<e){
            if(A[s]%2 != 0){
                swap(A[s],A[e]);
                --e;
            }
            else  ++s;  
            }
        return A;
    }
};