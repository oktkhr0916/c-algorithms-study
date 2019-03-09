/* MergeSort(マージソート) */

/*

n個の整数を含む数列Sをマージソートで昇順に整列するプログラムを作成
mergeにおける比較回数の総数を報告

入力:
    1　>　１つの整数n
    2　>　S[]を表すn個の整数

出力:
    1　>　整列済みの数列S
    2　>　比較回数
*/


/*//////////////////////////////前処理/////////////////////////////////////////*/


#include<stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

/*//////////////////////////////マージソート/////////////////////////////////////////*/

void merge(int A[], int n, int left, int mid, int right){
  int n1 = mid - left;                          //左半分
  int n2 = right - mid;                         //右半分
  for(int i = 0; i<n1; i++){L[i] = A[left+i];}  //一時的に左半分のリストを作成する
  for(int i = 0; i<n2; i++){R[i] = A[mid+i];}   //一時的に右半分のリストを作成する
  L[n1]=SENTINEL;                               // Lの最後の要素
  R[n2]=SENTINEL;                               // Rの最後の要素
  int i = 0,j = 0;
  for(int k =left; k<right; k++){               //leftからrightのインデックスの値まで
    cnt++;                                      //meregeの回数を追加
    if(L[i]<=R[j]){                             //小さい方から順にA[left]から順番に値を加えていく
      A[k] = L[i++];                            //L[i]と定義し、その後に+1
    }else{
      A[k] = R[j++];
    }
  }
}

//要素が二つになるまで分割した後、昇順で統合し、再帰的にA[]を編集していく。
void mergeSort(int A[], int n, int left, int right){      //  リストを左右に分割している。
  if(left+1 < right){                                     //　（リストの数）＞２　の時
    int mid = (left + right)/2;                           //  中央値の計算
    mergeSort(A,n,left,mid);                              //  左側でマージソート
    mergeSort(A,n,mid,right);                             //  右側でマージソート
    merge(A,n,left,mid,right);                            //  最下層まで行ったら
  }
}

/*//////////////////////////////メイン関数/////////////////////////////////////////*/

int main(){
  int A[MAX];        //リストの因数渡しは、参照渡し
  int  n;            // n : リストの数
  cnt = 0;           //初期化

  printf("配列の数を入力\n");
  scanf("%d",&n);
  for(int i=0; i<n; i++)scanf("%d", &A[i]);

  mergeSort(A,n,0,n);

  for (int i = 0; i < n; i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("\n%d\n",cnt);

  return 0;
}

/*/////////////////////////////考察/////////////////////////////////////*/

//  階層は(logn)で求められる。
//  各階層の計算量は(n):　nの分割数は違えど、nの数だけ、比較と追加が行われる。
//  よって計算量は（nlogn）
