#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;
    int j = low;
    while(j<= high - 1){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
        j++;
    }
    swap(a[i + 1], a[high]);
    return (i+1);
}

void divide_and_sort_and_merge(vector<int> &v, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    int par = partition(v, i, j);
    divide_and_sort_and_merge(v, i, par - 1);
    divide_and_sort_and_merge(v, par + 1, j);
}

void quick_sort(vector<int> &v, int n)
{
    if (n == 0)
    {
        return;
    }
    int i = 0, j = n - 1;
    divide_and_sort_and_merge(v, i, j);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = random() % 100;
        cout << n << "\n";
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = random() % 10000;
            cout << v[i] << " ";
        }
        cout << '\n';
        quick_sort(v, n);
        for (auto i : v)
        {
            cout << i << " ";
        }
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                cout << "NOOOOOOOO\n";
            }
        }
        cout << "\n";
    }
    return 0;
}