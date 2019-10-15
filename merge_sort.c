/*
A[0]~A[N-1]までのint配列を、昇順にマージソートする
問題：AtCoder ABC138-C

(使用例)
入力：
5
500 300 200 800 600
出力： 200 300 500 600 800
*/


/*
使用データ構造
void merge_sort(int* A, int left, int right, int* B)

入力：A[left]~A[right]までの配列,left, right ,ソート時に使う仮の配列スペースB
出力：なし
*/

#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//ソートされたA[left~mid]とA[mid+1~right]をくっつける関数
void merge(int* A, int left, int mid, int right, int* B){
    int i,j,k;
    int tmp;

    //kは一時的な配列Bの現在の添字、iは前半A[left~mid]、jは後半A[mid+1~right]を指す添字
    k=left; i=left; j=mid+1;
    while(k<=right){
        if(j>right) tmp=A[i++]; //前半のみにデータがある
        else if(i>mid) tmp=A[j++]; //後半のみにデータがある
        else if(A[i]<=A[j]) tmp=A[i++]; //前半の方が小さい
        else tmp=A[j++]; //後半の方が小さい

        B[k++]=tmp;
    }
    for(i=left;i<=right;i++) A[i]=B[i]; //元の配列に戻す
}

//A[left]~A[right]までの配列を昇順にマージソートする関数
void merge_sort(int* A, int left, int right, int*B){
    int mid;

    if(left<right){
        mid=(left+right)/2;
        merge_sort(A,left,mid,B); //A[left]~A[mid]までを再帰的にソート
        merge_sort(A,mid+1,right,B); //A[mid+1]~A[right]までを再帰的にソート
        merge(A,left,mid,right,B); //分割した二つをくっつける
    }
}


//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    int N;
    scanf("%d",&N);

    //v[0]~v[N-1]に格納する
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    int* B;
    NEW(B,N);
    merge_sort(A,0,N-1,B);

    for(int i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    free(B);

    return 0;
}