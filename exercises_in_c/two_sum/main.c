#include <stdio.h>
#include <stdlib.h>

int *twoSum( int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *returnArray;
    int i, j;
    
    returnArray = (int*)malloc(sizeof(int) * 2);

    for(i = 0; i < numsSize; i++)
    {
        for(j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
            }
        }
    }

    return returnArray;
}
int main()
{
    int nums[4] = {2,7,11,15};
    int* bos;



}