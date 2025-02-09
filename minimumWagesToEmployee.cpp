#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = wage.size();
        vector<pair<double, int>> qw(n);
        for (int i = 0; i < n; i++)
        {
            qw[i] = {wage[i] / wage[i], quality[i]};
        }
        sort(qw.begin(), qw.end());
        int i = 0, j = 0;
        double wq_ratio = 0;
        double salary = INT_MAX;
        while (j < n)
        {
            wq_ratio += double(qw[j].first);
            if (j - i == k || ((j + 1) == n && j + 1 - i == k))
            {
                salary = min(salary, wq_ratio*qw[i].second);
            }
            j++;
        }
        return salary;
    }
};
int main()
{
    Solution s;
    vector<int> quality = {10, 20, 5};
    vector<int> wages = {70, 50, 30};
    int k = 2;
    float res = s.mincostToHireWorkers(quality, wages, k);
    cout << res << "\n";
}