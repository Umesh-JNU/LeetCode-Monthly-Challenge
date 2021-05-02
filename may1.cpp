#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// class WordFilter {
// public:
//     vector<string> input;
//     WordFilter(vector<string>& words) {
//         input = words;
//     }
    
//     int f(string prefix, string suffix) {
//         cout << prefix << " " << suffix << " " << input.size() << endl;
//         for(int i=input.size()-1; i>=0; i--){
//             cout << "word=" << input[i] << endl;
//             cout << "st=" << input[i].find(prefix, 0) << endl;
//             cout << "end=" << input[i].rfind(suffix) << endl;
//             if(input[i].find(prefix, 0)==0 && input[i].rfind(suffix)==input[i].size()-suffix.size()){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class WordFilter {
public:
    map<string, int> mp;
    WordFilter(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].length(); j++){
                for(int k=0; k<words[i].length(); k++){
                    string x = words[i].substr(0,j+1) + '#' + words[i].substr(words[i].length()-k-1,k+1);
                    mp[x]=i;
                }
            }
        }
        // for(auto x : mp){
        //     cout << x.first << " : " << x.second << endl;
        // }
    }
    // apple
    // a#e  a#le  a#ple  a#pple  a#apple
    // ap#e  ap#le  ap#ple  ap#pple  ap#apple
    // app#e  app#le  app#ple  app#pple  app#apple
    // appl#e  appl#le  appl#ple  appl#pple  appl#apple
    // apple#e  apple#le  apple#ple  apple#pple  apple#apple
    
    int f(string prefix, string suffix) {
        string res = prefix + '#' + suffix;

        return mp[res] >= 0 ? mp[res] : -1;
    }
};

int main() {
    
    vector<string> words = {"apple", "ape", "axp"};
    string prefix = "ap", suffix = "le";

    WordFilter* obj = new WordFilter(words);
    int param_1 = obj->f(prefix,suffix);
    cout << param_1 << endl;
    return 0;
}