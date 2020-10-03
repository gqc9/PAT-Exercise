// 7.3链表


#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int addr;
    int key;
    int next;
    bool flag;
} nodes[100010];

bool cmp(Node a, Node b) {
    if (a.next==0 || !a.flag) return false;
    if (b.next==0 || !b.flag) return true;

    return a.key<b.key;
}

int main() {
    int n, head;
    scanf( "%d %d", &n, &head);
    for (int i=0; i<n; i++) {
        int addr, key, next;
        scanf( "%d %d %d", &addr, &key, &next);
        nodes[addr].addr = addr;
        nodes[addr].key = key;
        nodes[addr].next = next;
    }

    // 遍历出链表中的节点及链表长度
    int index=head, len=0;
    while (index!=-1) {
        nodes[index].flag = true;
        index = nodes[index].next;
        len++;
    }

    sort(nodes, nodes+100010,cmp);

    if(len>0) printf("%d %05d\n", len, nodes[0].addr);
    else{   //有可能连表里一个都没有（均为无效节点）
        printf("%d %d\n", len, head);
        return 0;
    }
    for (int i=0; i<len-1; i++) {
        printf("%05d %d %05d\n", nodes[i].addr, nodes[i].key, nodes[i+1].addr);
    }
    printf("%05d %d %d\n", nodes[len-1].addr, nodes[len-1].key, -1);

    return 0;
}