/*
パスカルの三角形をDPで求める
問題：AtCoder ABC132-D

(使用例)
入力：5
出力：
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
*/


/*
使用データ構造
void build_pascals_triangle(matrix C, int N)

導入：vector型(intポインタ), matrix型(vectorポインタ)

入力：int
出力：なし
*/



#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//ベクトル型、マトリックス型を導入
typedef int* vector;
typedef vector* matrix;

//v[0]~v[c-1]の添字のものを作る(初期値0)
vector create_vector(int c){
    vector v;
    NEW(v,c);
    for(int i=0;i<c;i++){
        v[i]=0;
    }
    return v;
}

//M[0][0]-M[0][c-1]-M[b-1][0]-M[b-1][c-1]の添字のものを作る
matrix create_matrix(int b, int c){
    matrix M;
    NEW(M,b);
    for(int i=0;i<b;i++){
        M[i]=create_vector(c);
    }
    return M;
}

//0C0〜N_C_Nまでのパスカルの三角形を作る(CはC[0][0]~C[N][N]のmatrix型のメモリ確保済み)
void build_pascals_triangle(matrix C, int N){
    //初期値にC[i][0]とC[i][i]を入れる
    for(int i=0;i<=N;i++){
        C[i][0]=1;
        C[i][i]=1;
    }

    //iCjをDPで入れる
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    return;
}


//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    int N;
    scanf("%d",&N);

    matrix C = create_matrix(N+1,N+1);

    build_pascals_triangle(C,N);

    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}