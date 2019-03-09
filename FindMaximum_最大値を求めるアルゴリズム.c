/* 再帰的に最大値を求めるアルゴリズm */

//lからr内(rは含まない)で最大値を求める関数
int findMaximum(A,l,r)(
  m = (l+r)/2; // DIvide
  if(l == r-1)return A[l];
  else{
    u = findMaximum(A,l,m); //左半分
    v = findMaximum(A,m,r); //右半分
    x = max(u,v) // Conquer
  }
  return x;
)
