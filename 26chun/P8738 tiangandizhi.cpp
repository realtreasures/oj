#include<iostream>
#include<string>
using namespace std;

string tiangan[10]={"geng","xin","ren","gui","jia","yi","bing","ding","wu","ji"};
string dizhi[12]={"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
int main(){
    int start=2020;
    int year;
    cin>>year;
    int count=year-start;

    int tiangan_index=(count%10+10)%10;
    int dizhi_index=(count%12+12)%12;

    cout<<tiangan[tiangan_index]<<dizhi[dizhi_index]<<endl;
    return 0;
}