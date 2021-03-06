#ifndef SingleLinkedListCpp
#define SingleLinkedListCpp
#include <iostream>
using namespace std;

template<typename T>
class SingleLinkedList {
    private:
        struct Node
        {
            T data;
            Node * next;

            Node(const T & d = T(), Node * n = NULL) : data(d), next(n) {}
        };
        int theSize;
        Node * head;
        Node * tail;
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
            protected:
                const_iterator(Node * p) : current(p) {}
                friend class SingleLinkedList<T>;
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
                    ++(*this);
                    return old;
                }
                const T & operator*() const {
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
                friend class SingleLinkedList<T>;
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
                T & operator*() {
                    return iterator::retrieve();
                }
                const T & operator*() const {
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
            return iterator(tail);
        }
        const_iterator end() const {
            return iterator(tail);
        }
        Pair contain(const T & x) {
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
        void remove(const T & x) {
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
        void push_back(const T & o) {
            insert(end(), o);
        }
        T & back() {
            const_iterator itr = begin();
            for (int i = 0; i < theSize - 1; i++) {
                ++itr;
            }
            return *(itr);
        }
        const T & back() const {
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
        void push_front(const T & o) {
            insert(begin(), o);
        }
        T & front() {
            return *(begin());
        }
        const T & front() const {
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
        iterator insert(iterator itr, const T & o) {
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
        iterator add_before(iterator itr, const T & x) {
            Node * p1 = itr.current;
            Node * p2 = p1->next;
            Node * p = new Node(p1->data, p2);
            p1->next = p;
            p1->data = x;
            return itr;
        }
        // iterator erase(const_iterator itr) {
        //     const_iterator begin_itr = begin();
        //     Node * p = itr.current;
        //     Node * next = p->next;
        //     if (itr == begin_itr) {
        //         head->next = next;
        //     } else {
        //         for (int i = 0; i < theSize; i++) {
        //             if (begin_itr.current->next == itr.current) {
        //                 begin_itr.current->next = next;
        //                 break;
        //             }
        //             ++begin_itr;
        //         }
        //     }
        //     delete p;
        //     --theSize;
        //     return iterator(next);
        // }
        iterator erase(iterator itr) {
            Node * p1 = itr.current;
            Node * p2 = p1->next;
            Node * p3 = p2->next;
            p1->data = p2->data;
            delete p2;
            p1->next = p3;
            --theSize;
            return itr;
        }
        bool contain_circle() {
            const_iterator begin_speed_1_itr = begin();
            const_iterator begin_speed_2_itr = begin();
            const_iterator end_itr = end();
            while (begin_speed_2_itr != end_itr) {
                ++begin_speed_2_itr;
                if (begin_speed_2_itr == begin_speed_1_itr) return true;
                ++begin_speed_2_itr;
                if (begin_speed_2_itr == begin_speed_1_itr) return true;
                ++begin_speed_1_itr;
            }
            throw "Exception: Circle Here!";
            return false;
        }
        void make_circle() {
            Node * p = head->next->next;
            Node * p2 = head;
            for (int i = 0; i < 4; i++)
            {
                p2 = p2->next;
            }
            p2->next = p;
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