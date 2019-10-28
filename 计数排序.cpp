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

const int maxn = (int) 1e7 + 100;
int aftersort[maxn];//目标数组
int num[maxn], countNum[maxn];
int n;

void CountSort(int maxx) {
    memset(countNum, 0, sizeof(int) * (n + 5));
    for(int i = 0; i <= maxx; i++){
        countNum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        countNum[num[i]]++;
    }
    for(int i = 0; i <= maxx; i++){
        countNum[i] += countNum[i - 1];
    }
    for (int i = n; i > 0; i--) {
        aftersort[countNum[num[i - 1]] - 1] = num[i - 1];
        countNum[num[i - 1]]--;
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
    n = rand() % 10000 + 100000;
    //n = 10;
    int maxx = 0;
    for(int i = 0; i < n; i++){
        num[i] = rand() % 1000000;
        //cout << num[i] << endl;
        maxx = max(maxx, num[i]);
    }
    CountSort(maxx);
    for(int i = 0; i < n; i++){
        cout << aftersort[i] << endl;
    }
}