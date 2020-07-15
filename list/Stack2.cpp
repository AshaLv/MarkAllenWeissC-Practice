#ifndef Stack2Cpp
#define Stack2Cpp

template <typename T>
class Stack2 {
    private:
        struct Node
        {
            T data;
            Node * next;

            Node(const T & d = T(), Node * n = NULL) : data(d), next(n) {}
        };
        int size;
        Node * top_node;
        void init() {
            size = 0;
            top_node = NULL;
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
            return const_iterator(top_node);
        }
        const_iterator end() const {
            return const_iterator();
        }
        void clear() {
            if (!empty()) pop();
        }
    public:
        Stack2() {
            init();
        }
        ~Stack2() {
            clear();
        }
        Stack2(const Stack2 & rhs) {
            init();
            *this = rhs;
        }
        const Stack2 & operator=(const Stack2 & rhs) {
            if (this != &rhs) {
                clear();
                const_iterator begin_itr = rhs.begin();
                const_iterator end_itr = rhs.end();
                top_node = new Node(rhs.top_node->data, NULL);
                Node * p = top_node;
                ++begin_itr;
                while(begin_itr != end_itr) {
                    p->next = begin_itr.current;
                    p = begin_itr.current;
                    ++begin_itr;
                }
            }
            return *this;
        }
    public:
        bool empty() {
            return size == 0;
        }
        void push(const T & x) {
            Node * p = new Node(x, top_node);
            top_node = p;
            ++size;
        }
        void pop() {
            Node * p = top_node->next;
            delete top_node;
            top_node = p;
            --size;
        }
        const T & top() {
            return top_node->data;
        }
};

#endif