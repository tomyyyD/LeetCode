#include <stdio.h>

double recursiveMedianFind(int *nums1, int start1, int end1, int *nums2, int start2, int end2, int k)
{
    if (end1 < start1)
    {
        return nums2[k - start1];
    }
    if (end2 < start2)
    {
        return nums1[k - start2];
    }

    int med1Index = (end1 + start1) / 2;
    int nums1Med = nums1[med1Index];

    int med2Index = (end2 + start2) / 2;
    int nums2Med = nums2[med2Index];

    int length = (end1 - start1) + (end2 - start2);
    if (k > med1Index + med2Index)
    {
        // K-th element has to be in the right half of combined array
        // we can remove left half of array with smaller median.
        // We also need to decrease K as elements have essentially shifted left
        if (nums1Med < nums2Med)
            return recursiveMedianFind(nums1, med1Index + 1, end1, nums2, start2, end2, k);
        else
            return recursiveMedianFind(nums1, start1, end1, nums2, med2Index + 1, end2, k);
    }
    else
    {
        // K-th element has to be in the left half of combined array
        // we can remove right half of array with larger median
        // do not need to modify K
        if (nums1Med > nums2Med)
            return recursiveMedianFind(nums1, start1, med1Index - 1, nums2, start2, end2, k);
        else
            return recursiveMedianFind(nums1, start1, end1, nums2, start2, med2Index - 1, k);
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{

    if ((nums1Size + nums2Size) & 1)
        return recursiveMedianFind(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, (nums2Size + nums1Size) / 2);
    else
        return ((recursiveMedianFind(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, (nums2Size + nums1Size) / 2) +
                 recursiveMedianFind(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, ((nums2Size + nums1Size) / 2) - 1)) /
                2);
}

int main()
{
    int nums1[2] = {1, 3};
    int nums2[1] = {2};
    printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 1));
    int nums3[2] = {1, 2};
    int nums4[2] = {3, 4};
    printf("%f\n", findMedianSortedArrays(nums3, 2, nums4, 2));
    int nums5[3] = {1, 2, 9};
    int nums6[2] = {3, 4};
    printf("%f\n", findMedianSortedArrays(nums5, 3, nums6, 2));
    return 0;
}