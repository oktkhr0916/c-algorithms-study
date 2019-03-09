/* Maximu_Profit */

#include<stdio.h>
#include<math.h>

#define MAX 200000

int main(){
  int n,i ;
  int R[MAX];

  scanf("%d", &n );
  for( i = 0; i < n; i++ ){scanf("%d",&R[i]);}

  int maxv = -2000000000; //十分小さい値を初期値に設定
  int minv = R[0];

  for( i = 0; i < n; i++ ){
    maxv = fmax(maxv, R[i] - minv); //最大値を更新
    minv = fmin(minv, R[i]); //ここまでの最小値を保存しておく
  }

  printf("%d",maxv);

  return 0;
}
