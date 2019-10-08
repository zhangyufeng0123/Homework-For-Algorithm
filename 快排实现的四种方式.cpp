//\\ \\ \\ \\ \\ \\ \\ \\ || || || || || || // // // // // // // //
//\\ \\ \\ \\ \\ \\ \\        _ooOoo_          // // // // // // //
//\\ \\ \\ \\ \\ \\          o8888888o            // // // // // //
//\\ \\ \\ \\ \\             88" . "88               // // // // //
//\\ \\ \\ \\                (| -_- |)                  // // // //
//\\ \\ \\                   O\  =  /O                     // // //
//\\ \\                   ____/`---'\____                     // //
//\\                    .'  \\|     |//  `.                      //
//==                   /  \\|||  :  |||//  \                     ==
//==                  /  _||||| -:- |||||-  \                    ==
//==                  |   | \\\  -  /// |   |                    ==
//==                  | \_|  ''\---/''  |   |                    ==
//==                  \  .-\__  `-`  ___/-. /                    ==
//==                ___`. .'  /--.--\  `. . ___                  ==
//==              ."" '<  `.___\_<|>_/___.'  >'"".               ==
//==            | | :  `- \`.;`\ _ /`;.`/ - ` : | |              \\
////            \  \ `-.   \_ __\ /__ _/   .-` /  /              \\
////      ========`-.____`-.___\_____/___.-`____.-'========      \\
////                           `=---='                           \\
//// //   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \\ \\
//// // //      佛祖保佑      永无BUG      永不修改        \\ \\ \\ \\
//// // // // // // || || || || || || || || || || \\ \\ \\ \\ \\ \\

//by ACM-er vegetable birds

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll times1 = 0, times2 = 0, times3 = 0, times4 = 0;
int n = 100000;
const int maxn = 1e7 + 100;
int re1[maxn], re2[maxn];

void quickSort1(int num[], int first, int last);//主元在第一个位置
void quickSort2(int num[], int first, int last);//主元在最后一个位置
void quickSort3(int num[], int first, int last);//主元在中间的位置
void quickSort4(int num[], int first, int last);//主元出现在随机的位置

void print(int a[], int m) {
    for (int j = 0; j < m; j++) {
        cout << a[j] << endl;
    }
}

void quickSort1(int num[], int first, int last) {
    if (first < last) {
        int i = first, j = last;
        int x = num[first];
        while (i < j) {
            while (i < j && num[j] >= x) j--;
            if (i < j) {
                num[i++] = num[j];
                times1++;
            }
            while (i < j && num[i] <= x) i++;
            if (i < j) {
                num[j--] = num[i];
                times1++;
            }
        }
        //num[first] = num[i];
        num[i] = x;
        quickSort1(num, first, i - 1);
        quickSort1(num, i + 1, last);
    }
}

void quickSort2(int num[], int first, int last) {
    if (first < last) {
        int i = first, j = last;
        int x = num[last];
        while (i < j) {
            while (i < j && num[i] <= x) i++;
            if (i < j) {
                num[j--] = num[i];
                times2++;
            }
            while (i < j && num[j] >= x) j--;
            if (i < j) {
                num[i++] = num[j];
                times2++;
            }
        }
        num[j] = x;
        quickSort2(num, first, j - 1);
        quickSort2(num, j + 1, last);
    }
}

void quickSort3(int num[], int first, int last) {
    if (first < last) {
        int i = first, j = last;
        int middle = (first + last) / 2;
        int x = num[middle];
        while (i < j) {
            while (num[i] < x) i++;
            while (num[j] > x) j--;
            if (i <= j) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                i++;
                j--;
            }
        }
        quickSort3(num, first, j);
        quickSort3(num, i, last);
    }
}

void quickSort4(int num[], int first, int last) {
    if (first < last) {
        int i = first, j = last;
        int e = rand() % (max(1, j - i - 2)) + i + 1;
        int x = num[e];
        while (i < j) {
            while (num[i] < x) i++;
            while (num[j] > x) j--;
            if (i <= j) {
                swap(num[i], num[j]);
                i++;
                j--;
            }
        }
        quickSort4(num, first, j);
        quickSort4(num, i, last);
    }
}

void give(int num[], int ans[]) {
    for (int i = 0; i < n; i++) {
        ans[i] = num[i];
    }
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    clock_t stime, etime;
    chrono::steady_clock::time_point t1, t2;
    chrono::duration<double> cost;
    srand(time(NULL));

    n = 10000000;
    for (int i = 0; i < n; i++) {
        //times1 = times2 = times3 = times4 = 0;
        re1[i] = rand() % 10000000;
        //cout << num[i] << endl;
    }

    give(re1, re2);
    t1 = chrono::steady_clock::now();
    quickSort1(re2, 0, n - 1);
    t2 = chrono::steady_clock::now();
    cost = chrono::duration_cast<chrono::duration<double>> (t2 - t1);
    cout << cost.count() << endl;
    give(re1, re2);
    t1 = chrono::steady_clock::now();
    quickSort2(re2, 0, n - 1);
    t2 = chrono::steady_clock::now();
    cost = chrono::duration_cast<chrono::duration<double>> (t2 - t1);
    cout << cost.count() << endl;
    give(re1, re2);
    t1 = chrono::steady_clock::now();
    quickSort3(re2, 0, n - 1);
    t2 = chrono::steady_clock::now();
    cost = chrono::duration_cast<chrono::duration<double>> (t2 - t1);
    cout << cost.count() << endl;
    give(re1, re2);
    t1 = chrono::steady_clock::now();
    quickSort4(re2, 0, n - 1);
    t2 = chrono::steady_clock::now();
    cost = chrono::duration_cast<chrono::duration<double>> (t2 - t1);
    cout << cost.count() << endl;
}