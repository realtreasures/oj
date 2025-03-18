#include <iostream> 
using namespace std;

int f(int *num, int start, int n)
{
    int max = num[start], min = num[start];
    int count = 0;
    for (int end = start; end < n; end++)
    {
        if (end == start)
        {
            count++;
            continue;
        }
        else if (num[end] == max + 1)
        {
            count++;
            max = num[end];
        }
        else if (num[end] == min - 1)
        {
            count++;
            min = num[end];
        }
        else
            continue;
    }
    return count;
}
int main()
{
    int n, a[50005];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans += f(a, i, n);
    }
    cout << ans << endl;
}