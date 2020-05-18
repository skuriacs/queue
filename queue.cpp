#define CAPACITY 3
#include <iostream>
#include <bits/stdc++.h>
class CircularArrayQueue
{
private:
    struct node
    {
        int val;
        node *next;
        node(int v)
        {
            val = v;
            next = nullptr;
        }
    };
    node *front;
    node *back;
    int cap = CAPACITY;
    int size = 0;

public:
    CircularArrayQueue();
    bool isEmpty() const;
    void enqueue(int x);
    void dequeue();
    int peekFront() const;
    void print();
};

CircularArrayQueue::CircularArrayQueue()
{
    front = nullptr;
    back = nullptr;
}

bool CircularArrayQueue::isEmpty() const
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}

void CircularArrayQueue::enqueue(int x)
{
    if (front == nullptr)
    {
        front = new node(x);
        back = front;
        size++;
        return;
    }
    node *temp = front;
    for (int i = 0; i < size - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = new node(x);
    back = temp->next;
    size++;
    size = size % cap;
}

void CircularArrayQueue::dequeue()
{
    node *temp = front;
    temp = temp->next;
    delete front;
    front = temp;
    size--;
    size = size % cap;
}

int CircularArrayQueue::peekFront() const
{
    return front->val;
}

void CircularArrayQueue::print()
{
    node *temp = front;
    while (temp != nullptr)
    {
        std::cout << temp->val;
        temp = temp->next;
    }
}
bool checkValidity(std::queue<int> q)
{
    int last = -2147483648;
    while (!q.empty())
    {
        if (q.front() < last)
            return false;
        last = q.front();
        q.pop();
    }
    return true;
}
int main()
{
    CircularArrayQueue queue;
    queue.enqueue(5);
    queue.enqueue(18);
    queue.enqueue(11);
    queue.enqueue(15);
    queue.print();
}