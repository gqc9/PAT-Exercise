#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 15;

int main() {
	freopen("1.txt", "r", stdin);
	int n;
	int rn[maxn];
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &rn[i]);
		rn[i] = -rn[i];
	}
	int arr[maxn][2];
	for (int i = 0; i<n; i++) {
		arr[i][0] = rn[i];
		arr[i][1] = 1;
	}
	int res[maxn];
	fill(res, res+n, 0);
	res[0] = arr[0][0];
	res[1] = arr[0][1];
	int len = 2;
	for (int i = 1; i<n; i++) {
		int tmp[maxn];
		fill(tmp, tmp+n, 0);
		// 0
		for (int j = 0; j<len; j++) {
			tmp[j] = arr[i][0] * res[j];
		}

		// 1
		for (int j = 1; j<=len; j++) {
			tmp[j] += arr[i][1] * res[j-1];
		}
		for (int j = 0; j<=len; j++) {
			res[j] = tmp[j];
		}
		len++;
	}

	for (int i = len-2; i>=0; i--) {
		printf("%d", res[i]);
		if (i!=0)printf(" ");
	}

}