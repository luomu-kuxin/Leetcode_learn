// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

#include<stdlib.h>  //qsort
#include<stdio.h>

int cmp(const void* ptr1, const void* ptr2) {
    return *((int*)ptr1) > *((int*)ptr2);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ** ans = malloc(sizeof(int*) * 18000);
    int s =0;
    if( numsSize < 3){
        *returnSize = 0;
        return ans;
    }

    qsort(nums,numsSize,sizeof(int),cmp);

    
    for(int i = 0; i < numsSize - 2; i++){
        if(nums[i] > 0){
            break;
        }
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum < 0){
              left++;
            }else if(sum > 0){
              right--;
            }else{
              int *res = malloc(sizeof(int) * 3);
              res[0] = nums[i];
              res[1] = nums[left];
              res[2] = nums[right];
              ans[s++] = res;
              //更新左右指针
              
              while(right > left && nums[right] == nums[right - 1])
                  right--;
              while(left < right && nums[left] == nums[left + 1])
                  left++;
              left++;
              right--;
            }
        }
    }
    *returnSize = s;
    *returnColumnSizes = (int *)malloc(sizeof(int) * s);
    for(int z = 0; z < s; z++){
        (*returnColumnSizes)[z] = 3;
    }

    return ans;
}


int** threeSum1(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

}

void printsum(int ** sum, int size, int *ColumSize)
{
    for(int i = 0 ; i < size; i++){
        printf("[ ");
        for(int j = 0; j < ColumSize[i]; j++){
            printf("%d ", sum[i][j]);
        }
        printf(" ]\n");
    }
}

int main(void)
{
    int num[3] = {0,0,0};
    int **sum = NULL;
    int size = 0;
    int *csize = NULL;
    sum = threeSum(num,3,&size,&csize);
    printsum(sum,size,csize);

    return 0;
}
