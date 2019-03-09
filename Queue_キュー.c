/* Queue_キュー */
/// 配列によるリングバッファ

#include<stdio.h> //入出力
#include<string.h> //文字列操作
#define LEN 100005

/* プロセスを表す構造体 */
typedef struct pp{
  char name[100];
  int t;
}P;

P Q[LEN];
int head, tail, n;

void enqueue(P x){ //Qに要素xを追加する関数、Q[tail]にxを代入してtailを一つ増やす。
  Q[tail]=x;
  tail = (tail + 1) % LEN;
}

P dequeue(){ //Qの先頭から要素を取り出す関数、Q[head]の値を返し、headを一つ増やす。
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int min(int a, int b){return a < b ? a : b; } ///最小値を返す a<b が真a,偽b

int main(){
  int elaps = 0, c;
  int i ,q;
  P u;
  scanf("%d %d",&n,&q); //ラウンドロビンスケジュールにおける最大クオンタイム:q プロセスの数:n

/*全てのプロセスをキューに順番に追加する*/
  for (i = 1; i <=n; i++){
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
    }
  head = 1; tail = n+1;

  /* シュミレーション*/
  while(head != tail){
    u  = dequeue();
    c = min(q, u.t);
    u.t -= c; //残りの必要時間を計算
    elaps += c; //経過時間を加算
    if(u.t>0)enqueue(u); //処理が完了してなければ、キューの末尾に追加
    else{
      printf("%s %d\n",u.name, elaps);
    }
  }

  return 0;
}
