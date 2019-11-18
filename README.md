# C_function
私がよくAtCoderでよく使う関数をまとめました。　　
以下、upしたファイルの一つである「general_tree.c」を元に見方を解説します。

##概要
'''C
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
'''
