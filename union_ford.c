#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int parent;
    long size; //根だったらその木のサイズを表す
}node;

//union-ford木のメモリを確保→初期化して出力(0からカウント)
node* build_union_ford(int N){
    node* T;
    NEW(T,N);
 
    //T[i]には、節iの親を入れる
    for(int i=0;i<N;i++){
        T[i].parent=i;
        T[i].size=1;
    }
    return T;
}
 
//節xを含む部分木の根を返す
int find_set(node* T, int x){
    if(T[x].parent==x){
        return x;
    }
    else{
        return T[x].parent=find_set(T,T[x].parent);
    }
}
 
//節xを含む部分木と節yを含む部分木を併合する
void union_set(node* T,int x, int y){
    x=find_set(T,x);
    y=find_set(T,y);
 
    if(x==y) return;
    else{
        T[x].parent=y;
        T[y].size+=T[x].size;
        return;
    }
}