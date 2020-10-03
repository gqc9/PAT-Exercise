/*
 * 大数加法和比较
 * 这题范围63位，所以可以直接用long long
 * A+B>C: true, A+B<=C: false
 *  */

#include <cstdio>
#include <iostream>
#include <string.h> // memset()
#include <algorithm>
using namespace std;

const int maxlen = 65;
struct bign {
    int data[maxlen];
    int len;
    int sign;
    bign() {
        memset(data, 0, sizeof(data));
        len = 0;
        sign = 1;
    }
};

// 转化成大数
bign toBigN(string str) {
    bign res;
    if (str.at(0)=='-') {
        res.sign = -1;
        str = str.substr(1);
    }
    res.len = str.length();
    for (int i=0; i<str.length(); i++) {
        res.data[i] = str.at(str.length() - i - 1) - '0';   // 重要：将char转换为int
    }
    return res;
}


// 两个大数比较。true为x>y，false为x<=y
bool compare(bign x, bign y) {
    // 以下这几行判断'-0'情况的可以省略
    // if (x.len==1 && x.data[0]==0 && y.len==1 && y.data[0]==0) return false;
    // if (x.len==1 && x.data[0]==0) return y.sign < 0;
    // if (y.len==1 && y.data[0]==0) return x.sign > 0;
    if (x.sign * y.sign < 0)  return x.sign > y.sign; //一正一负
    bool posi = (x.sign > 0); // 两个都是正

    if (x.len == y.len) {
        for (int i=x.len-1; i>=0; i--) {
            if (x.data[i] == y.data[i]) continue;
            if (posi) return x.data[i] > y.data[i];
            else return x.data[i] < y.data[i];
        }
        return false;   // 相等
    }
    else {
        if (posi) return x.len > y.len;
        else return x.len < y.len;
    }
}


// 两个大数相加
bign add(bign a, bign b) {
    bign res;
    int carry = 0;
    int i;
    for (i=0; i<a.len || i<b.len; i++) {
        int sum = a.data[i] + b.data[i] + carry;
        res.data[i] = sum % 10;
        carry = sum / 10;
        res.len++;
    }
    if (carry > 0) {
        res.data[i] = carry;
        res.len++;
    }
    return res;
}

bool equal(bign x, bign y) {
    if (x.sign != y.sign) return false;
    if (x.len != y.len) return false;
    for (int i=x.len-1; i>=0; i--) {
        if (x.data[i] != y.data[i]) return false;
    }
    return true;   // 相等

}

// 大数相减a-b，需要a>b才行，所以减之前如果a<b，要先互换位置，最后取负
bign substract(bign a, bign b) {
    bign res;
    if (compare(a, b)) {   //如果a>b
        int carry = 0;
        int i;
        for (i=0; i<a.len || i<b.len; i++) {
            res.data[i] = a.data[i] - b.data[i] - carry;
            if (res.data[i]<0) {
                res.data[i] += 10;
                carry = 1;
            }
            else carry = 0;
            res.len++;
        }
        // 去除高位多余的0，并至少要保留最低位的0
        while (res.len-1 > 0 && res.data[res.len-1] == 0) {
            res.len--;
        }
    }
    else if (equal(a, b)) {
        res.len = 1;
        return res;
    }
    else {  //如果a<b
        res = substract(b, a);
        res.sign = -1; // 换位，要取负
        return res;
    }
    return res;
}


int main() {
    freopen("1.txt","r",stdin);
    const int maxn = 15;
    int n;
    scanf("%d", &n);
    bool res[maxn];
    for (int i=0; i<n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        bign a = toBigN(s1);
        bign b = toBigN(s2);
        bign c = toBigN(s3);
        bign sum;
        if (a.sign * b.sign > 0) {
            sum = add(a, b);
            if (a.sign<0) sum.sign = -1;
        }
        else {
            if (a.sign == 1) {
                b.sign = 1;
                sum = substract(a, b);
            }
            else {
                a.sign = 1;
                sum = substract(b, a);
            }
        }
        res[i] = compare(sum, c);
    }

    for (int i=0; i<n; i++) {
        printf("Case #%d: ", i+1);
        if (res[i]) printf("true");
        else printf("false");
        printf("\n");
    }

    return 0;
}