/*
配列A[1]~A[N]が与えられたときに、それを元に
・降順(A[1]が一番大きい)になるようなヒープ木を構成
・最大値抽出 O(1)
・値の追加O (logN)
をする関数を導入する。
問題：AtCoder ABC141-D

(使用例)
なし
*/



/*
使用データ構造
heap heap_build(int n, heapdata* A, int max_size)　BUILD_HEAP
heapdata extract_max(heap H)                       EXTRACT_MAX
void heap_insert(heap H,heapdata x)                INSERT


導入：heapdata型、heap木型

BUILD_HEAP
入力：配列A[1]~A[N], 現在の要素数N, 最大要素数N
出力：ヒープ木

EXTRACT_MAX
入力：ヒープ木
出力：最大要素のpriorityを持つheapdata

INSERT
入力：ヒープ木、heapdata
出力：なし
*/



#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ


#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

//ヒープ木の構成要素型の定義
typedef struct{
    int priority; //ここの値で降順にする！！
    double value;
}heapdata;

//ヒープ木型の定義
typedef struct{
    int max_size;   //ヒープ二分木(配列A)の中に格納できる最大要素数
    int heap_size;  //ヒープ二分木(配列A)の中に現在入っている要素の数
    heapdata* A;    //要素を格納するための配列(ポインタ)
}* heap;

//ヒープH内の配列のA[i]とA[j]の値を入れ替える関数
void heap_swap(heap H,int i,int j){
    heapdata tmp;
    
    tmp=H->A[i];
    H->A[i]=H->A[j];
    H->A[j]=tmp;
    
    return;
}

//HEAPIFY O(nlogn)
//A[i]を根とする部分木がヒープになるように整序する関数
void heapify(heap H, int i){
    int l,r,largest,size;
    heapdata* A;
    
    l=LEFT(i); //iの左の子の添字
    r=RIGHT(i); //iの右の子の添字
    size=H->heap_size; //今のヒープHのサイズ
    A=H->A; //ヒープ二分木に格納されている要素の配列
    
    //以下largestを決めるコード
    if(l>size&&r>size){
        largest=i;
    }
    else if(l<=size&&r>size){
        if(A[l].priority>A[i].priority){
            largest=l;
        }
        else{
            largest=i;
        }
    }
    else{
        if(A[r].priority>A[l].priority){
            largest=r;
        }
        else{
            largest=l;
        }
        if(A[i].priority>A[largest].priority){
            largest=i;
        }
    }
    
    //largestが決まったら要素を入れ替えする
    if(largest!=i){
        heap_swap(H,i,largest);
        heapify(H,largest);
    }
    
    return;
}

//BUILD_HEAP O(n)
//要素n個の配列A[1]~A[n]、max_sizeをもつヒープ木Hのメモリを確保し出力する関数
heap heap_build(int n, heapdata* A, int max_size){
    int i;
    heap H;
    NEW(H,1);
    
    H->max_size=max_size;
    H->heap_size=n;
    H->A=A;
    
    for(i=n/2;i>=1;i--){
        heapify(H,i);
    }
    
    return H;
}

//EXTRACT_MAX O(logn)
//ヒープ木の中の最大要素を削除し出力、その最大要素を除いたヒープ木を再構成する関数
heapdata extract_max(heap H){
    int n=H->heap_size;
    
    heap_swap(H,1,n);
    H->heap_size=n-1;
    heapify(H,1);
    
    return H->A[n];
}

//INSERT O(logn)
//data xをヒープHに挿入する関数
void heap_insert(heap H,heapdata x){
    int n=H->heap_size;
    
    if(n==H->max_size){
        printf("ERROR　cannot insert anymore\n");
        return;
    }
    else{
        H->A[n+1]=x;
        H->heap_size=n+1;
        
        int i=n+1;
        while(PARENT(i)>=1&&H->A[i].priority>H->A[PARENT(i)].priority){
            heap_swap(H,i,PARENT(i));
            i=PARENT(i);
        }
        return;
    }
}

//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
//使用例なしなのでmain関数もなし