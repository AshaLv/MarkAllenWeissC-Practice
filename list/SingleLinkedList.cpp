#ifndef SingleLinkedListCpp
#define SingleLinkedListCpp
#include <iostream>
using namespace std;

template<typename Object>
class SingleLinkedList {
    private:
        struct Node
        {
            Object data;
            Node * next;

            Node(const Object & d = Object(), Node * n = NULL) : data(d), next(n) {}
        };
        int theSize;
        Node * head;
        void init() {
            theSize = 0;
            head = new Node;
        }

    public:
        class const_iterator {
            protected:
                Node * current;
            protected:
                const_iterator(Node * p) : current(p) {}
                friend class SingleLinkedList<Object>;
                Object & retrieve() const {
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
            protected:
                iterator(Node * p) : const_iterator(p) {}
                friend class SingleLinkedList<Object>;
            public:
                iterator() {}
                iterator operator++() {
                    iterator::current = iterator::current->next;
                    return *this;
                }
                iterator operator++(int) {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }
                Object & operator*() {
                    return iterator::retrieve();
                }
                const Object & operator*() const {
                    return iterator::retrieve();
                }
        };

    public:
        SingleLinkedList() {
            init();
        }
        ~SingleLinkedList() {
            clear();
            delete head;
        }
        SingleLinkedList(const SingleLinkedList & rhs) {
            init();
            *this = rhs;
        }
        const SingleLinkedList & operator=(const SingleLinkedList & rhs) {
            if (this != &rhs) {
                clear();
                for (const_iterator itr = rhs.begin(); itr != rhs.end(); itr++) push_back(*itr);
            }
            return *this;
        }

    private:
        struct Pair
        {
            bool existed;
            iterator itr;

            Pair(bool m_existed, iterator m_itr) : existed(m_existed), itr(m_itr) {}
        };

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
            return iterator(NULL);
        }
        const_iterator end() const {
            return iterator(NULL);
        }
        Pair contain(const Object & x) {
            iterator c = begin();
            iterator end_itr = end();
            while (c != end_itr) {
                if (*(c) == x) {
                    return Pair(true, c);
                } else if (*(c) > x) {
                    return Pair(false, c);;
                }
                ++c;
            } 
            return Pair(false, c);;
        }
        void remove(const Object & x) {
            const_iterator c = begin();
            const_iterator end_itr = end();
            while (c != end_itr) {
                if (*(c) == x) {
                    erase(c);
                    return;
                }
                ++c;
            } 
        }

    public:
        //core methods
        void push_back(const Object & o) {
            insert(end(), o);
        }
        Object & back() {
            const_iterator itr = begin();
            for (int i = 0; i < theSize - 1; i++) {
                ++itr;
            }
            return *(itr);
        }
        const Object & back() const {
            const_iterator itr = begin();
            for (int i = 0; i < theSize - 1; i++) {
                ++itr;
            }
            return *(itr);
        }
        void pop_back() {
            const_iterator itr = begin();
            for (int i = 0; i < theSize - 1; i++) {
                ++itr;
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
        void reverse() {
            Node * p1 = NULL;
            Node * p2 = head->next;
            Node * p3 = p2->next;
            while(p2 != NULL) {
                p2->next = p1;
                p1 = p2;
                p2 = p3;
                if (p3 != NULL) p3 = p3->next;
            }
            head->next = p1;
        }
        void rprint() {
            reverse();
            const_iterator begin_itr = begin();
            const_iterator end_itr = end();
            while(begin_itr != end_itr) cout << *(begin_itr++) << " ";
            cout << "\n";
        }
        void print() {
            const_iterator begin_itr = begin();
            const_iterator end_itr = end();
            while(begin_itr != end_itr) cout << *(begin_itr++) << " ";
            cout << "\n";
        }

    public:
        iterator insert(iterator itr, const Object & o) {
            Pair m_pair = contain(o);
            if (m_pair.existed) {
                return itr;
            } 
            else {
                itr = m_pair.itr;
            } 
            const_iterator begin_itr = begin();
            Node * p = itr.current;
            Node * newNode = new Node(o, p);
            if (itr == begin_itr) {
                head->next = newNode;
            } else {
                for (int i = 0; i < theSize; i++) {
                    if (begin_itr.current->next == itr.current) {
                        begin_itr.current->next = newNode;
                        break;
                    }
                    ++begin_itr;
                }
            }
            theSize++;
            return iterator(newNode);
        }
        iterator erase(const_iterator itr) {
            const_iterator begin_itr = begin();
            Node * p = itr.current;
            Node * next = p->next;
            if (itr == begin_itr) {
                head->next = next;
            } else {
                for (int i = 0; i < theSize; i++) {
                    if (begin_itr.current->next == itr.current) {
                        begin_itr.current->next = next;
                        break;
                    }
                    ++begin_itr;
                }
            }
            delete p;
            theSize--;
            return iterator(next);
        }

    public:
        void adjacentElementsSwap(const_iterator itr) {
            const_iterator prev = itr;
            const_iterator next = const_iterator(itr.current->next);
            const_iterator begin_itr = begin();
            const_iterator end_itr = end();
            // I need the node which is prior to the "prev" node
            if (begin_itr == prev){
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