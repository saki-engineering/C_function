/*
昇順配列(仕様はデータ構造の欄を参照)の中で、key以上になる最小の添字を出力→right
                                    　　 以下     最大          →left
問題：AtCoder ABC119-D,ABC77-C

(使用例)
left
//A[6] = {1,3,5,7,9,11};
//key 12なら5
//key 0なら-1
//key 5なら2
//A[6] = {3,3,3,3,3,3};
//key 3なら5

right
//A[6] = {1,3,5,7,9,11};
//key 12なら6
//key 0なら0
//key 5なら2
//A[6] = {3,3,3,3,3,3};
//key 3なら0
*/



#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//rightでは(初めて以上になる添字を0始まりで出力)
//(もしそういうのがないならNを出力)
int binary_search_right(int* array, int N, int key){
    int i=0;
    int low=0;
    int high=N-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(array[mid]<key){
            low=mid+1;
            i=mid+1;
        }
        else{
            high=mid-1;
            i=mid;
        }
    }
    return i;
}

//(以下になる添字の中で一番でかいものを0始まりで出力)
//(もしそういうのがないなら-1を出力)
int binary_search_left(int* array, int N, int key){
    int i=0;
    int low=0;
    int high=N-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(array[mid]<=key){
            low=mid+1;
            i=mid+1;
        }
        else{
            high=mid-1;
            i=mid;
        }
    }
    return i-1;
}