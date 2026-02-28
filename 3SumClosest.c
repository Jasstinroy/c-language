#include <stdio.h>
#include <stdlib.h>
#include <math.h>>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return currentSum;  // Exact match
            }
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Closest Sum: %d\n", threeSumClosest(nums, size, target));

    return 0;
}
