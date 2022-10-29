#include <stdio.h>

// 2つの引数を足し算し画面に表示する関数
long func(long num1, long num2)
{
    // 足し算した結果を画面に表示
    printf("%ld\n", num1 + num2);

    return num1 + num2;
}

int main(void)
{
    // 関数ポインタの変数定義
    long (*pfunc)(long, long);

    // ①：直接的な関数呼び出し
    func(100, 200);

    // 照準設定：pfunc --> func関数
    pfunc = func; // 関数名ぶち込む

    // ②：pfuncから関数呼び出し
    pfunc(100, 200);

    return 0;
}