#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        cout << "n: " << n << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << fruits[i] << " ";
        }
        cout << "\n";
        int first_start = 0, second_start = 0, first_count = 0, second_count = 0;
        int start_index = 0;
        int first = -1, second = -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (fruits[i] != first && fruits[i] != second)
            {
                // cout << "New num: " << first_count << " " << second_count << '\n';
                // cout << first << " " << second << " " << fruits[i] << "\n\n";
                while (first_count != 0 && second_count != 0)
                {
                    first_count -= (first == fruits[start_index]);
                    second_count -= (second == fruits[start_index]);
                    start_index++;
                }
                if (first_count == 0)
                {
                    first = fruits[i];
                }
                else if (second_count == 0)
                {
                    second = fruits[i];
                }
            }
            if (fruits[i] == first)
            {
                first_count++;
            }
            if (fruits[i] == second)
            {
                second_count++;
            }
            // cout << first << " " << second << "\n";
            // cout << i << " " << start_index << "\n\n";
            ans = max(ans, i - start_index + 1);
        }
        cout << "Ans: " << ans << endl;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 20;
        vector<int> fruits(n);
        for (int i = 0; i < n; i++)
        {
            fruits[i] = random() % 5;
        }
        Solution s;
        s.totalFruit(fruits);
    }
}