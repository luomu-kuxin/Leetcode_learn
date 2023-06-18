// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。


#include<stdio.h>
#include<string.h>


void reverseString(char* s, int sSize){
    int le = 0;
    int ri = sSize - 1;
    if(ri < 1)return;
    while (le < ri)
    {
        char tmp = s[le];
        s[le] = s[ri];
        s[ri] = tmp;
        le++;
        ri--;
    }

}



int main(void)
{
    char sr[2] = "ok";    //不能设置为 char * ，否则会无法改变地址。

    int sSize = strlen(sr);


    reverseString(sr,sSize);

    printf("%s",sr);

    return 0;
}