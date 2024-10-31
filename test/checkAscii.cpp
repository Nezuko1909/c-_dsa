#include <bits/stdc++.h>
using namespace std;
int main(){
    ofstream file("ASCII.txt");
    for (int i=1;i<=127;i++){
        file<<i<<"\t"<<char(i)<<"\n";
    }
    return 0;
}