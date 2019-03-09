/*RootedTrees(根付き木の表現)*/

/*
与えられた根付き木Tの各接点uについて、以下の情報を出力するプログラム
＞uの接点番号
＞uの接点の種類(根、内部ノード、または葉)
＞uの親の接点番号
＞uの子の接点リスト
＞uの深さ
ここで与えられる木は、n個の接点番号を持ち、それぞれ0からn-1までの接点番号が割り当てられている。

入力:
  1 > 接点の個数 : n
  n > id k c1 c2...ck (id:接点の番号、k:次数（子の数）、c1-ck:子供の接点番号)

出力:
  n > ＜node id: parent = p, depth = d,type, [c1...ck]＞

  >出力形式は以下の通りで、節点の情報は、節点番号が小さい順に出力
  >pは親の番号を示す。親を持たない場合は-1
  >typeは根(root)、内部節点(internal node)、葉（leaf）を表す。
  >[c1...ck]は子のリスト。順序木（子供に順序性がある木）とみなし、入力された順番で出力
*/

//////////////////////////////前処理/////////////////////////////////////////

#include<stdio.h>
#define MAX 100005
#define NIL -1 //親を持たない場合はー1,子を持たない場合も-1

typedef struct Node{int p,l,r;}Node; //p:親, l:最も左の子ども r:すぐ右の兄弟

Node T[MAX];   //StructNodeを入れるリスト
int n, D[MAX]; //Dは各接点の深さのリスト

void print(int u){
  int i;
  printf("node %d : ",u);
  printf("parent = %d : ",T[u].p);
  printf("depth = %d : ",D[u]);

  if (T[u].p == NIL) printf("root, ");    //親がいない = 根っこ(root)
  else if(T[u].l == NIL)printf("leaf, "); //左下の子がいない = 子がいない　= 葉っぱ(leaf)
  else printf("internal node, ");         //上記二つ、どちらでもない = 内部接点(internal node)

  printf("[");

  int c = T[u].l;                         //T[u]の一番左の子供
  while (c != NIL){                       //兄弟をすべて辿る。
    printf("%d, ",c);
    c = T[c].r; 
  }
  printf(" ]");
}

//再帰的に深さを求める。
int rec(int u, int p){              //u:親の接点番号 p:主に深さが入る
  D[u] = p;                         //深さを記録するリストに入力
  if (T[u].p != NIL)rec(T[u].r,p);  //親が存在する場合　→　uの兄弟にも同じ深さを設定
  if(T[u].l != NIL)rec(T[u].l,p+1); //子供がいる場合　→　最も左の子に自分の深さ+1を設定
}

//////////////////////////////メイン関数/////////////////////////////////////////

int main(){
  int d,v,c,l,r;

  printf("接点の数を入力!!\n");
  scanf("%d",&n);

  for(int i = 0;i<n;n++){T[i].p = T[i].l = T[i].r = NIL;} //Nodeの要素をすべてNILにしておく
  for(int i = 0;i<n;n++){
    printf("接点の数と、子供の数を入力!!\n");                 
    scanf("%d %d",&v,&d);                                 //vは本体の接点番号、dは子供の次数
    for(int j = 0;j < d;j++){                             //こども次数分ループ処理を行う。
      printf("子供の接点番号を入力!!\n",)
      scanf("%d",&c);                                     //子供の接点番号を入力
      if(j == 0){T[v].l = c;}                             //1入力目の子供はT[v].left(一番左の子供)としてleftに登録する
      else {T[l].r = c;}                                  //2入力目以降はT[l].right(すぐ右の兄弟)
      l = c;                    
      T[c].p = v;                                         //親を設定
    }
  }

  for(i = 0; i<n ; i++){if(T[i].p == NIL) {r = i;}}       //根のリスト番号を探索している
  rec(r,0);                                               //根からスタートして深さのリストを作成する。

  for(i = 0;i<n;i++){print(i);}                           //全てのリストに対してprint関数をかける

  return 0;
}

//  各接点から親をたどっていくアルゴリズム O(h)
//  すべての接点(n)について深さを求める。O(hn)

//  再帰的に求める場合,すべての点を一回訪問すれば良いので O(n)