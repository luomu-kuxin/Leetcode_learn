//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

#include<stdbool.h>
#include<stdio.h>
#include<string.h>

// #define true 1
// #define false 0
bool isAnagram(char * s, char * t){
    int lens = strlen(s), lent = strlen(t);
    if(lens != lent)return false;
    int table[26];
    memset(table,0,sizeof(table));
    for(int i = 0; i < lens; ++i){
        table[s[i] - 'a']++;
    }
    for(int i = 0; i < lent; ++i){
        table[t[i] - 'a']--;
        if(table[i] < 0){
            return  false;
        }
    }
    return true;
    
}


int main(void)
{
    char *s = "anagram";
    char *t = "nagaram";
    bool k = isAnagram(s,t);
    printf("%d",k);
    return 0;
}
  