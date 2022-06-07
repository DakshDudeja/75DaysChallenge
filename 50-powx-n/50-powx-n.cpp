class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long t=n;
        if(t<0) t=abs(t);
        while(t){
            if(t%2==0){
                x=x*x;
                t=t/2;
            }
            else{
                ans=ans*x;
                cout<<ans<<endl;
                t=t-1;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};