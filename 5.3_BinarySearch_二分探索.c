/* BinarySearch_二分探索 */

/*
n個の整数を含む整列S（昇順が前提）と、q個の異なる整数を含む整列Tを読み込み、Tに含まれるものの中で、
Sに含まれるものの個数Cを出力するプログラムを作成する
*/

//////////////////////////////　前処理　/////////////////////////////////////////

#include<stdio.h>

int A[100000], n; // グローバル変数

/////////////////////////////　二分探索　/////////////////////////////////////////

int binarySearch(int key){
  int left = 0;
  int right = n;
  int mid;

  while(left<right){                  //左値が右値より小さい間
    mid = (left + right)/2;           //中央値の再設定
    if(key == A[mid])return 1;        //keyを発券　＞　Trueをかえす
    if(key>A[mid]) left = mid + 1;    //もしkeyが中央値より大きければ、中央値＋１を左値に設定
    else if(key<A[mid])right = mid;   //もしkeyが中央値より小さければ、中央値を右値に設定
  }
  return 0; //見つからない場合
}

/////////////////////////////　メイン関数　/////////////////////////////////////////

int main(){
  int q, k, sum = 0;
  printf("昇順に並べられた整数リストAの要素の数を入力\n");
  scanf("%d",&n);
  for(int i = 0; i<n; i++){
    printf("整数リストを入力")
    scanf("%d",&A[i]);
  }

  printf("整数リストTの要素の数を入力\n");
  scanf("%d",&q);
  for(int i = 0; i<q; i++){
    printf("検討する整数を入力\n");
    scanf("%d", &k);  
    if (binarySearch(k))sum++;
  }
  printf("%d\n",sum);

  return 0;
}


//計算時間　＞　O(logn)