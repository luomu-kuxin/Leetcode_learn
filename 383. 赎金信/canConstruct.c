// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

#include<stdbool.h>
#include<string.h>
#include<stdio.h>

bool canConstruct(char * ransomNote, char * magazine){

    int cur[200] = {};
    int len_r = strlen(ransomNote);
    int len_m = strlen(magazine);
    
   for(int i = 0; i < len_r; i++){
        cur[(int)ransomNote[i]]++;
   }

    for(int j = 0; j < len_m; j++){
        if(cur[(int)magazine[j]] > 0){
            cur[(int)magazine[j]] --;
        }
    }
    
    for(int i = 0; i < 200; i++){
        if(cur[i] > 0){
            return false;
        }
    }
    return true;

}


int main(void)
{
    char *a  = "aa";
    char *b = "aabb";
    bool s = canConstruct(a,b);
    
    printf("%d",s);

    return 0;
}
