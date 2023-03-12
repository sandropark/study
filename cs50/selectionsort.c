#include <stdio.h>

const int length = 3;

int main(int argc, char const *argv[])
{
    int nums[length] = {3, 1, 2};
    for (int i = 0; i < length; i++)
    {
        int minimum = nums[i];
        int idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (nums[j] < minimum)
            {
                minimum = nums[j];
                idx = j;
            }
        }
        nums[idx] = nums[i];
        nums[i] = minimum;

        for (int k = 0; k < length; k++)
        {
            printf("%i\n", nums[k]);
        }
        printf("---------------\n");
    }
    


}
