#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end();)
        {
            if (*i == val)
                nums.erase(i);
            i++;
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    int r = solution.removeElement(v, 3);
    printf("%d\n", r);
    for (int i = 0; i < v.size(); i++)
        printf("%d\n", *(v.begin() + i));
    return 0;
}