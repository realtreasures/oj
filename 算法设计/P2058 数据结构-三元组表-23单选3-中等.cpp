

#include <iostream>
#include <vector>
#include <algorithm>  // 引入 sort
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;

    // 使用 pair 来存储三元组 (r, c, v)
    vector<pair<int, pair<int, int>>> q;
    q.reserve(n); // 预分配内存，避免动态扩容

    // 使用 scanf 来加速输入
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        q.push_back({a,{b,c}});  // (行, (列, 值))
    }

    // 按照值 (v) 升序排序，比较函数使用 pair 的第三个元素 (即值)
    sort(q.begin(), q.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.second.second < b.second.second;  // 按照值 v 排序
    });

    // 使用 printf 来加速输出
    for (const auto& element : q) {
        printf("%d %d %d\n", element.first, element.second.first, element.second.second);
    }

    return 0;
}



/*
#include<iostream>
#include<vector>
#include <algorithm>  // 引入 sort
#include<tuple>
using namespace std;

int main(){
    int n,a,b,c;
    cin>>n;
    vector<tuple<int,int,int>> q(n);
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        q[i]=make_tuple(a,b,c);
    }
    // 按照值 (v) 升序排序，比较函数使用 std::get<2> 提取三元组中的第三个元素 (即值)
    sort(q.begin(), q.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) < get<2>(b);  // 按照值 v 排序
    });
    
    // 输出排序后的每个三元组 (r, c, v)
    for (const auto& element : q) {
        cout << get<0>(element) << " " << get<1>(element) << " " << get<2>(element) << endl;
    }
    
    return 0;
}
*/