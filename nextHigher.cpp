/*
    Position of the next higher or
    next lower element
    */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextHigher(vector<int> arr, int n)
{
    vector<int> next_higher(n, -1);
    stack<int> s;
    vector<int> ind(n, 0);
    for (int i = 0; i < n; i++)
    {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](int &a, int &b)
         { return arr[a] == arr[b] ? a < b : arr[a] < arr[b]; });
    for (int i : ind)
    {
        while (!s.empty() && s.top() < i)
        {
            next_higher[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<next_higher[i]<<" "<<arr[next_higher[i]]<<"\n";
    }
    cout<<"\n\n";
}

void nextLower(vector<int> arr, int n)
{
    vector<int> ind(n, 0), next_lower(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](int &a, int &b)
         { return arr[a] == arr[b] ? a < b : arr[a] > arr[b]; });
    for (int i : ind)
    {
        while (!s.empty() && s.top() < i)
        {
            next_lower[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<next_lower[i]<<" "<<arr[next_lower[i]]<<"\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 10;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = (random()) % 10;
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        nextHigher(arr, n);
        nextLower(arr, n);
    }
}