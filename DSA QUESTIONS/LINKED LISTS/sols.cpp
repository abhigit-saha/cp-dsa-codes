struct LinkedListNode
{
    int val;
    LinkedListNode *next;
    LinkedListNode(int val) : val(val), next(nullptr) {}
};

// cycle
bool linkedListCycle(LinkedListNode *head)
{
    LinkedListNode *slow = head;
    LinkedListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast != nullptr && fast == slow)
        {
            return true;
        }
    }
    return false;
}

// kth node from the end
LinkedListNode *kthNodeFromEnd(LinkedListNode *head, int k)
{
    LinkedListNode *forward = head;
    LinkedListNode *backward = head;
    while (k-- && forward != nullptr)
    {
        forward = forward->next;
    }
    if (forward == nullptr && k)
    {
        return;
    }

    while (forward != nullptr)
    {
        forward = forward->next;
        backward = backward->next;
    }

    return backward;
}

// delete duplicates from sorted linked list
LinkedListNode *removedLL(LinkedListNode *head)
{
    LinkedListNode *backward = head;
    LinkedListNode *forward = head->next;
    if (backward = nullptr)
    {
        return;
    }
    while (forward != nullptr)
    {
        if (forward->val == backward->val)
        {
            backward->next = forward->next;
            forward = forward->next;
        }
        else
        {
            backward = backward->next;
            forward = forward->next;
        }
    }

    return head;
}

LinkedListNode *reverse(LinkedListNode *head)
{
    LinkedListNode *prev = nullptr;
    LinkedListNode *curr = head;
    while (curr != nullptr)
    {
        LinkedListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

LinkedListNode *swapPairs(LinkedListNode *head)
{
    LinkedListNode *prev = head;
    LinkedListNode *curr = head->next;
    LinkedListNode *start = head->next;
    if (prev == nullptr || curr == nullptr)
    {
        return head;
    }
    while (curr != nullptr && prev != nullptr)
    {
        LinkedListNode *nextNode = curr->next;
        curr->next = prev;
        prev->next = nextNode;
        curr = nextNode->next;
        if (curr != nullptr)
        {
            prev->next = curr;
        }
        prev = nextNode;
    }

    return start;
}

// reverse a linked list from l to r
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    // first get the node at the left index.
    ListNode *dummy = head->next;
    ListNode *prevDummy = head;
    if (dummy == nullptr)
    {
        return head;
    }

    // dummy is the element at the left index
    while (left - 1 != 0 && dummy != nullptr)
    {
        dummy = dummy->next;
        prevDummy = prevDummy->next;
        left--;
    }

    if (left > 1 && dummy == nullptr)
        return head;

    // reference to the original place of the dummy node.
    ListNode *dummyRef = dummy;
    // previous element to the dummy node's next element is set to before the start of the reversed
    // array which has right-left+1 reversed elements.
    // this is the method to reverse k elements of the array from the start.
    ListNode *prev = nullptr;
    ListNode *curr = dummy;
    int k = right - left;
    while (curr != nullptr && k--)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        if (k == 1)
            dummyRef->next = nextNode; // dummyRef is the original start of the array that
        // was to be reversed. However, now it has become the end of the reversed array
        // so we set its next to the nextNode, which is just after the reversed elements.
    }
    prevDummy->next = prev;

    // diagram. a->b->c->d->e(left = 2, right = 4)
    // a d->c->b e //in the last step of reversing a d->c->b->e(e  is the nextNode in this case)
    // a->d->c->b->e

    return head;

    // please work dude
}
// correct solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// slightly changed solution for testing purposes (thanks btw)
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head; // No need to reverse if left == right

        ListNode dummy(0); // Create a dummy node to handle case where left = 1
        dummy.next = head;
        ListNode *prevDummy = &dummy;
        ListNode *curr = head;

        // Move to the node just before the left position
        for (int i = 1; i < left; i++)
        {
            prevDummy = prevDummy->next;
            curr = curr->next;
        }

        ListNode *start = curr; // Remember the start of the sublist to be reversed
        ListNode *prev = nullptr;

        // Reverse the sublist
        for (int i = 0; i <= right - left; i++)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect the reversed sublist back to the main list
        prevDummy->next = prev;
        start->next = curr;

        return dummy.next;
    }
};