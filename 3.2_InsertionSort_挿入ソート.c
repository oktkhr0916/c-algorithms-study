/* InsertionSort(挿入ソート、0オリジン配列) */
//外部メモリが必要

/*
入力:
1 数列の長さを表すN
2 N個の整数

出力:
1 各ステップの計算結果途中を空白区切で出力
2 N個の整数
*/

#include<stdio.h>

/*配列の要素を順番に出力*/
void trace(int A[],int N){
  int i;
  for(i = 0; i < N;i++ ){
    if( i > 0) printf(" "); /*隣接する要素の間に１つの空白を入力*/
    printf("%d",A[i]);
  }
  printf("\n");
}

/* 挿入ソート(0オリジン配列) */
void insertionSort(int A[], int N){
  int j, i, v;
  for (i = 1; i < N; i++){
    v = A[i]; //挿入する要素
    j = i - 1;
    while( j >= 0 && A[j] > v){ //A[i}<A[j]の時
      A[j+1] = A[j]; // A[]
      j--;
    }
    A[j+1] = v;
    trace(A,N); //挿入を一度終えるたびにprintfで確認している。
  }
}

int main(){
  int N, i, j;
  int A[100];

  scanf("%d", &N); //ソートする要素の個数N
  for (i = 0; i < N; i++) scanf("%d", &A[i]); //A[]の値をNの数だけ取り込む

  trace(A,N); // 初期値の出力
  insertionSort(A,N);

  return 0;
}
