#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<chrono>

using namespace std;

const int maxn = (int)1e7 + 100;
int num[maxn];

int parttion(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if(a[j] <= x){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

int randomized_parttion(int a[], int p, int r) {
	int i = rand() % (r - p + 1) + p;
	swap(a[r], a[i]);
	return parttion(a, p, r);
}

int rand_select(int a[], int p, int r, int i) {
	if (p == r) {
		return a[p];
	}
	int q = randomized_parttion(a, p, r);
	int k = q - p + 1;
	if (i == k) {
		return a[q];
	}
	else if (i < k) {
		return rand_select(a, p, q - 1, i);
	}
	else {
		return rand_select(a, q + 1, r, i - k);
	}
}

void solve1() {//随机选择
	cout << "下面是随机选择部分" << endl;
	int n;
	cout << "请输入数组的大小：";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		num[i] = rand() % 1000000;
		cout << num[i] << ' ';
	}
	cout << endl;
	cout << "请输入要找到第几小的数:";
	int tmp;
	cin >> tmp;
	chrono::steady_clock::time_point t1, t2;
	chrono::duration<double> cost;
	t1 = chrono::steady_clock::now();
	int ans = rand_select(num, 1, n, tmp);
	t2 = chrono::steady_clock::now();
	cout << ans << endl;
	cost = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	cout << "运行时间为:" << cost.count() << endl;
}

void insertsort(int a[], int low, int high) {
	int key;
	for (int i = low + 1; i <= high; i++) {
		key = a[i];
		int j;
		for (j = i - 1; j >= low && key < a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int partition(int a[], int p, int r, int pivot) {
	int x, i = p - 1, j, tmp;
	for (j = p; j < r; j++) {
		if (a[j] == pivot) {
			swap(a[j], a[r]);
		}
	}
	x = a[r];
	for (j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[r], a[i + 1]);
	return i + 1;
}

int select(int a[], int l, int r, int k){
	int group, i, left, right, mid, privot, p, left_num;
	if (r - l + 1 <= 5) {
		insertsort(a, l, r);
		return a[l + k - 1];
	}

	group = (r - l + 1 + 5) / 5;
	for (int i = 0; i < group; i++) {
		left = l + 5 * i;
		right = (l + 5 * i + 4) > r ? r : l + 5 * i + 4;
		mid = (left + right) >> 1;
		insertsort(a, left, right);
		swap(a[l + i], a[mid]);
	}
	privot = select(a, l, l + group - 1, (group + 1) >> 1);

	p = partition(a, l, r, privot);
	left_num = p - 1;
	if (k == left_num + 1) {
		return a[p];
	}
	else if (k <= left_num) {
		return select(a, l, p - 1, k);
	}
	else {
		return select(a, p + 1, r, k - left_num);
	}
}

void solve2() {
	cout << "下面是最坏情况下为线性时间的选择算法" << endl;
	int n;
	cout << "请输入数组的大小:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		num[i] = rand() % 10000000;
		//cout << num[i] << ' ';
	}
	cout << endl;
	cout << "请输入要找第几小的数:";
	int tmp;
	cin >> tmp;
	chrono::steady_clock::time_point t1, t2;
	chrono::duration<double> cost;
	t1 = chrono::steady_clock::now();
	int ans = select(num, 1, n, tmp);
	t2 = chrono::steady_clock::now();
	cout << ans << endl;
	cost = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	cout << "运行时间为:" << cost.count() << endl;
}

int main(void) {
	srand(time(NULL));
	//int n = rand() % 1000 + 1000;
	//solve1();//随机数
	solve2();//下面是最坏情况下为线性时间的选择算法
}