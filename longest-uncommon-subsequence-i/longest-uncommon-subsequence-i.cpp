class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b)return -1;
        int n1 = a.length();
        int n2 = b.length();
        return max(n1, n2);
    }
};