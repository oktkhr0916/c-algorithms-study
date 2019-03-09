/*二分木の表現*/

/*
一つの根を持ち全ての節点についてその子の数が２以下である木を根付き二分木という。
二分木では節点が持つ子供の数は２以下になるが、左の子と右の子は区別される。
よって子供に順序性があるため、順序木であるとも言える。


与えられた根付き二分木Tの各節点uについて、以下の情報を出力するプログラム。
＞uの接点番号
＞uの親
＞uの兄弟
＞uの子の数
＞uの深さ
＞uの高さ
＞接点の種類(根、内部接点または葉)

入力:
  １＞接点の個数n個
  n ＞各接点の情報を与える<id left right> id:接点の番号、left:左の子の番号、right:右の子の番号(子を持たない場合はleft(right)は-１)

出力:
  n＞ ＜node id: parent = p, sibling = s, degree = deg, depth = dep, height = h, type＞

p:親の番号(親を持たない場合は-1)
s:は兄弟の番号、(兄弟を持たない場合は-1)
deg:子の数 dep(depth):深さ h(height):高さ
type:根(root)、内部節点(internal node)、葉（leaf）を表す。
*/

//////////////////////////////前処理/////////////////////////////////////////

#include<stdio.h>
#define MAX 10000
#define NIL -1

typedef struct Node{int parent,left,right;}Node;

Node T[MAX];           //Nodeを入れるリスト(T : tree)
int n, D[MAX], H[MAX]; //接点の数 D:深さ H:高さ

/*////////////////////////////二分木の表現////////////////////////////////////////*/

void setDepth(int u,int d){     //深さを求める u:根の節点 d:根の深さ(初期値:d = 0)
  if(u == NIL){return;}           //if 根がない　→　グラフが閉じていて木じゃない。
  D[u] = d;                     //根から初めて、再帰的に深さを求めることができる。
  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}

int setHeight(int u){                                     //根から初めて、再帰的に高さを求めることができる。
  int h1 = 0, h2 = 0;                                     //左右の子供から帰ってきた高さをおさめる。
  int return_num = 0;                                         //
  if(T[u].left != NIL){ h1 = setHeight(T[u].left)+1; }    //もし左のこどもがNIL( = -1)じゃなければ、
  if(T[u].right != NIL){ h1 = setHeight(T[u].right)+1; }  //もし右のこどもがNIL( = -1)じゃなければ
  if (h1>h2){return_num=h1;}else{return_num=h2;}            //左右、どちらが深いか比較する。
  return H[u] = return_num;                               //再帰的に接点番号で高さを格納する
}

//節点uの兄弟を返す
int getSibling(int u){
  if (T[u].parent == NIL){return NIL;}                              //親がいないときは、そいつが根→よって兄弟がいない。
  if (T[T[u].parent].left) != u && (T[T[u].parent].left) != NIL)    //親の左が自分じゃなくて、空でもないとき
    return T[T[u].parent].left;                                     //左に兄弟がいることになるので、左の値を返す。
  if (T[T[u].parent].right) != u && (T[T[u].parent].right) != NIL)  //親の左が自分じゃなくて、空でもないとき
    return T[T[u].parent].right;                                    //右に兄弟がいることになるので、右の値を返す。
  return NIL;
}

void print_tree(int u){
  printf("< node %d: ", u);                     
  printf("parent = %d, ", T[u].parent);        
  printf("sibling = %d, ", getSibling(u));     
  int deg = 0;                               
  if(T[u].left != NIL){deg++;}
  if(T[u].right != NIL){deg++;}
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d", H[u]);

  if(T[u].parent == NIL){printf("type = root\n");} 
  else if(T[u].left == NIL && T[u].right == NIL){printf("type = leaf\n");}  
  else{printf("type = interal node\n");}                                       
}

/*////////////////////////////メイン関数////////////////////////////////////////*/

int main(){
  int v, root = 0;

  printf("接点の数を入力!!\n");
  scanf("%d", &n);                                            //接点の数

  for(int i = 0; i<n; i++)T[i].parent = NIL;                  //親の初期化
  for(int i = 0; i<n; i++){
    printf("接点番号、左の子の接点番号、右の子の接点番号を入力！！子がいない場合は-1を入力\n");
    scanf("%d %d %d",&v, &T[v].left ,&T[v].right);            //vは接点番号、l:左の子の接点番号、r:右の子の接点番号
    if(T[v].left != NIL){T[T[v].left].parent = v;}
    if(T[v].right != NIL){T[T[v].right].parent = v;}
  }

  //すべてのリストに対してparentがNILだった場合。根の接点番号を記憶。
  for(int i = 0; i<n; i++){if(T[i].parent == NIL){root = i;}} //根を記憶

  setDepth(root,0);                                           //深さを設定
  setHeight(root);                                            //高さを設定

  for(int i = 0; i<n; i++){print_tree(i);}

  return 0;
}

/*/////////////////////////////考察/////////////////////////////////////*/

//  高さを求めるアルゴリズムは、すべての節点を1回ずつ訪問しているので、O(n)のアルゴリズムになる 
