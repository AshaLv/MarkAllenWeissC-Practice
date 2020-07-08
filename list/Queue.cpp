#ifndef QueueCpp
#define QueueCpp
#include <iostream>
using namespace std;

template<typename Object>
class Queue {
    private:
        struct Node
        {
            Object data;
            Node * prev;
            Node * next;

            Node(const Object & d = Object(), Node * p = NULL, Node * n = NULL) : data(d), prev(p), next(n) {} 
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
            tail->prev = head;
        }

    public:
        class const_iterator {
            protected:
                Node * current;
                const_iterator(Node * p) : current(p) {};
                friend class Queue<Object>;

            protected:
                Object & retrieve() const {
                    return current->data;
                }

            public:
                const_iterator() : current(NULL) {}
                const_iterator & operator++() {
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
            protected:
                iterator(Node * p) : const_iterator(p) {};
                friend class Queue<Object>;

            public:
                iterator() {}
                iterator & operator++() {
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
                    return const_iterator::operator*();
                }
        };

    public:
        Queue() { init(); }
        ~Queue() {
            clear();
            delete head;
            delete tail;
        }
        Queue(const Queue & rhs) {
            init();
            *this = rhs;
        }
        const Queue & operator=(const Queue & rhs) {
            if (this != &rhs) {
                clear();
                const_iterator rhsBegin = rhs.begin();
                const_iterator rhsEnd = rhs.end();
                while(rhsBegin != rhsEnd) {
                    push_back(*(rhsBegin++));
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
            while (!empty()) {
                pop_front();
            }
        }

    public:
        // core methods
        void push_back(const Object & o) {
            insert(end(), o);
        }
        const Object & front() const {
            if (!empty()) {
                return *(begin());
            }
            return NULL;
        }
        void pop_front() {
            if (!empty()) {
                erase(begin());
            }
        }
    private:
        iterator insert(iterator itr, const Object & o) {
            theSize++;
            Node * p = itr.current;
            Node * current = new Node(o, p->prev, p);
            p->prev = p->prev->next = current;
            return iterator(current);
        }
        iterator erase(iterator itr) {
            Node * p = itr.current;
            iterator retVal(p->next);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            theSize--;
            return retVal;
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
};
#endif