void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Step 1: find first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = numsSize - 1;

        // Step 2: find element just greater than nums[i]
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Step 3: swap
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Step 4: reverse remaining part
    reverse(nums, i + 1, numsSize - 1);
}
