#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[5] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int tmp = nums[j];
            int next = nums[j + 1];
            if (tmp > next)
            {
                nums[j] = next;
                nums[j + 1] = tmp;
            }
        }

        for (int k = 0; k < 5; k++)
        {
            printf("%i\n", nums[k]);
        }
        printf("---------------\n");
    }
    


}
