#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    // 9 4 2 1
    int index;
    int start = 0, finish = numsSize - 1;
    index = numsSize / 2;

    do
    {
        
        if (nums[index] == target)
            return index;
        else if (nums[index] > target) //  1 2 3 4 5 6 7 8 9
        {                              //  0 1 2 3 4 5 6 7 8 start 4 index = 6 finish 6
            finish = index - 1;
            index = (finish + start) / 2;
        }
        else if (target > nums[index])
        {
            start = index + 1;
            index = (finish + start) / 2;
        }
    } while (finish - start >= 0);

    return -1;
}

int main()
{                                    //0 1 2 3 4 5 
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,16,161, 167, 184,203, 435, 657, 789, 908}; //  -1 0 3 5 9 12
    printf("\n\n%d\n\n", search(nums, 24, 1));
}
