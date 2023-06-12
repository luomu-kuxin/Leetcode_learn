// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，
// 请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
#include<stdio.h>
#include"uthash.h"



typedef struct Hash_table{
    int id;
    int val;
    UT_hash_handle hh;
}HASH_TABLE;

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    HASH_TABLE *hash = NULL;

    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            int k = nums1[i] + nums2[j];
            HASH_TABLE *s = NULL;
            HASH_FIND_INT(hash, &k, s);
            if(s == NULL){
                s = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
                s->id = k;
                s->val = 1;
                HASH_ADD_INT(hash,id,s);
            }else{
                s->val++;
            }

        }
    }
    int count = 0;

    for(int i = 0; i < nums3Size; i++){
        for(int j = 0; j < nums4Size; j++){
            int k = 0 - (nums3[i] + nums4[j]);
            HASH_TABLE *s = NULL;
            HASH_FIND_INT(hash, &k, s);
            if(s){
                count += s->val;
            }
        }
    }
    return count;
}

// void printnum(int *nums, int size)
// {
//     for(int i = 0; i < size; i++){
//         printf("[%d] ",nums[i]);
//     }
// }

int main(void)
{
    int nums1[2] = {1,2};
    int nums2[2] = {-2,-1};
    int nums3[2] = {-1,2};
    int nums4[2] = {0,2};

    int a = 0;
    a = fourSumCount(nums1,2,nums2,2,nums3,2,nums4,2);
    printf("a = %d\n",a);

    return 0;
}
