class Solution {
public:
    int minTimeToType(string word) {
        int ans = word[0] == 'a' ? 1 : min(word[0] - 'a', ('z' - word[0])+1) + 1;
        cout << ans << endl;
        for (int i = 1; i < word.size(); i++){
            // cout << abs(word[i-1]-word[i]) << " " << ('z'-word[i-1])+1+(word[i]-'a') << " " << ('z'-word[i])+1+(word[i-1]-'a') << endl;
            ans += min(abs(word[i - 1] - word[i]), min(('z'-word[i])+1+(word[i-1]-'a'), ('z' - word[i - 1]) + 1 + (word[i] - 'a'))) + 1;
        }
        return ans;
    }
};