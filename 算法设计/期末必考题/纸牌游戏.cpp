#include <iostream>
#include <queue>

using namespace std;
int f(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return q.front();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f(n) << endl;
        
    }
    return 0;
}