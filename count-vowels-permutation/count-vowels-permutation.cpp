class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    int countVowelPermutation(int n) {
        map<char, ll> mp = {{'a',1}, {'e',1},{'i',1},{'o',1},{'u',1}};
        if(n==1)
            return 5;

        for(; n>1; n--){
            ll a = mp['i'] + mp['e'] + mp['u'];
            ll e = mp['i'] + mp['a'];
            ll i = mp['e'] + mp['o'];
            ll o = mp['i'];
            ll u = mp['i'] + mp['o'];

            mp['a'] = a % MOD;
            mp['e'] = e % MOD;
            mp['i'] = i % MOD;
            mp['o'] = o % MOD;
            mp['u'] = u % MOD;
        }

        return (mp['a'] + mp['e'] + mp['i'] + mp['o'] + mp['u'])%MOD;
    }
};