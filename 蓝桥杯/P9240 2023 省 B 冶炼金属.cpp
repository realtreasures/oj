#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;//记录条数
    cin>>n;
    vector<long long int> a(10005),b(10005);
    long long int max_val=0x3f3f3f3f,min_val=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        max_val=min(a[i]*1.0/(b[i]),max_val*1.0);
        min_val=max((a[i]*1.0/(b[i]+1)+1),min_val*1.0);
    }
    cout<<(int)min_val<<' '<<(int)max_val<<endl;
    return 0;
}




/*

#include<bits/stdc++.h>
using namespace std;
int n,a,b,maxn = 0x3f3f3f3f,minn;
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> b;
		minn = max(minn,int(floor(a*1.0/(b+1)))+1);
		maxn = min(maxn,int(floor(a*1.0/b)));
	}
	cout << minn << " " << maxn;
	return 0;
}
*/