#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename E>
//interfaz que determina que características debe tener un priority queue
class PriorityQueue{
private:
    void operator =(const PriorityQueue<E>& obj) {}
    PriorityQueue(const PriorityQueue<E>& obj) {}

public:
    PriorityQueue() {}
    virtual ~PriorityQueue() {}
    virtual void insert(E element, int priority) = 0;
    virtual E min() = 0;
    virtual E removeMin() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

#endif // PRIORITYQUEUE_H
