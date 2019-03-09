/*　単一視点最短経路(ダイクストラのアルゴリズム)　*/

/*

与えられた重み付き有向グラフG=(V,E)について、最小全域木の辺の重みの総和を求めるプログラムを作成する。

入力:
最初の行に、Gの頂点数nが与えられる。
続くn行に、各頂点uの隣接リストが以下の形式で一行に与えられる。
<u k v1 c1 v2 c2>
u は頂点の番号、kはuの出次数、vはuに隣接する頂点の番号であり、cは有効辺の重み。

出力:
最小全域木の辺の重みの総和を出力
*/

//////////////////////////////前処理/////////////////////////////////////////
#include<stdio.h>

#define MAX 100
#define INFTY (1<<21) //最大値を定義しておく
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[MAX][MAX]; //隣接リストの作成

//////////////////////////////プリムのアルゴリズム/////////////////////////////////////////
void prim(){
    int u,minv;
    int d[MAX],p[MAX],color[MAX]; //d:頂点をつなぐ最小パス、p:親となる頂点、c:頂点の探索状況

    for(int i = 0 ; i < n ; i++){
        d[i] = INFTY;       //最長に設定しておく
        p[i] = -1           //親を初期化しておく
        color[i] = WHITE;   //探索状況を初期化しておく
    }

    d[0] = 0;               //出発点の距離は0

    while(1){
        minv = INFTY;       //最小値を0
        int u = -1;         //とりあえずの次数を決定しておく
        for(int i = 0 ; i < n ; i++){
            if( minv > d[i] && color[i] != BLACK){  //探索済みでない最小の値
                u = i;       //親になる次数を決定する
                minv = d[i]; //親の最短距離はminv 
            }
        }
        if(u == -1){break;} //BLACK以外ない時点で、全探索終了
        color[u] = BLACK; //親を探索済みにする
        for (int v = 0; v < n; v++){
            if(color[v] !=BLACK && M[u][v] != INFTY ){　//パスが通っている、かつ、探索済みでなければ
                if(d[v] > M[u][v]){                     //最短経路を短縮できれば
                    d[v] = M[u][v];                     //最短経路の入れ替えを行う。
                    p[v] = u;                           //親を決定する
                    color[v] = GRAY;                    //探索中にしておく
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        if (p[i] != -1) {sum += M[i][p[i]];}   //すべての頂点に対して、親との距離を合計する
    }
    return sum;
}

//////////////////////////////メイン関数/////////////////////////////////////////
int main(){
    int i,j,u,k,v,c,n;
    printf("頂点の数は？\n");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            M[i][j] = INFTY;
            }
        }

    for(i = 0 ; i < n ; i++){
        printf("頂点の番号は？\n");
        scanf("%d",&u);
        printf("uの出次数？\n");
        scanf("%d",&k);
        for(j = 0 ; j < k ; j++){
            printf("隣接する頂点の番号は？\n");
            scanf("%d",&v);
            printf("隣接する頂点の有効辺の重みは？\n");
            scanf("%d",&c);
            }
        }
    printf("%d",prim());

    return 0;
}


//計算時間　＞　O(V^2)のアルゴリズム