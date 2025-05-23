#include <iostream>
#include <cmath>
using namespace std;
    //把每个要删除的数字的位置记录下来
    //并且计算出他们到自己前面的2的次方的距离
    //找到距离非0的位置，看前面有几个距离为0，若数量大于自己的距离，直接删除，若小于，则要取最大
#define N 300004
int d[N];
int pos(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (pow(2, i) == n)
            return 0;
        else if (pow(2, i) > n)
            return n - pow(2, i - 1) + 1;
    }
}

int main()
{
    
    int n, k, j = 0, ans = 0, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == k)
            d[j++] = pos(i + 1);
    }
    for (int i = 0; i < j; i++) //从左到右扫描指定值
    {
        if (!d[i] || d[i] < ans)
            ans++;
        else
            ans = max(ans, d[i]);
    }
    cout << ans << endl;
}
