#ifndef Queue2Cpp
#define Queue2Cpp

template <typename T>
class Queue2 {
    private:
        struct Node
        {
            T data;
            Node * next;

            Node(const T & d = T(), Node * n = NULL) : data(d), next(n) {}
        };
        int size;
        Node * front_node;
        Node * last_node;
        void init() {
            size = 0;
            front_node = NULL;
            last_node = NULL;
        }
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
        const_iterator begin() const {
            return const_iterator(front_node);
        }
        const_iterator end() const {
            return const_iterator();
        }
        void clear() {
            if (!empty()) pop();
        }
    public:
        Queue2() {
            init();
        }
        ~Queue2() {
            clear();
        }
        Queue2(const Queue2 & rhs) {
            init();
            *this = rhs;
        }
        const Queue2 & operator=(const Queue2 & rhs) {
            if (this != &rhs) {
                clear();
                const_iterator begin_itr = rhs.begin();
                const_iterator end_itr = rhs.end();
                while(begin_itr != end_itr) {
                    push(*begin_itr++);
                }
            }
            return *this;
        }
    public:
        bool empty() {
            return size == 0;
        }
        void push(const T & x) {
            Node * p = new Node(x, NULL);
            if (!front_node) front_node = p;
            if (last_node) last_node->next = p;
            last_node = p;
            ++size;
        }
        void pop() {
            Node * n = front_node->next;
            delete front_node;
            front_node = n;
            --size;
            if (size == 0) last_node = NULL;
        }
        const T & front() {
            return front_node->data;
        }
};

#endif