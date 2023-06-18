// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 // 这么简单? 热死了，大半夜的睡不着写leetcode，无奈了

#include<string.h>
#include<stdio.h>

void revStr(char *s, int sSize){
    int l = 0;
    int r = sSize - 1;
    if(r < 1)return;
    while(l < r){
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

void reStr(char *s, int l, int r){
    if(r <= l)return;

    while(l < r){
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

char * reverseStr(char * s, int k){
    
    int sSize = strlen(s);
    printf("%d\n",sSize);
    if(sSize < k){
        revStr(s,sSize);
        return s;
    }

    int as = sSize % (2 * k);
    printf("as = %d\n",as);
    int i = sSize / (2 * k);
    printf("i = %d\n",i);
    for(int a = 0; a < i; a++){
        reStr(s,(0 + a * 2 * k), (k - 1 + a * 2 * k));
    }
    if(as < k){
        reStr(s,(i * 2 * k + 0),sSize - 1);
    }else{
        reStr(s, (i * 2 * k), k - 1 + i * 2 * k);
    }

    return s;
    
}


int main(void)
{
    char s[7] = "abcdefg";
    // char s[4] = "abcd";
    char *a = reverseStr(s,8);
    printf("%s\n",a);
    return 0;
}
