/*QuickSort(クイックソート)*/
//インプレースソート

/*

n枚のカードを整列する、書くカードに一つの絵柄(S,H,C,D)と一つの数のペアが描かれている。
これらをクイックソートに基づく、昇順に整列するプログラム
Aはカードが格納された配列、partitionにおける比較演算はカードに書かれた「数」を基準に行われるものとする。

また、与えられた入力に対し、安定な出力を行なっているかを報告。*/

/*
===入力===
  １ ＞　カードの枚数n
  N ＞ n枚のカード（絵柄を表す一つの文字と、数のペアで一行に与えられる。絵柄と数はスペースで仕切られている。）

===出力===
  １　＞　一行目に、この出力が安定か否かを出力
  2　＞　入力と同様の形式で整列されたカードを順番に出力
*/

/*//////////////////////////////前処理/////////////////////////////////////////*/

#inlude<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

//構造型Cardを定義
typedef struct Card{
  char suit;          //絵柄
  int value;          //数字
}Card;

Card L[MAX/2 + 2], R[MAX/2 + 2];    

/*//////////////////////////////merge sort/////////////////////////////////////////*/

void merge(Card A[],int n,int left,int mid,int right){
  int j,k;
  int n1 = mid - left;                      //左半分の数
  int n2 = right - mid;                     //右半分の数
  for(int i = 0;i<n1;i++)L[i] = A[left+i];  //一時的に右半分のリスト作成
  for(int i = 0;i<n2;i++)R[i] = A[mid +i];  //一時的に右半分のリスト作成
  L[n1].value = R[n2].value = SENTINEL;     //Lの最後の要素、Rの最後の要素
  i = j = 0;
  for (k = left; k < right; k++){           //左から右まで埋まるまで。
    if(L[i].value <= R[i].value){           //もし左の値が、右の値よりも小さかったら
      A[k] = L[i++];                        //後置インクリメント演算子:評価してから、i++をする
    }else{
      A[k] = R[j++];
    }
  }
}

void mergeSort(Card A[], int n, int left, int right){
  int mid;
  if (left +1 < right){           //要素が2個以上の時は
    mid = (left + right)/2;       //分割
    mergeSort(A,n,left,mid);      //左側を再帰的に分割
    mergeSort(A,n,mid,right);     //右側を再帰的に分割
    merge(A,n,left,mid,right);    //左右を統合
  }
}

/*//////////////////////////////quick sort/////////////////////////////////////////*/

int partition(Card A[], int n, int p, int r){
  Card t, x;
  x = A[r];                                 //partitonの初期値(:振り分けする一番右の値)
  int i = p - 1;                            //partionの値より小さい数字の右側
  for(int j = p; j < r;j++){                //評価するすべての値に関して
    if(A[j].value <= x.value){              //partitionの値よりも小さければ。
      i++;                                  //初期の状態でA[-1]→A[0]になる
      t=A[i]; A[i] = A[j]; A[j]=t           //入れ替え
    }
  }
  t = A[i+1]; A[i+1]=A[r]; A[r]=t;          //最後にpartitionを閾値の位置に挿入（境界の右側の値と入れ替え）
  return i+1;                               //partitonとなっている値のリスト番号を返す
}

void quickSort(Card A[],int n,int p,int r){ //要素数:n スタート:p 最後尾:r
  int q;
  if( p < r ){                              //partitionする値が2以上あったら
    q = partition(A[],n,p,r);               //partitionとなった番号の位置を返す。
    quickSort(A[],n,p,q-1);                 //partitionの前後で、再帰的にquicksort
    quickSort(A[],n,q+1,r);                 //partitionの前後で、再帰的にquicksort
  }
}

/*//////////////////////////////メイン関数/////////////////////////////////////////*/

int main(){
  int n,v;              //n:数、v:数字の入力用
  Card A[MAX], B[MAX];  //Aはマージソート用
  char S[10];           //Bはクイックソート用
  int stable = 1;       //判定の初期状態

  scanf("%d",&n);

  for (int i = 0; i < n; i++){
    scanf("%s %d",S,&v); //文字列charの時は&はいらない
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
  }

  mergeSort(A,n,0,n);
  quickSort(B,n,0,n-1);

  for(int i = 0; i<n; i++){
    //マージソートとクイックソートの結果を比べる
    if(A[i].suit != B[i].suit)stable = 0;
  }

  if(stable == 1)printf("Stable\n");
  else printf("Not Stable\n");
  for(int i = 0; i<n; i++){
    printf("%c %d\n", B[i].suit, B[i].value);
  }

  return 0;
}

/*/////////////////////////////考察/////////////////////////////////////*/

//  階層は(logn)で求められる。
//  各階層の計算量は(n):　nの分割数は違えど、nの数だけ、比較と追加が行われる。
//  よって計算量は（nlogn）
