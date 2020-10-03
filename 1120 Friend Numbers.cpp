#include <cstdio>
#include <set>
using namespace std;

int main() {
    freopen("1.txt","r",stdin);
    int n, a;
    set<int> s;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a);
        int sum = 0;
        while (a!=0) {
            sum += a%10;
            a/=10;
        }
        s.insert(sum);
    }
    printf("%d\n",s.size());
    for (set<int>::iterator it = s.begin(); it!=s.end(); it++) {
        if (it != s.begin()) printf(" ");
        printf("%d", *it);
    }
}