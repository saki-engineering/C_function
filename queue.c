/*
単方向リスト構造でqueueを実装
問題：AtCoder ABC88-D


導入：リスト構造体obj, キュー(リスト)

obj obj_new(int x)
→キューに入る構造体(keyがx)の作成

queue queue_new(void)
void enqueue(queue Q,obj p)
→特筆事項なし

obj dequeue(queue Q)
→キューが空なら、NULLを出力する

入力：配列(文字列)　S[0]~S[N-1]、　文字列長さN, ブロック中の要素数を格納する配列A
出力：なし
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct obj_{
    int key;
    struct obj_ *next;
}*obj;

//slobj型の変数のポインタをslist型と定義→いずれリストの先頭・最後尾要素を指す
typedef struct{
    obj head;
    obj tail;
}*queue;

//keyにxをもつキュー要素を作る関数
obj obj_new(int x){
    obj p;
    NEW(p,1);
    p->key=x;
    p->next=NULL;
    return p;
}

//slist型の空リスト1つを作る関数
queue queue_new(void){
    queue Q;
    NEW(Q,1);
    Q->head=NULL;
    Q->tail=NULL;
    return Q;
}

//enqueue(リスト最後尾に挿入)
void enqueue(queue Q,obj p){
    if(Q->head==NULL){
        Q->head=p;
        Q->tail=p;
    }
    else{
        Q->tail->next=p;
        Q->tail=p;
    }
    
    return;
}

obj dequeue(queue Q){
    obj p=Q->head;
    if(p==Q->tail){
        Q->tail=NULL;
        Q->head=NULL;
    }
    else{
        Q->head=p->next;
    }
    return p;
}