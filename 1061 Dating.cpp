/*
"the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D"
这句话的意思是：在两个字符串的*同一位置*上 相同的大写字母
DAY: ABCDEFG
HOUR: 0-9, A-N
 */
#define  CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#include <ctype.h>
#include <algorithm>
using namespace std;

char day, h;
int m;

void find1(string s1, string s2) {
    int i=0;
    int len = min(s1.size(), s2.size());
    // day
    for (; i<len; i++) {
        if (s1[i]!=s2[i] || s1[i] < 'A' || s1[i] > 'G') continue;
        day = s1[i];
        break;
    }
    i++;
    // hour
    for (; i<len; i++) {
        if (s1[i] == s2[i] && ( (s1[i]>='A' && s1[i]<='N') || isdigit(s1[i]) )) {
            h = s1[i];
            break;
        }
    }
}

void find2(string s1, string s2) {
    for (int i=0; i<s1.size() && i<s2.size(); i++) {
        if (s1[i]==s2[i] && isalpha(s1[i])) {
            m = i;
            return;
        }
    }
}

int main() {
    freopen("1.txt","r",stdin);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    find1(s1,s2);
    find2(s3,s4);
    // cout<<"d:"<<day<<",h:"<<h<<",m:"<<m<<endl;
    int daynum = day-'A';
    string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int hnum;
    if (isdigit(h)) {
        hnum = h-'0';
    }
    else {
        hnum = h-'A'+10;
    }
    printf("%s %02d:%02d",days[daynum].c_str(),hnum,m);
}