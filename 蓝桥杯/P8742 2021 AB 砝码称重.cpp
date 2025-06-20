#include<iostream>
#include<cmath>

/*首先，代码的开头部分，用户使用了全局变量来声明dp数组，即`int dp[101][100001];`，然后在main函数里使用它。而用户可能注意到，如果将dp声明在main函数内部会导致问题，所以想知道为什么必须放在外面。

我记得在C++中，全局变量和局部变量的存储位置不同。全局变量存储在静态存储区，而局部变量存储在栈上。栈的大小是有限的，如果定义的数组太大，可能会导致栈溢出错误。

这里dp数组的大小是101行，100001列，每个int占4字节的话，总共有101*100001=10,100,101个int，也就是大约40,400,404字节，差不多38.5MB。这明显超过了大多数系统栈的大小限制，通常栈的大小在几MB左右。所以如果把这个数组放在main函数内部作为局部变量，会导致栈溢出，程序崩溃。

而全局变量存储在静态存储区，这部分的内存通常比栈大得多，所以可以容纳这么大的数组。这就是为什么用户必须将dp声明在main函数外的原因。*/
int dp[101][100001];
	
using namespace std;
int main(){
    int w[101]; 
    int n;//个数
    int ans=0;//结果
    int sum=0;//总和
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sum+=w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=sum;j>0;j--){
            if(w[i]==j)
                dp[i][j]=1;
            //前i-1个可以凑出重量j，则不选第i个
            else if(dp[i-1][j])
                dp[i][j]=1;

            //前i-1个凑出j-w[i],则选择第i个
            else if(dp[i-1][abs(j-w[i])])
                dp[i][j]=1;

            //前i-1个凑出j+w[i],则，选择第i个
            else if(dp[i-1][j+w[i]])
                dp[i][j]=1;
        }
    }
    for(int i=1;i<=sum;i++){
        if(dp[n][i])
        ans++;
    }
    cout<<ans<<endl;
}
    
