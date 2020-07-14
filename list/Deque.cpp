#ifndef DequeCpp
#define DequeCpp

template <typename T>
class Deque {
    private:
        struct Node
        {
            T data;
            Node * m_prev;
            Node * m_next;

            Node(const T & d = T(), Node * p = NULL, Node * n = NULL) : data(d), m_prev(p), m_next(n) {}
        };
        Node * head;
        Node * tail;
        int size;
        void init() {
            size = 0;
            head = new Node();
            tail = new Node();
            head->m_next = tail;
            tail->m_prev = head;
        }
        class const_iterator {
            public:
                Node * current;
                const_iterator(Node * p) : current(p) {}
                T & retrieve() const {
                    return current->data;
                }
            public:
                const_iterator() : current(NULL) {}
                const_iterator operator++() {
                    current = current->m_next;
                    return *this;
                }
                const_iterator operator++(int) {
                    const_iterator old = *this;
                    current = current->m_next;
                    return old;
                }
                const_iterator operator--() {
                    current = current->m_prev;
                    return *this;
                }
                const_iterator operator--(int) {
                    const_iterator old = *this;
                    current = current->m_prev;
                    return old;
                }
                const T & operator*() const {
                    return retrieve();
                }
                bool operator==(const const_iterator & rhs) const {
                    return current == rhs.current;
                }
                bool operator!=(const const_iterator & rhs) const {
                    return !(*this == rhs);
                }
        };
    public:
        Deque() {
            init();
        }
        ~Deque() {
            clear();
            delete head;
            delete tail;
        }     
        Deque(const Deque & rhs) {
            init();
            *this = rhs;
        }   
        const Deque & operator=(const Deque & rhs) {
            if (this != &rhs) {
                clear();
                const_iterator begin = rhs.begin();
                const_iterator end = rhs.end();
                while(begin != end) inject(*(begin++));
            }
            return *this;
        }
    private:
        const_iterator begin() {
            return const_iterator(head->m_next);
        }
        const_iterator end() {
            return const_iterator(tail);
        }
        void clear() {
            if (!empty()) erase(begin());
        }
    public:
        bool empty() {
            return size == 0;
        }
        void push(const T & x) {
            insert(begin(), x);
        }
        T pop() {
            const_iterator start = begin();
            T d = start.current->data;
            erase(start);
            return d;
        }
        void inject(const T & x) {
            insert(end(), x);
        }
        T eject() {
            const_iterator last_node_position = --end();
            T d = last_node_position.current->data;
            erase(last_node_position);
            return d;
        }
    private:
        void insert(const_iterator itr, const T & x) {
            Node * p = itr.current;
            Node * n = new Node(x, p->m_prev, p);
            p->m_prev->m_next = n;
            p->m_prev = n;
            ++size;
        }
        void erase(const_iterator itr) {
            Node * p = itr.current;
            Node * m_prev = p->m_prev;
            Node * m_next = p->m_next;
            m_prev->m_next = m_next;
            m_next->m_prev = m_prev;
            --size;
            delete p;
        }
};

#endif