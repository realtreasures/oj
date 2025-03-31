#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
/*
int daysOfRunMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
*/
//判断闰年
bool Is_run(int year){
    if(year%4==0&&year%100!=0){
        return true;
    }
    else if(year%400==0){
        return true;
    }
    else{
        return false;
    }
}
//返回天数
int days(int year,int mo){
    if(Is_run(year)){
        switch (mo)
        {
        case 1:
            return 31;
        case 2:
            return 29;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        default:
            return 31;
        }
    }
    else{
        switch (mo)
        {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        default:
            return 31;
        }
    }
}

int main(){
    string x;
    cin>>x;
    char y1=x[0];
    char y2=x[1];
    char y3=x[3];
    char y4=x[4];
    char y5=x[6];
    char y6=x[7];
    int z1=(y1-'0')*10+(y2-'0');
    int z2=(y3-'0')*10+(y4-'0');
    int z3=(y5-'0')*10+(y6-'0');
    for(int year = 1960; year <= 2059; ++year) { // 1960年到2059年
        for(int month=1;month<=12;month++){
            for(int day=1;day<=days(year,month);day++){
                if((z1 == year % 100 && z2 == month && z3 == day) ||
                   (z1 == month && z2 == day && z3 == year % 100) ||
                   (z1 == day && z2 == month && z3 == year % 100))  // 判断是否符合条件
                    printf("%d-%02d-%02d\n", year, month, day); // 注意输出的格式
            }
        }               
    }
    return 0;

}