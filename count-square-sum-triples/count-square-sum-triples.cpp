class Solution {
public:
    int SquareRoot(int num)
    {
        int l = 1, r = num;
        long long mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid * mid <= num && (mid + 1) * (mid + 1) > num)
                break;
            else if (mid * mid > num)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return mid;
    }
    int countTriples(int n)
    {
        int count = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                if(a == b)
                    continue;
                int c = SquareRoot(a * a + b * b);
                if(c*c != a*a+b*b)
                    continue;
                if(c > n)
                    continue;

                count++;
            }
        }
        return count;
    }
};