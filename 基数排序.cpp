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

int date[1000000];
int tmp[10][1000000];
int storemax(int num[], int n) {
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int count = 1, tmp = num[i];
        while (tmp / 10 != 0) {
            tmp /= 10;
            count++;
        }
        if (count > maxx) {
            maxx = count;
        }
    }
    return maxx;
}

void BaseSort(int num[], int n) {
    int maxx = storemax(num, n);
    int v = 1;
    for (int i = 0; i < maxx; i++) {
        int count[10];

        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < n; k++) {
                tmp[j][k] = 0;
            }
        }
        for (int j = 0; j < n; j++) {
            int fg = num[j] / v;
            int k = fg % 10;
            count[k]++;
            int temp = count[k] - 1;
            tmp[k][temp] = num[j];
        }
        int a = 0;
        for (int j = 0; j < 10; j++) {
            if (count[j] > 0) {
                for (int k = 0; k < count[j]; k++) {
                    num[a] = tmp[j][k];
                    a++;
                }
            }
        }
        v *= 10;
    }
}

void paint(int num[], int n) {
    for (int i = 0; i < n; i++) {
        cout << num[i] << endl;
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

    srand(time(NULL));
    int n = rand() % 1000 + 10000;
    for(int i = 0; i < n; i++){
        date[i] = rand() % 1000000;
    }
    BaseSort(date, n);
    paint(date, n);
}