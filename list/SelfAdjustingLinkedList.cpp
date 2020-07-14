#ifndef SelfAdjustingLinkedListCpp
#define SelfAdjustingLinkedListCpp

template <typename T>
class SelfAdjustingLinkedList {
    private:
        struct Node
        {
            T data;
            Node * next;

            Node(const T & d = T(), Node * n = NULL) : data(d), next(n) {}
        };
        int size;
        Node * head;
        void init() {
            size = 0;
            head = new Node();
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
                    current = current->next;
                    return *this;
                }
                const_iterator operator++(int) {
                    const_iterator old = *this;
                    current = current->next;
                    return old;
                }
                const T & operator*() {
                    return retrieve();
                }
                bool operator==(const const_iterator & rhs) {
                    return current == rhs.current;
                }
                bool operator!=(const const_iterator & rhs) {
                    return !(*this == rhs);
                }
        };
        void clear() {
            while(!empty()) {
                pop();
            }
        }
        void pop() {
            Node * p = head->next;
            Node * p1 = p->next;
            head->next = p1;
            delete p;
            --size;
        }
        const_iterator begin() {
            return const_iterator(head->next);
        }
        const_iterator end() {
            return const_iterator(NULL);
        }
    public:
        SelfAdjustingLinkedList() {
            init();
        }
        ~SelfAdjustingLinkedList() {
            clear();
            delete head;
        }
        SelfAdjustingLinkedList(const SelfAdjustingLinkedList & rhs) {
            init();
            *this = rhs;
        }
        const SelfAdjustingLinkedList & operator=(const SelfAdjustingLinkedList & rhs) {
            if (this != &rhs) {
                clear();
                const_iterator begin_itr = rhs.begin();
                const_iterator end_itr = rhs.itr();
                Node * p = head;
                while(begin_itr != end_itr){
                    p->next = new Node(*(begin_itr++));
                    p = p->next;
                } 
            }
            return *this;
        }
    public:
        void push(const T & x) {
            Node * p = new Node(x, head->next);
            head->next = p;
            ++size;
        }
        bool empty() const {
            return size == 0;
        }
        bool find(const T & x) {
            const_iterator begin_itr = begin();
            const_iterator end_itr = end();
            const_iterator prev_itr;
            while(begin_itr != end_itr) {
                if (*(begin_itr) == x) {
                    Node * p = begin_itr.current;
                    Node * prev = prev_itr.current;
                    Node * next = p->next;
                    prev->next = next;
                    Node * head_next_p = head->next;
                    head->next = p;
                    p->next = head_next_p;
                    return true;
                }
                prev_itr = begin_itr;
                ++begin_itr;
            }
            return false;
        }
        const T & front() {
            return *begin();
        }

        
};

#endif