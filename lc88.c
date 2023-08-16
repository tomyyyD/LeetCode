/*
Solution
================================================================================
*/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int *tempn1 = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        tempn1[i] = nums1[i];
    int index = 0;
    int i1 = 0;
    int i2 = 0;
    while (i1 < m && i2 < n)
    {
        if (tempn1[i1] < nums2[i2])
        {
            nums1[index] = tempn1[i1];
            i1++;
        }
        else
        {
            nums1[index] = nums2[i2];
            i2++;
        }
        index++;
    }
}

/*
Testing
================================================================================
*/

int main()
{
    const int m = 3;
    const int n = 3;
    const int n_m = n + m;
    int n1[n_m] = {1, 2, 3, 0, 0, 0};
    int n2[n] = {2, 5, 6};
    int *nums1 = malloc(sizeof(int) * 6);
    int *nums2 = malloc(sizeof(int) * 3);
    for (int i = 0; i < 6; i++)
        nums1[i] = n1[i];
    for (int i = 0; i < 3; i++)
        nums2[i] = n2[i];
    merge(nums1, n_m, m, nums2, n, n);
    return 0;
}