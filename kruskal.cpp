#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int mapp[7][7];
int judge[7];
int pre[7], sum = 0;

struct edge {
    int v1;
    int v2;
    int val;
} a[11];

bool cmp(edge &c, edge &b) {
    return c.val < b.val;
}

void init() {
    a[0].v1 = 1;
    a[0].v2 = 2;
    a[0].val = 10;
    a[1].val = 30;
    a[1].v1 = 1;
    a[1].v2 = 4;
    a[2].val = 45;
    a[2].v1 = 1;
    a[2].v2 = 5;
    a[3].val = 20;
    a[3].v1 = 6;
    a[3].v2 = 4;
    a[4].val = 25;
    a[4].v1 = 2;
    a[4].v2 = 6;
    a[5].val = 40;
    a[5].v1 = 2;
    a[5].v2 = 5;
    a[6].val = 50;
    a[6].v1 = 2;
    a[6].v2 = 3;
    a[7].val = 35;
    a[7].v1 = 3;
    a[7].v2 = 5;
    a[8].val = 15;
    a[8].v1 = 3;
    a[8].v2 = 6;
    sort(a, a + 9, cmp);
    for(int i = 1; i <= 6; i++){
        pre[i] = i;
    }
}

int find(int x){
    if(x != pre[x]){
        pre[x] = find(pre[x]);
    }
    return pre[x];
}

void merge(int n){
    int fx = find(a[n].v1);
    int fy = find(a[n].v2);
    if(fx != fy){
        pre[fx] = fy;
        sum += a[n].val;
        mapp[a[n].v1][a[n].v2] = a[n].val;
        mapp[a[n].v2][a[n].v1] = a[n].val;
    }
}

void solve() {
    for (int i = 0; i <= 8; i++) {
        merge(i);
    }
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    cout << sum << endl;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << mapp[i][j] << ' ';
        }
        cout << endl;
    }
}