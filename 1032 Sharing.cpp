// 7.3链表
// 相交链表
// 牛客里全通过，PTA里有两个没通过。
// 【因为PAT会提供一些没有在单词字母链中出现过的无关结点，这些结点会干扰结果】

#include <cstdio>
using namespace std;

struct Node {
    char data;
    int next;
} nodes[100010];

int main() {
    FILE* fp = fopen("input.txt","r");
    int start1, start2, n;
    int end=0;
    fscanf(fp, "%d %d %d", &start1, &start2, &n);
    for (int i=0; i<n; i++) {
        int add, nextAdd;
        char c;
        fscanf(fp, "%d %c %d", &add, &c, &nextAdd);
        nodes[add].data = c;
        nodes[add].next = nextAdd;
        if (nextAdd==-1) end = add;
    }

    // 头尾相连，找是否有环
    nodes[end].next = start1;
    int slow = start2, fast = start2;
    while (fast!=0 && nodes[fast].next!=0) {
        slow = nodes[slow].next;
        fast = nodes[nodes[fast].next].next;
        if (slow==fast) { // 相交
            fast = start2;
            while (fast!=slow) {
                fast = nodes[fast].next;
                slow = nodes[slow].next;
            }
            printf("%05d", fast);
            return 0;
        }
    }
    printf("-1");
    return 0;
}