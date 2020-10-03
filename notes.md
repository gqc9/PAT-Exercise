# PAT刷题笔记

* 1013 计算图的连通分量个数
* 1030 Dijkstra + DFS
* 1034 map
* 1043 图DFS、字符串id转数字id
* 1043 二叉搜索树创建
* 1059 素数
* 1065 大数运算
* 1066 AVL树
* 1110 完全二叉树

## C++基础

* double要用`scanf("%lf",&d1)`

* `isdigit(), isupper(), islower(), isalpha()`: `<ctype.h>`

* [1110] 输入char和int混合数据需要转int，不能直接`cin >> (char)`，要读入string后`stoi(v)`转成int。char转int：`c-'0'`

* `max(), min()`: `<algorithm>`，并且`using namespace std;`

* int变浮点：`n * 1.0`。开根号：`(int)sqrt(n * 1.0)`，需要`<math.h>`

* 初始化数组全为固定值val：`fill(arr, arr+arr.size(), val);`，需要`<algorithm>`并且`using namespace std;`

* 复制数组a到新数组b：`copy(a,a+len,b);`或`memcpy(arr,newarr,sizeof(arr));`

* 双端队列`<deque>`：
```
a.push_back(e) //在尾部插入元素e,会不断扩张队列
a.push_front(e) //在头部插入元素e
a.pop_front() //在头部删除数据
a.pop_back() //在尾部删除数据
a.front()
a.back()
```

## set

* 插入`insert()`，删除`erase(val)`，迭代由小到大排序
```
for (auto it=s.begin(); it!=s.end(); it++)
    printf("%d\n",*it);
```

* 合并两个set，把`b`中的元素合并入`a`：
```
set<int> a,b;
a.insert(b.begin(),b.end());
```

## map

* 判断是否在map里`map.find(str) == map.end())`

## 字符串

* `stoi()`：`<string>`

* [1055] 能用char[]就不要用string，会影响速度：cin比scanf慢很多。strcmp()在`<cstring>`中。

* `substr()`取子串：
```
string s = "0123456789";

string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"

string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"
```

## Vector

* [1053] 这样复制之后，对v2的操作不会影响v1，反之亦然。仅复制其中数据。
```
vector v1;
vector v2 = v1;
```

* [1043] 比较两个vector内元素是否相同：`v1 == v2`

## 排序

* [1053] 对vector的排序：`sort(v.begin(),v.end());`

## 递归

* [1053] 记录递归路径：使用vector，当枚举当前访问节点的子节点过程中，先将子节点加入path vector中，再递归，递归结束后将之前加入的子节点pop_back()。path vector是全局变量。

## 树

* 二叉搜索树的插入：递归查找，在查找失败的地方（`root==NULL`）时，`root`就是要插入的地方。

* [1043] 新建树的节点：
```
node = new Node;
node->data = key;
node->left = node->right = NULL; // 一定要这一步
```

* [1043] 新建树：传入的一定是引用（`&`）。如果不加&，只是在函数内部修改，地址的变化不会反映到整体（如root->left还是没有被修改）
```
void insert(Node* &node, int key) {
    if (node...) {
        node = new Node;    // 这一步是修改了node的地址
    }
}
```

* [1066] AVL树
```
if (node->data > key) {
    insert(node->left, key);
    updateHeight(node);
    if (getBalanceFactor(node) == 2) {  //左子树高度 - 右子树高度
        if (getBalanceFactor(node->left) == 1) {
            RightRotate(node);
        }
        else if (getBalanceFactor(node->left) == -1){
            LeftRotate(node->left);
            RightRotate(node);
        }
    }
}
else {
    insert(node->right, key);
    updateHeight(node);
    if (getBalanceFactor(node) == -2) {
        if (getBalanceFactor(node->right) == -1) {
            LeftRotate(node);
        }
        else if (getBalanceFactor(node->right) == 1){
            RightRotate(node->right);
            LeftRotate(node);
        }
    }
}
```

* [1094] 层序遍历迭代写法模板。

* [1086] 非递归形式的二叉树遍历（栈）：[详解二叉树的非递归遍历](https://blog.csdn.net/z_ryan/article/details/80854233)

## 图

* 临时去除图中一个节点可以：把该节点的visited设为true，这样就不会访问它了

* 计算连通分量数：进行了几次dfs（一次遍历一个连通分量）

* 拓扑 判别无环图（邻接表）
```
先把所有入度为0的顶点压入q，然后
while (!q.empty()) {
    int v = q.front();
    q.pop();
    ////这里随便干点什么
    for (int i = 0; i<g[v].size(); i++) {
        if (--indegree[g[v][i]]==0) {
            q.push(g[v][i]);
        }
    }
    cnt++;
}
如果cnt==n，说明无环
```

## 并查集

* 压缩路径（递归）
```
int findFather(int idx) {
    return (idx == father[idx]) ? idx : father[idx] = findFather(father[idx]);
}
```

## Other

```
struct Node {
    vector<> v;
}
Node* nodes[];
nodes[i]->v.push_back(x); //会报错
//要改成
Node nodes[];
nodes[i].v.push_back(x);
```

* 最大公因数：`return b == 0 ? a : gcd(b, a % b);`

* #define _CRT_SECURE_NO_WARNINGS

