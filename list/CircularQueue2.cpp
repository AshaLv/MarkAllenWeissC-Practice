#ifndef CircularQueue2Cpp
#define CircularQueue2Cpp

template <typename T>
class CircularQueue2 {
    private:
        struct Node
        {
            T data;
            Node * next;

            Node(const T & d = T()) : data(d), next(this) {}
        };
        class const_iterator{
            public:
                Node * current;
                const_iterator(Node * p) : current(p) {}
                T & retrieve() {
                    return current->data;
                }
            public:
                const_iterator() : current(NULL) {}
                const_iterator operator++() {
                    current = current->next;
                    return *this;
                }
                const_iterator operator++(int) {
                    const_iterator old = *this;
                    current = current->next;
                    return old;
                }
                bool operator==(const const_iterator & rhs) {
                    return current == rhs.current;
                }
                bool operator!=(const const_iterator & rhs) {
                    return !(*this == rhs);
                }
                const T & operator*() {
                    return retrieve();
                }
        };
        const_iterator last_node_itr;
        void clear() {
            if (!empty()) dequeue();
        }
    public:
        CircularQueue2() {}
        ~CircularQueue2() {
            clear();
        }
        CircularQueue2(const CircularQueue2 & rhs) {
            *this = rhs;
        }
        const CircularQueue2 & operator=(const CircularQueue2 & rhs) {
            if (this != &rhs) {
                clear();
                Node * rhs_last_node = rhs.last_node_itr.current;
                Node * rhs_first_node = rhs_last_node->next;
                while (rhs_first_node != rhs_last_node) {
                    enqueue(rhs_first_node->data);
                    rhs_first_node = rhs_first_node->next;
                }
            }
            return *this;
        }
    public:
        bool empty() {
            if (!last_node_itr.current) return true;
            return false;
        }
        void enqueue(const T & x) {
            Node * p = new Node(x);
            if (empty()) last_node_itr = const_iterator(p);
            else {
                Node * last_node = last_node_itr.current;
                Node * first_node = last_node_itr.current->next;
                p->next = first_node;
                last_node->next = p;
                last_node_itr = const_iterator(p);
            }
        }
        const T dequeue() {
            if (empty()) throw "Exception: Out Of Bounds";
            Node * first_node = last_node_itr.current->next;
            const T d = first_node->data;
            Node * next_first_node = first_node->next;
            Node * last_node = last_node_itr.current;
            if (last_node == first_node) last_node_itr = const_iterator(NULL);
            else{
                last_node->next = next_first_node;
            }
            delete first_node;
            return d;
        }
};

#endif