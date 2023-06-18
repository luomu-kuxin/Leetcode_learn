// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
// 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 。

//需要使用long long 类型转换，leetcode有一些很nc的数据


#include<stdlib.h>
#include<stdio.h>

int cmp(const void * a, const void *b)
{
    return *((int *)a) > *((int *)b);
}



int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int ** ans = (int **)malloc(sizeof(int*) * 1800);
    int s = 0; // 计数

    if(numsSize < 4){
        *returnSize = 0;
        return ans;
    }

    qsort(nums,numsSize,sizeof(int),cmp);

    for(int i = 0; i < numsSize - 3; i++){
        //去重
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        if((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target){break;}
        // if((long long)(nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3]) < target){
        //     continue;
        // }

        

        printf("i = %d\n", i);
        for(int left = i + 1; left < numsSize - 2; left++){
            if(left > i + 1 && nums[left] == nums[left - 1]){
                continue;
            }
            int right = numsSize - 1;
            long long rest = (long long)target -  nums[i] - nums[left];
            int mid = left + 1;
            while (mid < right)
            {
                long long t_sum = (long long)(nums[mid] + nums[right]);
                if(rest == t_sum){
                    int *res = (int*)malloc(sizeof(int) * 4);
                    printf("s= %d ",s);
                    printf("i= %d, ni = %d ",i,nums[i]);
                    printf("l= %d, nl = %d ",left,nums[left]);
                    printf("m= %d, nm = %d ",mid,nums[mid]);
                    printf("r= %d, nr = %d\n",right,nums[right]);
                    res[0] = nums[i];
                    res[1] = nums[left];
                    res[2] = nums[mid];
                    res[3] = nums[right];
                    ans[s++] = res;
                    right--;
                    mid++;
                    while (mid < right && nums[mid] == nums[mid - 1])
                    {
                        mid++;
                    }
                    while((right > mid) &&nums[right] == nums[right + 1] )
                    {
                        right--;
                    }

                }
                if(rest > t_sum){
                    mid++;
                    while (mid < right && nums[mid] == nums[mid - 1])
                    {
                        mid++;
                    }
                }else if(rest < t_sum){
                    right--;
                    while((right > mid) &&nums[right] == nums[right + 1] )
                    {
                        right--;
                    }
                }
                
               
                
                

            }
            
        }
    }
    
    *returnSize = s;
    printf("s = %d \n",s);
    *returnColumnSizes = (int *)malloc(sizeof(int) * s);
    for(int i = 0; i < s; i++){
        (*returnColumnSizes)[i] = 4;
    }
    return ans;

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

    int num[6] = {1,0,-1,0,-2,2};
    int **sum = NULL;
    int size = 0;
    int *csize = NULL;
    sum = fourSum(num,6,0,&size,&csize);
    printsum(sum,size,csize);
    return 0;
}
