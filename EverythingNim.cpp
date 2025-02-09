
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define ll long long
#define PII std::pair<long long, long long>

long long rec_gcd(long long a, long long b)
{
    return b ? rec_gcd(b, a % b) : a;
}
long long non_rec_gcd(long long a, long long b)
{
    while (b)
    {
        a = a % b;
        a = (a + b);
        b = a - b;
        a = a - b;
    }
    return a;
}

long long check_gcd(long long n, long long arr[])
{
    long long gcd[n - 1];
    for (long long i = 0; i < n - 1; i++)
    {
        gcd[i] = rec_gcd(arr[i], arr[i + 1]);
    }
    for (long long i = 0; i < n - 2; i++)
    {
        if (gcd[i] > gcd[i + 1])
        {
            return i;
        }
    }
    return -1;
}

class Compare
{
public:
    bool operator()(PII below, PII above)
    {
        if (below.first > above.first)
        {
            return true;
        }
        else if (below.first == above.first && below.second > above.second)
        {
            return true;
        }

        return false;
    }
};

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int ones = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    int removed = 0;
    int turn = 0;
    while (!pq.empty())
    {
        int x = pq.top();
        if(x - removed >= 2){
            if(turn){
                cout<<"Bob\n";
            }else{
                cout<<"Alice\n";
            }
            return;
        }else{
            turn = 1 - turn;
            removed = x;
        }
        while(!pq.empty() && pq.top() == x)pq.pop();

    }
    if(!turn){
        cout<<"Bob\n";
    }else{
        cout<<"Alice\n";
    }
}

int main()
{

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}