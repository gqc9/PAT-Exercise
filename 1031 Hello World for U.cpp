/*
 * 图形输出
 *  */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("1.txt","r",stdin);
    string str;
    cin >> str;
    int len = str.size();
    int n1 = (len+2) / 3;
    int mid = len - n1 * 2;
    for (int i=0; i<n1-1; i++) {
        printf("%c", str.at(i));
        for (int j=0; j<mid; j++) {
            printf(" ");
        }
        printf("%c\n", str.at(len-1-i));
    }
    for (int i=n1-1; i<=len-n1; i++) {
        printf("%c",str.at(i));
    }
}