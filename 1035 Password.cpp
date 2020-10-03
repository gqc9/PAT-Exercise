/*
 * 字符串替换字符
 *  */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    freopen("1.txt","r",stdin);
    int n;
    string id, str;
    vector<string> ids;
    vector<string> pass;
    bool change = false;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        change = false;
        cin >> id >> str;
        for (int j=0; j<str.size(); j++) {
            if (str[j] == '1' || str[j] == '0' || str[j] == 'l' || str[j] == 'O') change = true;
            if (str[j] == '1') str[j] = '@';
            else if (str[j] == '0') str[j] = '%';
            else if (str[j] == 'l') str[j] = 'L';
            else if (str[j] == 'O') str[j] = 'o';
        }
        if (change) {
            ids.push_back(id);
            pass.push_back(str);
        }
    }

    if (ids.size() == 0) {  //***重要***注意account的单复数
        if (n>1) printf("There are %d accounts and no account is modified", n);
        else printf("There is %d account and no account is modified", n);
        return 0;
    }
    printf("%d\n", ids.size());
    for (int i=0; i<ids.size(); i++) {
        cout << ids[i] << " " << pass[i] << endl;
    }
}