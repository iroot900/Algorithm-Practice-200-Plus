class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        if(n<3) return 0;
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i])
            {
                for(int j=i+i;j<n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        return count_if(begin(prime)+2,end(prime),[](bool x){return x==true;});
    }
};
