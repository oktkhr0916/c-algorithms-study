/*　MiniMax法　*/



int mini_max(盤面, int lv)
{
  int val, max;

  if(lv == 0)return 評価値(盤面);

  if(先手)max = -∞;
  else max = ∞;

  while(打てる手がある){
    手を差して次の盤面を作る;
    val = mini_max(盤面, lv - 1);
    盤面を１手戻す;
    if(先手){
      if(max < val)max = val;
    }
    else{
      if(max > val)max = val;
    }
  }
  return max;
}

/depth == 0を先手として考える。
int mini_max(盤面、int 0){
  int val,max
  if(depth == 0)return val

  if(depth%2 == 0 or depth == 0)max = maximum //最大値をとる
  if(depth%2 == 1 or depth == 1)min = minimum //最小値を選ぶ

  for(すべての子ノードの対して){
    val = minimax(盤面、int d-1)
  }
}

mini-max
深さ優先探索で実装（スタックを利用）
深さで先手後手を判断
入れ替え

ab
最小値より大きな値が見つかったら終了。