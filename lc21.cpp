#include <cstdlib>
#include <stdio.h>

struct ListNode
{
    // contains
    int val;
    ListNode *next;
    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    ListNode *lastchecked = list2;
    if (head2 == nullptr)
        return head1;
    if (head1 == nullptr)
        return head2;
    ListNode *start = (head1->val <= head2->val) ? head1 : head2;
    while (head1 != nullptr)
    {
        if (head1->val <= head2->val)
        {
            if (lastchecked != nullptr)
                lastchecked->next = head1;
            lastchecked = head1;
            head1 = head1->next;
            lastchecked->next = head2;
        }
        else
        {
            if (head2->next == nullptr)
            {
                // getting here means least element in the list made by head1 is
                // greater than greatest element in the current made by head2.
                head2->next = head1;
                break;
            }
            else
            {
                head2 = head2->next;
                lastchecked = head2;
            }
        }
    }
}

/*
Testing functions
================================================================================
*/

int increaseByOne(int x)
{
    return x + 1;
}

int sqaure(int x)
{
    return x * x;
}

// function to create the lists
ListNode *makeList(int length, int (*func)(int))
{
    ListNode *header = (ListNode *)malloc(sizeof(ListNode));
    if (length == 0)
        return header;

    header->val = (*func)(0);
    header->next = nullptr;
    ListNode *a = header;

    for (int i = 1; i < length; i++)
    {
        ListNode *b = (ListNode *)malloc(sizeof(ListNode));
        b->val = (*func)(i);
        a->next = b;
        a = b;
    }
    return header;
}

void printList(ListNode *list)
{
    // print nullpty terminated list
    while (list != nullptr)
    {
        printf("%d", list->val);
        list = list->next;
    }
}

int main()
{
    int (*f)(int);
    int (*g)(int);
    f = &increaseByOne;
    g = &sqaure;

    ListNode *l1 = makeList(5, f);
    ListNode *l2 = makeList(5, g);
    while (l1 != nullptr)
    {
        printf("%d, ", l1->val);
        ListNode *temp = l1->next;
        free(l1);
        l1 = temp;
    }
    printf("\n");
    while (l2 != nullptr)
    {
        printf("%d, ", l2->val);
        ListNode *temp = l2->next;
        free(l2);
        l2 = temp;
    }

    ListNode *merged = mergeTwoLists(l1, l2);
    printf("\n");
    return 0;
}
