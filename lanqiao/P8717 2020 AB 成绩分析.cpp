#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;//表示人数
    int score;//记录分数
    int max=-1,min=101;
    double average=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>score;
        if(max<score)
        max=score;
        if(min>score)
        min=score;
        average+=score;
    }
    cout<<max<<endl<<min<<endl<<fixed<<setprecision(2)<<average/n<<endl;
    return 0;

}