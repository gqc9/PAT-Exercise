/*
 * 排序
 * 其中一个判例，如果使用string而不是char[]的话，因为cin比scanf慢，所以会超时。
 *  */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100010;

struct Person {
    char name[10];
    int age;
    int worth;
} people[maxn];

bool cmp (Person p1, Person p2) {
    if (p1.worth != p2.worth) {
        return p1.worth > p2.worth;
    }
    if (p1.age != p2.age) {
        return p1.age < p2.age;
    }
    return strcmp(p1.name, p2.name) < 0;
}


int main() {
    freopen("1.txt","r",stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
        // cin >> people[i].name >> people[i].age >> people[i].worth;
    }

    sort(people, people+n, cmp);

    int m, amin, amax;
    for (int i=1; i<=k; i++) {
        scanf("%d %d %d", &m, &amin, &amax);
        printf("Case #%d:\n", i);
        int count = 0;
        for (int j=0; j<n && count<m; j++) {
            if (people[j].age >= amin && people[j].age <= amax) {
                // printf("%s %d %d\n", people[j].name.c_str(), people[j].age, people[j].worth);
                cout << people[j].name << " " << people[j].age << " " << people[j].worth << endl;
                count++;
            }
        }
        if (count==0) {
            printf("None\n");
        }
    }

    return 0;
}