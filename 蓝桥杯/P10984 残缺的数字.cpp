#include<iostream>

using namespace std;

int zero = 0b1111110;
int one = 0b0110000;
int two = 0b1101101;
int three = 0b1111001;
int four = 0b0110011;
int five = 0b1011011;
int six = 0b1011111;
int seven = 0b1110000;
int eight = 0b1111111;
int nine = 0b1111011;

bool f(int a,int b){
    int c = a^0b1111111;
    c = c|b;
    if(c==127){
        return true;
    }
    return false;
}

int compute(int a){
    int count = 0;
    if(f(a,zero)){
        count++;
    }
    if(f(a,one)){
        count++;
    }
    if(f(a,two)){
        count++;
    }
    if(f(a,three)){
        count++;
    }
    if(f(a,four)){
        count++;
    }
    if(f(a,five)){
        count++;
    }
    if(f(a,six)){
        count++;
    }
    if(f(a,seven)){
        count++;
    }
    if(f(a,eight)){
        count++;
    }
    if(f(a,nine)){
        count++;
    }
    return count;
}
int main(){

    int a1 = 0b0000011;
    int a2 = 0b1001011;
    int a3 = 0b0000001;
    int a4 = 0b0100001;
    int a5 = 0b0101011;
    int a6 = 0b0110110;
    int a7 = 0b1111111;
    int a8 = 0b0010110;
    int a9 = 0b0101001;
    int a10 = 0b0010110;
    int a11 = 0b1011100;
    int a12 = 0b0100110;
    int a13 = 0b1010000;
    int a14 = 0b0010011;
    int a15 = 0b00011111;
    int a16 = 0b0101101;
    int a17 = 0b0110101;
    int a18 = 0b1101010;

    int ans = 1;
    ans = ans*compute(a1);
    ans = ans*compute(a2);
    ans = ans*compute(a3);
    ans = ans*compute(a4);
    ans = ans*compute(a5);
    ans = ans*compute(a6);
    ans = ans*compute(a7);
    ans = ans*compute(a8);
    ans = ans*compute(a9);
    ans = ans*compute(a10);
    ans = ans*compute(a11);
    ans = ans*compute(a12);
    ans = ans*compute(a13);
    ans = ans*compute(a14);
    ans = ans*compute(a15);
    ans = ans*compute(a16);
    ans = ans*compute(a17);
    ans = ans*compute(a18);
    cout<<ans<<endl;
    return 0;
}
