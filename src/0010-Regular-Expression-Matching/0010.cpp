#include <string>
#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.length(), n = p.length(); 
        vector<vector<bool>> mem(m + 1, vector<bool> (n + 1, false));
        mem[0][0] = true;
    	for (int j = 1; j <= n; j++) mem[0][j] = p[j-1] == '*' && j > 1 && mem[0][j-2];
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                    mem[i][j] = (j > 1 && mem[i][j - 2]) || 
                    (i > 0 && (s[i - 1] == p[j - 2] || 
                    (j > 1 && p[j - 2] == '.')) && mem[i - 1][j]);
                else mem[i][j] = i > 0 && 
                    mem[i - 1][j - 1] && 
                    (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return mem[m][n];
    }
};
int main()
{
    string s = "baccbbcbcacacbbc";
    string p = "c*.*b*c*ba*b*b*.a*";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}