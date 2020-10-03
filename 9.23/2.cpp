#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10010;
int s1[maxn];
int s2[maxn];
int s3[maxn];

bool cmp(int a, int b) {
	return a>b;
}

int getD(int a, int b, int c) {
	return abs(a-b) + abs(a-c) + abs(b-c);
}

int dist2(int a, int b) {
	return abs(a-b);
}

int main() {
	freopen("1.txt", "r", stdin);
	int n1, n2, n3;
	scanf("%d%d%d", &n1,&n2,&n3);
	for (int i = 0; i<n1; i++) {
		scanf("%d", &s1[i]);
	}
	for (int i = 0; i<n2; i++) {
		scanf("%d", &s2[i]);
	}
	for (int i = 0; i<n3; i++) {
		scanf("%d", &s3[i]);
	}

	//sort(s1, s1+n1, cmp);
	//sort(s2, s2+n2, cmp);
	//sort(s3, s3+n3, cmp);

	//int i = 0, j = 0, k = 0;
	//const int INF = 2000000000;
	//int a = INF, b = INF, c = INF;
	//int minD = INF;
	//while (i+1<n1&&j+1<n2&&k+1<n3) {
	//	int t = getD(s1[i], s2[j], s3[k]);
	//	if (i+1<n1) {
	//		if (t > getD(s1[i+1], s2[j], s3[k])) {
	//			if (minD > t) {
	//				minD = t;
	//				a = i;
	//				b = j;
	//				c = k;
	//			}
	//			i++;
	//			continue;
	//		}
	//	}
	//	if (j+1<n2) {
	//		if (t > getD(s1[i], s2[j+1], s3[k])) {
	//			if (minD > t) {
	//				minD = t;
	//				a = i;
	//				b = j;
	//				c = k;
	//			}
	//			j++;
	//			continue;
	//		}
	//	}
	//	if (k+1<n3) {
	//		if (t > getD(s1[i], s2[j], s3[k+1])) {
	//			if (minD > t) {
	//				minD = t;
	//				a = i;
	//				b = j;
	//				c = k;
	//			}
	//			k++;
	//			continue;
	//		}
	//	}
	//}
	


	
	//int dist12[maxn][maxn];
	//for (int i = 0; i<n1; i++) {
	//	for (int j = 0; j<n2; j++) {
	//		dist12[i][j] = dist2(s1[i], s2[j]);
	//	}
	//}
	const int INF = 2000000000;
	int a = INF, b=INF, c=INF;
	int minD = INF;
	for (int i = 0; i<n1; i++) {
		for (int j = 0; j<n2; j++) {
			for (int k = 0; k<n3; k++) {
				if (getD(s1[i], s2[j], s3[k]) < minD) {
					minD = getD(s1[i], s2[j], s3[k]);
					a = i;
					b = j;
					c = k;
				}
				else if (getD(s1[i], s2[j], s3[k]) == minD) {
					if (a+b+c<i+j+k) {
						a = i;
						b = j;
						c = k;
					}
				}
			}
		}
	}
	
	printf("MinD(%d, %d, %d) = %d", s1[a], s2[b], s3[c], minD);
}