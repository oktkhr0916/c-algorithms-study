//幅優先探索(BFS)

/*
与えられた有向グラフG = (V,E)について、頂点１から角頂点への最短距離d（バス上の辺の数上の最小値）を
求めるプログラムを作成。各頂点には１からnまでの番号が振られているものとします。
頂点１からたどり着けない頂点については、距離として−１を出力

入力:

    1＞Gの頂点数n
    n＞各頂点uの隣接リスト＜u(頂点番号) k(次数)v1-vk(uに隣接する頂点の番号)＞

出力:

    1＞各頂点については、id,d,を空白区切で出力。頂点の番号順で出力
　bんhjk　　
実装方法
    １＞スタックによる深さ優先探索
    ２＞再帰による深さ優先探索

*/

//////////////////////////////前処理/////////////////////////////////////////

#include<stdio.h>

#define N 100
#define INFTY (1<<21)
#define LEN 100005  //queueの長さ
#define None 0

/*グローバル変数*/
int n ,M[N][N];  //n:接点の数　M:隣接リスト
int d[N];        //訪問状態の管理（距離で管理している）
int Q[LEN];      //キューを表現するリスト
int head = 0;    //キューの頭を初期化（先入れ、先出し）
int tail = 0;    //キューの尻尾を初期化（先入れ、先出し）

/*キューを実現する関数*/
void enqueue(int x){ //Qに要素xを追加する関数、Q[tail]にxを代入してtailを一つ増やす。
  Q[tail]=x;
  tail = (tail + 1) % LEN;
}

/*キューを実現する関数*/
int dequeue(){ //Qの先頭から要素を取り出す関数、Q[head]の値を返し、headを一つ増やす。
  int x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

//////////////////////////////幅優先探索//////////////////////////////////////

void bfs(int s){ //void:戻り値のない関数
    enqueue(s);  //queueにs(0)を追加する
    for(int i = 0; i < n ; i++){d[i] = INFTY;} //距離リストの全ての値を未定義状態にする
    d[s] = 0;    //出発地点の距離は0
    int u;
    while( head == tail ){  //head == tail : キューが空じゃない
        u = dequeue();            //キューの先頭の値を取り出す。
        for(int v = 0; v < n; v++){
            if(M[u][v] == None){continue;}  //探索対象にパスが通っていない場合
            if(d[v] != INFTY){continue;}    //探索済みの場合
            d[v] = d[u] + 1;                //距離（深さ）は : 親 + 1
            enqueue(v);                     //次に子を探索するために親としてキューに入れる
        }
    }
    for(int i = 0; i < n; i++ ){printf("接点のid:%d 接点の距離:%d\n",i ,d[i]);}
}

//////////////////////////////メイン関数//////////////////////////////////////

int main(){
    int n,u,k,v;
    printf("頂点の数を入力\n");
    scanf("%d",&n);
    for (int i = 0; i < n ;i++){for (int j = 0; j < n ;j++){M[i][j] = None;}} //隣接リストの全てを初期化する
    for (int i = 0; i < n ;i++){
        printf("頂点番号と隣接する頂点の数を空白で空けて入力\n");
        scanf("%d%d",&u,&k);
        for(int i = 0; i < k; i++){
            printf("隣接する頂点の番号を入力\n");
            scanf("%d", &v);
            M[u][v] = 1;
        }
    }
    bfs(1);
    return 0;
}

//計算時間　＞　すべての頂点に対して、隣接しているかを調べるので、O(v^2)のアルゴリズム