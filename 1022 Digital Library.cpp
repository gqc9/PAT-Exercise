/*
 * map的使用
 *  */
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

const int K = 6;
map<string, set<int>> maps[K];

int main() {
    freopen("1.txt", "r", stdin);
    int n, id, m, kq;
    string str;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%d\n", &id);
        for (int j = 1; j<6; j++) {
            if (j!=3) {
                getline(cin, str);
                maps[j][str].insert(id);
            }
            else {
                while (cin >> str) {
                    maps[j][str].insert(id);
                    if (getchar() == '\n') break;
                }
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        scanf("%d: ", &kq); //***重要***这里不能漏掉空格，不然getline会把空格一起存入str中，map里就找不到了
        getline(cin, str);
        cout << kq << ": " << str << endl;
        if (maps[kq].find(str) != maps[kq].end()) {
            for (auto j = maps[kq][str].begin(); j!=maps[kq][str].end(); j++) {
                printf("%07d\n", *j);
            }
        }
        else {
            printf("Not Found\n");
        }
    }


}
