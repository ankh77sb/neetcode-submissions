class MyCircularQueue {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int val, ListNode* next = nullptr,
                 ListNode* prev = nullptr) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };

    int maxiSize;
    int currSize;
    ListNode* front;
    ListNode* back;

public:
    MyCircularQueue(int k) {
        maxiSize = k;
        currSize = 0;

        front = new ListNode(0);
        back = new ListNode(0, nullptr, front);

        front->next = back;
    }

    bool enQueue(int value) {
        if(isFull()) return false;

        ListNode* curr =
            new ListNode(value, back, back->prev);

        back->prev->next = curr;
        back->prev = curr;

        currSize++;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;

        ListNode* tmp = front->next;

        front->next = tmp->next;
        front->next->prev = front;

        delete tmp;

        currSize--;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return front->next->val;
    }

    int Rear() {
        if(isEmpty()) return -1;
        return back->prev->val;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == maxiSize;
    }
};