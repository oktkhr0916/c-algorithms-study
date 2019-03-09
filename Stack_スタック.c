/* Stack(スタック) */

#include<stdio.h>  //入出力
#include<stdlib.h> //一般ユーティリティ
#include<string.h> //文字列操作

int top, S[1000];

void push(int x){
/*topを加算してその位置へ挿入*/
S[++top] = x;
}

int pop(){
  top--;
  /*topがさして飯田要素を返す*/
  return S[top+1];
}

int main(){
  int a, b; //初期化
  top = 0; //初期化、宣言
  char s[100];
  while (scanf("%s",s) != EOF){ //winでは、ctrl + Z でEOF,Macではctrl + D
    if(s[0]=='+'){
      a=pop();
      b=pop();
      push(a+b);
    }else if(s[0] == '-'){
      b = pop();
      a = pop();
      push(a-b);
    }else if(s[0] == '*'){
      b = pop();
      a = pop();
      push(a*b);
    }else{
      push (atoi(s)); //入力された文字列をint型の数値にしてスタックに挿入している。

    }
  }

  printf("%d\n",pop());
  return 0;
}
