/*
文字列が与えられた時に、同じ要素が続く群列に変換する関数を導入する。
問題：AtCoder ABC140-D

(使用例)
入力：6 LRLRRL
出力：
L 1
R 1
L 1
R 2
L 1
(Lが1個→Rが1個→Lが1個→Rが2個→Lが1個の群列(リスト構造))
*/


/*
使用データ構造
slist array_blocked(char* S, int N)

導入：双方向連結リスト(head, tailあり)(ソートなし)

入力：配列(文字列)　S[0]~S[N-1]
　　　配列に格納されている要素の数　N
出力：リスト+リストの要素数
*/



#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//整数と、リストの次要素を指すポインタをまとめた構造体slobjを定義
typedef struct slobj_{
    char key; //そのブロックの要素が何か
    int sum; //ブロックの中に何個文字があるか
    struct slobj_ *next;
    struct slobj_ *prev;
}*slobj;

//slobj型の変数のポインタをslist型と定義→いずれリストの先頭・最後尾要素を指す
typedef struct{
    slobj head;
    slobj tail;
}*slist;

//keyにc, sumにnを持つリスト要素を作る関数
slobj slobj_new(char c, int n){
    slobj p;
    NEW(p,1);
    p->key=c;
    p->sum=n;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

//slist型の空リスト1つを作る関数
slist slist_new(void){
    slist L;
    NEW(L,1);
    L->head=NULL;
    L->tail=NULL;
    return L;
}

//slobj型の要素pをリストLの最後に挿入する関数
void slist_insert_tail(slist L,slobj p){
    if(L->head==NULL){ //もし最初に挿入するなら
        //p->prev=NULL;
        //p->next=NULL;
        L->head=p;
        L->tail=p;
    }
    else{ //それ以外なら
        p->prev=L->tail;
        //p->next=NULL;
        L->tail->next=p;
        L->tail=p;
    }
    
    return;
}

slist array_blocked(char* S, int N){
    slist L=slist_new();

    char c=S[0]; //ブロックの文字
    int charn=0; //ブロックの中にある文字の数

    for(int i=0;i<N;i++){
        if(S[i]==c){
            charn+=1;
        }
        else{
            slobj p=slobj_new(c, charn);
            slist_insert_tail(L,p);
            c=S[i];
            charn=1;
        }

        if(i==N-1){ //もし最後だったら、それをリストに足す
            slobj p=slobj_new(c, charn);
            slist_insert_tail(L,p);
        }
    }

    return L;
}







//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。

int main(void){
    int N;
    scanf("%d",&N);

    char S[N+1];
    scanf("%s",S); //S[0]~S[N-1]まで文字列、S[N]は0

    slist L=array_blocked(S,N);

    slobj q=L->head;
    while(q!=NULL){
        printf("%c %d\n",q->key, q->sum);
        q=q->next;
    }

    return 0;
}