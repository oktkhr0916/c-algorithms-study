/* BubbleSort(バブルソート、0オリジン配列) */

#include<stdio.h>

void trace(int A[],int N){
  int i;
  for(i = 0; i < N; i++ ){
    if( i > 0) printf(" "); /*隣接する要素の間に１つの空白を入力*/
    printf("%d",A[i]);
  }
  printf("\n");
}

int bubbleSort(int A[],int N){
  int i, j;
  int a;

  for(i=0; i < N-1; i++){ //iがN-1より小さい間,
    for(j = N - 1; j > i; j--){  //jがiより大きい間
      if(A[j] < A[j-1]){ //A[j]とA[j-1]（最小では、A[0](i=0の時)）を比較
        a = A[j];
        A[j] = A[j-1];
        A[j-1] = a;
      }
    }
    trace(A,N); //途中結果を出力
  }
}

int main(){
  int N, i, j;
  int A[100];

  scanf("%d", &N); //ソートする要素の個数N
  for (i = 0; i < N; i++) scanf("%d", &A[i]); //A[]の値をNの数だけ取り込む

  trace(A,N); // 初期値の出力
  bubbleSort(A,N);

  return 0;
}
