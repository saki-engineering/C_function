/*
二分木とは限らない一般の木構造(子がいくつかが決まってない)を記述する
問題：AtCoder ABC138-D

(使用例)
入力：(上記問題の入力例1のグラフ)
4
1 2
2 3
2 4
出力：
node 1 parent null children 2 
node 2 parent 1 children 4 3 
node 3 parent 2 children 
node 4 parent 2 children 
*/


/*
使用データ構造
node* build_tree(int N)

導入：
単方向リスト(未ソート)(headのみ)
(ノードの子を示すのに使用)

入力：木構造のノードの数N
scanf N-1回の、親ノード番号aと子ノード番号bの組み合わせ
出力：nodeの配列tree[1]~tree[n] tree[i]が、ノード番号iの情報
*/

#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//ノード番号と、リストの次要素を指すポインタをまとめた構造体slobjを定義
typedef struct slobj_{
    int n; //ノード番号
    struct slobj_ *next; //次へのポインタ
}*slobj;

//slobj型の変数のポインタをslist型と定義→いずれリストの先頭・最後尾要素を指す
typedef struct{
    slobj head;
}*slist;

//nにiを持つリスト要素を作る関数
slobj slobj_new(int i){
    slobj p;
    NEW(p,1);
    p->n=i;
    p->next=NULL;
    return p;
}

//slist型の空リスト1つを作る関数
slist slist_new(void){
    slist L;
    NEW(L,1);
    L->head=NULL;
    return L;
}

//slobj型の要素pをリストLの最初に挿入する関数
void slist_insert_head(slist L,slobj p){
    if(L->head==NULL){ //もし最初に挿入するなら
        //p->next=NULL;
        L->head=p;
    }
    else{ //それ以外なら
        p->next=L->head;
        L->head=p;
    }
    
    return;
}

//グラフのノード要素
typedef struct node_{
    int i; //ノード番号
    int key; //節点に載せるデータ
    struct node_ *parent; //親ノード
    slist children; //子ノードの番号を格納するリスト
}*node;

//ノード番号m,keyにnをもつ節点要素の作成
node node_new(int m,int n){
    node x;
    NEW(x,1);
    x->i=m;
    x->key=n;
    x->parent=NULL;
    x->children=slist_new();

    return x;
}

//木構造の作成(keyは全部0)
node* build_tree(int N){

    //木構造の作成(keyは全部0)
    node* tree;
    NEW(tree,N+1); //T[i]にノード番号iを格納、範囲はT[1]~T[N]
    for(int i=1;i<=N;i++){
        tree[i]=node_new(i,0);
    }

    //親a,子bの入力
    //木構造なので、枝の数はN-1
    for(int i=1;i<=N-1;i++){
        int a,b;
        scanf("%d %d",&a, &b);

        //もし子a、親bなら入れ替え
        if(a>b){
            int tmp=a;
            a=b;
            b=tmp;
        }

        //親aの子リストにbを追加
        slobj p=slobj_new(b);
        slist_insert_head(tree[a]->children, p);

        //子bの親にaを登録
        tree[b]->parent=tree[a];
    }

    return tree;
}



//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    //節点の数
    int N;
    scanf("%d",&N);

    node* tree=build_tree(N);

    for(int i=1;i<=N;i++){
        if(tree[i]->parent==NULL){
            printf("node %d parent null children ",i);
        }
        else{
            printf("node %d parent %d children ",i, tree[i]->parent->i);
        }

        slobj q=tree[i]->children->head;
        while(q!=NULL){
            printf("%d ",q->n);
            q=q->next;
        }
        printf("\n");
    }

    return 0;
}