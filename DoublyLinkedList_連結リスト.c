/* DoublyLinkedList_連結リスト */
//双方向リスト

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
  int key;
struct Node *next,*prev;
}Node;

Node *nil; // 蛮兵(実データには含めない)リストの先頭をさす

Node* listSearch(int key){
  Node *cur = nil->next; //curは蛮兵の次のリスト○●○
  while (cur != nil && cur->key != key){
    cur = cur->next; //curはcurのnext ○○●
  }
  return cur;
}

//初期化
void init(){
  //サイズを確保する
  nil = (Node*)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  Node *cur = nil->next; //nilのnextから始まる(スタック的にprintされる)
  int isf = 0;
  while(1){ //無限ループ
    if (cur == nil)break; //一周してnilに戻った時点で終了
    if(isf++ > 0)printf(" ");
    printf("%d", cur->key); //現在のデータ本体key
    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node *t){
  if(t == nil)return; //tが蛮兵の場合は処理しない
  t->prev->next = t->next;
  t->next->prev = t->prev; //つなぎ合わせている。
  free(t);
}

void deleteFirst(){
  deleteNode(nil->next);
}

void deleteLast(){
  deleteNode(nil->prev);
}

void deleteKey(int key){
  deleteNode(listSearch(key));
}

void insert(int key){
  Node *x = (Node*)malloc(sizeof(Node)); // 追加用のメモリを確保
  x->key = key; // keyの設定
  //nilの直後に追加。
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0;
  int nd = 0;

  scanf("%d",&n);
  init(); //初期化
  for (i = 0; i < n; i++){
    scanf("%s%d", com ,&key); //command
    if(com[0] == 'i'){insert(key);np++;size++;} // ようはinsert
    else if (com[0] == 'd'){
      if (strlen(com) > 6){ //文字の長さでどのdeleteなのかを分類
        if(com[6]=='F')deleteFirst();
        else if (com[6]=='L')deleteLast();
      }else{
        deleteKey(key); nd++;
      }
      size--;
    }
  }

  printList();

  return 0;
}
