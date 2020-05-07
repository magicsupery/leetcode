#include <vector>
using namespace std;
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) :
    head_(-1),
    tail_(-1),
    size_(k)
    {
        vec_.reserve(k);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;

        if(isEmpty())
        {
            vec_[0] = value;
            head_ = 0;
            tail_ = 0;
        }
        else
        {
            tail_ = (tail_ + 1) % size_;
            vec_[tail_] = value;
        }

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;

        if(head_ == tail_)
        {
            head_ = -1;
            tail_ = -1;
        }
        else
        {
            head_ = (head_ + 1) % size_;
        }

        return true;

    }

    /** Get the front item from the queue. */
    int Front() {
        return head_ == -1? -1 : vec_[head_];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return tail_ == -1? -1 : vec_[tail_];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head_ == -1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head_ == -1 ? false:
               ((((tail_ - head_) % size_) + size_) % size_ + 1) == size_;
    }

private:
    int head_;
    int tail_;
    int size_;
    std::vector<int> vec_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    MyCircularQueue q(4) ;

    q.enQueue(3);
    q.enQueue(7);
    q.enQueue(2);
    q.enQueue(5);

    q.deQueue();
    q.enQueue(4);
    q.enQueue(2);
}