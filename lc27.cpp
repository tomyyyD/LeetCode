#include <cstdio>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        // std::vector<int>::iterator i = nums.begin();
        for (std::vector<int>::iterator i = nums.begin(); i < nums.end(); i++)
        {
            if (*i == val)
            {
                nums.erase(i);
                i--;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;
    std::vector<int> v;
    int arr[8] = {0, 1, 2, 2, 3, 0, 4, 2};
    for (int x : arr)
        v.push_back(x);
    // for (int i = 0; i < 10; i++)
    //     v.push_back(i);
    int r = solution.removeElement(v, 2);
    printf("%d\n", r);
    for (int i = 0; i < v.size(); i++)
        printf("%d\n", *(v.begin() + i));
    return 0;
}