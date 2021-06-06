class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        vector<int> prime;
        vector<int> SPF(n+1);

        isPrime[0]=isPrime[1] = false;
        // check for all i < n
        // if i is prime then store it in 'prime' as well as it smallest prime factor which will be itself
        // ie SPF[i]=i
        for(int i=2; i<n; i++){
            if(isPrime[i]){
                prime.push_back(i);
                SPF[i]=i;
            }
            // for all prime j <= i &&
            //      i*prime[j] <= n &&   (multiple of i for prime[j] not > n)
            //        prime[j] <= SPF[i] ( <= SPF[i])
            for(int j=0; j<prime.size() && i*prime[j]<=n && prime[j]<=SPF[i]; j++){
                isPrime[i*prime[j]]=false;
                SPF[i*prime[j]]=prime[j];
            }
        }

        int count=0;
        for(int i=0; i<n; i++){
            if(isPrime[i]) count++;
        }
        
        return count;
    }
};