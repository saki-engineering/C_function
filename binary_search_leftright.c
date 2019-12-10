/*
昇順配列(仕様はデータ構造の欄を参照)の中で、keyより初めて大きくなる添字を出力→right
                                                小さく            →left
問題：AtCoder ABC119-D

(使用例)
right
入力：
6 8
1 3 5 7 9 11
出力：
5
(配列の中で初めて8を超えるのは、添字5番の9)

left
入力：
6 8
1 3 5 7 9 11
出力：
4
(配列の中で8を超えないギリギリのは、添字4番の7)
*/


/*
使用データ構造
int binary_search_right(long* array,int min, int max, long key)


入力：long配列(昇順、array[0]はマイナス無限大、array[N+1]は無限大),添字の範囲min~max(0~N+1),比較したい値
出力：int
*/



#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//配列sの中で、keyより初めて大きくなる添字を出力(そのようなものがないなら、max+1を出力)
int binary_search_right(long* array,int min, int max, long key){
    if(min<max){
        int mid=min+(max-min)/2;

        if(key<=array[mid]) return binary_search_right(array,min,mid,key);
        else if(key>array[mid]) return binary_search_right(array,mid+1,max,key);
    }
    if(key>=array[min]) return min+1;
    return min;
}

//配列sの中で、keyより初めて小さくなる添字を出力
int binary_search_left(long* array,int min, int max, long key){
    if(min<max){
        int mid=min+(max-min)/2;

        if(key<=array[mid]) return binary_search_left(array,min,mid,key);
        else if(key>array[mid]) return binary_search_left(array,mid+1,max,key);
    }
    if(key>array[min]) return min;
    return min-1;
}

//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    int N;
    long key;
    scanf("%d%ld",&N,&key);

    long INF = 1e18;

    long* array;
    NEW(array,N+2);
    for(int i=1;i<=N;i++){
        scanf("%ld",&array[i]);
    }
    array[0]=-INF;
    array[N+1]=INF;

    int left=binary_search_left(array,0,N+1,key);
    int right=binary_search_right(array,0,N+1,key);
    printf("%d %d\n",left, right);

}