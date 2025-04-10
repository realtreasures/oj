#include<bits/stdc++.h>
using namespace std;

// ���仯���飬�����洢�Ѿ��������������Ľ��
vector<int> dp;

// �ݹ麯�������м��仯
int f(vector<int>& arr, int i, int n) {
    // �ݹ����ֹ��������� i �Ѿ�����������ķ�Χ������ 0
    if (i >= n) {
        return 0;
    }

    // �������������Ѿ��������ֱ�ӷ��ؽ��
    if (dp[i] != -1) {
        return dp[i];
    }

    // ѡ��ǰԪ�� arr[i]����������һ��Ԫ��
    int take = arr[i] + f(arr, i + 2, n);

    // ��ѡ��ǰԪ�أ�ֱ��������һ��Ԫ��
    int skip = f(arr, i + 1, n);

    // ѡ�����ֵ��Ҫôѡ��ǰԪ�أ�Ҫô������ǰԪ��
    dp[i] = max(take, skip);
    return dp[i];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // ��������
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ��ʼ�����仯���飬-1��ʾ��δ����
    dp.assign(n, -1);

    // ������0��ʼ���õݹ麯��
    cout << f(arr, 0, n) << endl;
    return 0;
}

