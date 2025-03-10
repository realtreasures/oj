#include<iostream>
#include<unordered_map>
#include<vector>
 
using namespace std;

int find_num(vector<int> A,vector<int> B,vector<int> C,vector<int> D){
	unordered_map<int,int> sum_ab;
	int count=0;
	for(int a:A){
		for(int b:B){
			sum_ab[a+b]++;
		}
	}
	for(int c:C){
		for(int d:D){
			int sum_cd=-(c+d);
			if(sum_ab.find(sum_cd)!=sum_ab.end()){
		    	count+=sum_ab[sum_cd];
			}
		}
	}
	return count;
}

int main(){
	int t;//t组 
	int n;//n个列表
	cin>>t;


	for(int i=0;i<t;i++){
		vector<int>A,B,C,D;
		int x1,x2,x3,x4;//四元组 
		cin>>n; 
		for(int j=0;j<n;j++){
			cin>>x1>>x2>>x3>>x4;
			A.push_back(x1);
			B.push_back(x2);
			C.push_back(x3);
			D.push_back(x4);
		}
		cout<<find_num(A,B,C,D)<<endl;
	} 
	return 0;
} 
/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 计算符合条件的四元组数量
int count_quadruples(const vector<int>& A, const vector<int>& B, const vector<int>& C, const vector<int>& D) {
    // 使用 unordered_map 来存储 a + b 的和及其出现次数
    unordered_map<int, int> sum_ab;

    // 计算所有 a + b 的和，并记录出现次数
    for (int a : A) {
        for (int b : B) {
            sum_ab[a + b]++;
        }
    }

    // 统计符合条件的四元组
    int count = 0;
    for (int c : C) {
        for (int d : D) {
            int target = -(c + d);
            if (sum_ab.find(target) != sum_ab.end()) {
                count += sum_ab[target];
            }
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T; // 输入测试用例数

    while (T--) {
        int n;
        cin >> n; // 输入每个列表的大小 n

        vector<int> A, B, C, D;
        
        // 输入四个列表 A, B, C, D
        for (int i = 0; i < n; ++i) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            A.push_back(a);
            B.push_back(b);
            C.push_back(c);
            D.push_back(d);
        }

        // 计算并输出当前测试用例的结果
        cout << count_quadruples(A, B, C, D) << endl;
    }

    return 0;
}
*/