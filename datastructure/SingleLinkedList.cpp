#ifndef SingleLinkedListCpp
#define SingleLinkedListCpp

template<typename Object>
class SingleLinkedList {
    private:
        struct Node
        {
            Object data;
            Node * next;

            Node(const Object & d = Object(), Node * n = NULL) : data(d), next(n) {}
        };
        
    private:
        int theSize;
        Node * head;
        Node * tail;

    private:
        void init() {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
        }

    public:
        class const_iterator {
            protected:
                Node * current;
                const_iterator(Node * p) : current(p) {}
                friend class SingleLinkedList<Object>;
                Object & retrieve() {
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
                    ++(*this);
                    return old;
                }
                const Object & operator*() const {
                    return retrieve();
                }
                bool operator==(const const_iterator & rhs) const {
                    return (current == rhs.current);
                } 
                bool operator!=(const const_iterator & rhs) const {
                    return !(*this == rhs);
                } 
        };
        class iterator : public const_iterator {
            private:
                iterator(Node * p) : const_iterator(p) {}
                friend class SingleLinkedList<Object>;
            public:
                iterator() {}
                iterator operator++() {
                    const_iterator::current = const_iterator::current->next;
                    return *this;
                }
                iterator operator++(int) {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }
                Object & operator*() {
                    return const_iterator::retrieve();
                }
                const Object & operator*() const {
                    return const_iterator::retrieve();
                }
        };

    public:
        SingleLinkedList() {
            init();
        }
        ~SingleLinkedList() {
            clear();
            delete head;
            delete tail;
        }
        SingleLinkedList(const SingleLinkedList & rhs) {
            init();
            *this = rhs;
        }
        const SingleLinkedList & operator=(const SingleLinkedList & rhs) {
            if (this != &rhs) {
                clear();
                for (const_iterator itr = rhs.begin(); itr != rhs.end(); itr++) {
                    push_back(*itr);
                }
            }
            return *this;
        }

    public:
        int size() const {
            return theSize;
        }
        bool empty() const {
            return (theSize == 0);
        }
        void clear() {
            while(!empty()) {
                pop_front();
            }
        }
        iterator begin() {
            return iterator(head->next);
        }
        const_iterator begin() const {
            return iterator(head->next);
        }
        iterator end() {
            return iterator(tail);
        }
        const_iterator end() const {
            return iterator(tail);
        }

    public:
        //core methods
        void push_back(const Object & o) {
            insert(end(), o);
        }
        Object & back() {
            iterator itr = begin();
            for (int i = 1; i < theSize; i++) {
                itr++;
            }
            return *(itr);
        }
        const Object & back() const {
            const_iterator itr = begin();
            for (int i = 1; i < theSize; i++) {
                itr++;
            }
            return *(itr);
        }
        void pop_back() {
            const_iterator itr = begin();
            for (int i = 1; i < theSize; i++) {
                itr++;
            }
            erase(itr);
        }
        void push_front(const Object & o) {
            insert(begin(), o);
        }
        Object & front() {
            return *(begin());
        }
        const Object & front() const {
            return *(begin());
        }
        void pop_front() {
            erase(begin());
        }

    public:
        iterator insert(const_iterator itr, const Object & o) {
            const_iterator begin_itr = begin();
            Node * p = itr.current;
            Node * newNode = new Node(o, p);
            if (itr == begin_itr) {
                head->next = newNode;
            } else {
                for (int i = 0; i < theSize; i++) {
                    const_iterator prev = begin_itr;
                    if ((++begin_itr) == itr) {
                        prev.current->next = newNode;
                        break;
                    }
                }
            }
            theSize++;
            return iterator(newNode);
        }
        iterator erase(const_iterator itr) {
            const_iterator begin_itr = begin();
            Node * p = itr.current;
            Node * next_p = p->next;
            if (itr == begin_itr) {
                head->next = next_p;
            } else {
                for (int i = 0; i < theSize; i++) {
                    const_iterator prev = begin_itr;
                    if ((++begin_itr) == itr) {
                        prev.current->next = next_p;
                        break;
                    }
                }
            }
            theSize--;
            return iterator(next_p);
        }

    public:
        void adjacentElementsSwap(iterator itr) {
            iterator prev = itr;
            iterator next = iterator(itr.current->next);
            iterator begin_itr = begin();
            iterator end_itr = end();
            // I need the node which is prior to the "prev" node
            if (begin_itr.current == prev.current){
                head->next = next.current;
            } 
            else {
                while(begin_itr != end_itr) {
                    if (begin_itr.current->next == prev.current) {
                        begin_itr.current->next = next.current;
                        break;
                    }
                    ++begin_itr;
                }
            } 
            prev.current->next = next.current->next;
            next.current->next = prev.current;
        }

};

#endif