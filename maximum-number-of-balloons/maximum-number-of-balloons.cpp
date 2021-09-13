class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> freq;
        for (int i = 0; i < text.size(); i++){
            switch (text[i])
            {
            case 'b':
                freq['b']++;
                break;
            case 'a':
                freq['a']++;
                break;
            case 'l':
                freq['l']++;
                break;
            case 'o':
                freq['o']++;
                break;
            case 'n':
                freq['n']++;
                break;
            default:
                continue;
            }
        }

        string t = "balon";
        int ans = INT_MAX;
        for(auto e: t){
            if(e == 'l' || e == 'o')
                ans = min(ans, freq[e] / 2);
            else
                ans = min(ans, freq[e]);
        }
        return ans;
    }
};