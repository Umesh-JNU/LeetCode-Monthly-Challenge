class Solution {
public:
    complex<int> parse(string num){
        int idx = num.find('+');
        int re = stoi(num.substr(0, idx));
        int img = stoi(num.substr(idx + 1, num.size() - idx - 2));

        return complex<int>(re, img);
    }
    string complexNumberMultiply(string num1, string num2){
        complex<int> n = parse(num1) * parse(num2);
        return to_string(real(n)) + '+' + to_string(imag(n)) + 'i';
    }
};