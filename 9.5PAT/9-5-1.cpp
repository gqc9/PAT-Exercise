/*
 * 9.5PAT考试第一题
 * 熊猫、局部最小值
 *  */


#include <cstdio>

const int maxn = 100010;

int main() {
	freopen("1.txt", "r", stdin);
	int n;
	int kg[maxn];
	int milk[maxn];
	int l = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &kg[i]);
		if (i==0) {
			milk[i] = 200;
		}
		else if (i>0 && kg[i]<kg[i-1]) {
			milk[i] = 200;
			for (int j = i-1; j>=l; j--) {
				if (milk[j]-milk[j+1] <= 0)
					milk[j] += 100;
			}
		}
		else if (i>0 && kg[i]>kg[i-1]) {
			milk[i] = milk[i-1] + 100;
			l = i;
		}
		else if (kg[i] == kg[i-1]) {
			milk[i] = milk[i-1];
		}
	}
	int res = 0;
	for (int i = 0; i<n; i++) {
		res+=milk[i];
	}
	printf("%d", res);
	return 0;
}