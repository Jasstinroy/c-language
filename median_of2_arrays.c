#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, 
                              int* nums2, int nums2Size) {

    // Ensure nums1 is smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int low = 0, high = nums1Size;
    int total = nums1Size + nums2Size;

    while (low <= high) {

        int partition1 = (low + high) / 2;
        int partition2 = (total + 1) / 2 - partition1;

        int maxLeft1  = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == nums1Size) ? INT_MAX : nums1[partition1];

        int maxLeft2  = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == nums2Size) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {

            // If total length is even
            if (total % 2 == 0) {
                int leftMax = (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
                int rightMin = (minRight1 < minRight2) ? minRight1 : minRight2;
                return (leftMax + rightMin) / 2.0;
            }
            // If total length is odd
            else {
                return (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
            }
        }
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        }
        else {
            low = partition1 + 1;
        }
    }

    return 0.0; // should never reach here
}
