#include <cstdlib>
#include <stdio.h>

struct ListNode {
    // contains
    int val;
    ListNode *next;
    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
// {

// }

int increaseByOne(int x)
{
    return x + 1;
}

int sqaure(int x)
{
    return x * x;
}

// function to create the lists
ListNode* makeList(int length, int(*func)(int))
{
    ListNode *header = (ListNode *)malloc(sizeof(ListNode));
    if (length == 0) return header;

    header -> val = (* func) (0);
    header -> next = nullptr;
    ListNode *a = header;

    for (int i = 1; i < length; i ++)
    {
        ListNode *b = (ListNode *)malloc(sizeof(ListNode));
        b -> val = (* func)(i);
        a -> next = b;
        a = b;
    }
    return header;
}

int main()
{
    int (*f)(int);
    int (*g)(int);
    f = &increaseByOne;
    g = &sqaure;

    ListNode *l1 = makeList(5, f);
    ListNode *l2 = makeList(5, g);
    while (l1 != nullptr){
        printf("%d, ", l1 -> val);
        ListNode *temp = l1 -> next;
        free(l1);
        l1 = temp;
    }
    printf("\n");
    while (l2 != nullptr){
        printf("%d, ", l2 -> val);
        ListNode *temp = l2 -> next;
        free(l2);
        l2 = temp;
    }
    printf("\n");
    return 0;
}