#ifndef CircularQueueCpp
#define CircularQueueCpp
#define CircularQueueSize 4

template <typename T>
class CircularQueue {
    private:
        T objects[CircularQueueSize];
        int front;
        int back;
        int size;
        int valid_index(int index) {
            return index % CircularQueueSize;
        } 
    public:
        CircularQueue() : front(0), back(-1), size(0) {}
        bool full() {
            return size == CircularQueueSize;
        }
        bool empty() {
            return size == 0;
        }
        void enqueue(const T & x) {
            if (full()) throw "Exception: Out Of Bounds";
            objects[valid_index(++back)] = x;
            ++size;
        }
        const T & dequeue() {
            if (empty()) throw "Exception: Out Of Bounds";
            int front_copy = front;
            front = valid_index(++front);
            --size;
            return objects[front_copy];
        }
};

#endif