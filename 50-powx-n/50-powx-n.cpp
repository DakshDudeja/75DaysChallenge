class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        long long g=n;
        int flag=true;
        if(g<0){
            flag=false;
            g=-1*g;}
        if(g==0)
            return 1;
     double temp = myPow(x,g/2);
        if(g%2==0)
            ans= temp*temp;
        else
            ans= x*temp*temp;
        if(flag==false)
            ans = 1/ans;
            return ans;
    }
};