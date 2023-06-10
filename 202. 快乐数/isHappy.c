// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」 定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

// pow --> math.h ; 用于算幂

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int getsum(int n){
    int sum = 0;
    while(n){
        sum += (int)pow(n%10,2);
        n = (int)(n/10);
    }
    return sum;
}

bool isHappy(int n){
    int hashlist[1000] = {0};
    int sum = 0;
    sum = getsum(n);
    while(sum != 1){
        if(hashlist[sum] != 1){
            hashlist[sum] = 1;
        }else{
            return false;
        }
        sum = getsum(sum);
    }
    return true;
}

// #define true 1
// #define false 0
int main(void)
{
    int n = 19;
    bool s = isHappy(n);
    printf("%d is %d",n,s);
    return 0;
}
