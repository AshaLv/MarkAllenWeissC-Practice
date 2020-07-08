#ifndef DoubleLinkedListCpp
#define DoubleLinkedListCpp
#include <iostream>
using namespace std;

template<typename Object>
class DoubleLinkedList {
    private:
        struct Node
        {
            Object data;
            Node * next;
            Node * prev;
            int flag;

            Node(const Object & d = Object(), Node * n = NULL, Node * p = NULL) : data(d), next(n), prev(p),flag(0) {}
        };

    private:
        int theSize;
        Node * head;
        Node * tail;

    private:
        void init() {
            theSize = 0;
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
        }

    public:
        class const_iterator {
            protected:
                Node * current;
            protected:
                const_iterator(Node * p) : current(p) {}
                friend class DoubleLinkedList<Object>;
                Object & retrieve() const {
                    return current->data;
                }
            public:
                const_iterator() : current(NULL) {}
                const_iterator operator+(int k) const {
                    const_iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        ++itr;
                    }
                    return itr;
                }
                const_iterator operator++() {
                    current = current->next;
                    return *this;
                }
                const_iterator operator++(int) {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }
                const_iterator operator--() {
                    current = current->prev;
                    return *this;
                }
                const_iterator operator--(int) {
                    const_iterator old = *this;
                    --(*this);
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
                void assertIsValid() const {
                    if (current == NULL ||  current->flag == -1) {
                        throw "bounds exception";
                    }
                }
                void delete_current() {
                    Node * old = current;
                    delete old;
                    current->flag = -1;
                    cout << "delete iterator" << "\n";
                }
        };
        class iterator : public const_iterator {
            protected:
                iterator(Node * p) : const_iterator(p) {}
                friend class DoubleLinkedList<Object>;
            public:
                iterator() {}
                iterator operator+(int k) const {
                    iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        ++itr;
                    }
                    return itr;
                }
                iterator operator++() {
                    iterator::current = iterator::current->next;
                    return *this;
                }
                iterator operator++(int) {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }
                iterator operator--() {
                    iterator::current = iterator::current->prev;
                    return *this;
                }
                iterator operator--(int) {
                    iterator old = *this;
                    --(*this);
                    return old;
                }
                Object & operator*() {
                    return iterator::retrieve();
                }
                const Object & operator*() const {
                    return iterator::retrieve();
                }
        };
        class const_reverse_iterator {
            protected:
                Node * current;
            protected:
                const_reverse_iterator(Node * p) : current(p) {}
                friend class DoubleLinkedList<Object>;
                Object & retrieve() const {
                    return current->data;
                }
            public:
                const_reverse_iterator() : current(NULL) {}
                const_reverse_iterator operator+(int k) const {
                    const_reverse_iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        --itr;
                    }
                    return itr;
                }
                const_reverse_iterator operator++() {
                    current = current->prev;
                    return *this;
                }
                const_reverse_iterator operator++(int) {
                    const_reverse_iterator old = *this;
                    ++(*this);
                    return old;
                }
                const_reverse_iterator operator--() {
                    current = current->next;
                    return *this;
                }
                const_reverse_iterator operator--(int) {
                    const_reverse_iterator old = *this;
                    --(*this);
                    return old;
                }
                const Object & operator*() const {
                    return retrieve();
                }
                bool operator==(const const_reverse_iterator & rhs) const {
                    return (current == rhs.current);
                } 
                bool operator!=(const const_reverse_iterator & rhs) const {
                    return !(*this == rhs);
                } 
        };
        class reverse_iterator : public const_reverse_iterator {
            protected:
                reverse_iterator(Node * p) : const_reverse_iterator(p) {}
                friend class DoubleLinkedList<Object>;
            public:
                reverse_iterator() {}
                reverse_iterator operator+(int k) const {
                    reverse_iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        --itr;
                    }
                    return itr;
                }
                reverse_iterator operator++() {
                    reverse_iterator::current = reverse_iterator::current->prev;
                    return *this;
                }
                reverse_iterator operator++(int) {
                    reverse_iterator old = *this;
                    ++(*this);
                    return old;
                }
                reverse_iterator operator--() {
                    reverse_iterator::current = reverse_iterator::current->next;
                    return *this;
                }
                reverse_iterator operator--(int) {
                    reverse_iterator old = *this;
                    --(*this);
                    return old;
                }
                Object & operator*() {
                    return reverse_iterator::retrieve();
                }
                const Object & operator*() const {
                    return reverse_iterator::retrieve();
                }
        };

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
        reverse_iterator rbegin() {
            return reverse_iterator(tail->prev);
        }
        const_reverse_iterator rbegin() const {
            return reverse_iterator(tail->prev);
        }
        reverse_iterator rend() {
            return reverse_iterator(head);
        }
        const_reverse_iterator rend() const {
            return reverse_iterator(head);
        }

    public:
        DoubleLinkedList() {
            init();
        }
        ~DoubleLinkedList() {
            clear();
            delete head;
            delete tail;
        }
        DoubleLinkedList(const DoubleLinkedList & rhs) {
            init();
            *this = rhs;
        }
        const DoubleLinkedList & operator=(const DoubleLinkedList & rhs) {
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
        void splice(iterator position, DoubleLinkedList<Object> & list) {
            try
            {
                position.assertIsValid();
                if (&list == this) return;
                Node * prev_node = position.current->prev;
                Node * next_node = position.current;
                iterator begin_itr = list.begin();
                iterator end_itr = list.end();
                Node * list_first_node = begin_itr.current;
                Node * list_last_node = end_itr.current->prev;
                Node * list_head = begin_itr.current->prev;
                Node * list_tail = end_itr.current;
                // splice lists
                prev_node->next = list_first_node;
                list_first_node->prev = prev_node;
                next_node->prev = list_last_node;
                list_last_node->next = next_node;
                // delete list nodes
                list_head->next = list_tail;
                list_tail->prev = list_head;
                // reset theSize
                theSize = list.theSize + theSize;
                list.theSize = 0;
            }
            catch(const char* msg)
            {
                std::cerr << msg << '\n';
            }
        }

    public:
        //core methods
        void push_back(const Object & o) {
            insert(end(), o);
        }
        Object & back() {
            const_iterator itr = end();
            return *(itr.current->prev);
        }
        const Object & back() const {
            const_iterator itr = end();
            return *(itr.current->prev);
        }
        void pop_back() {
            erase(end());
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
        iterator insert(iterator itr, const Object & o) {
            try
            {   
                itr.assertIsValid();
                Node * p = itr.current;
                Node * prev = p->prev;
                Node * newNode = new Node(o, p, prev);
                prev->next = newNode;
                p->prev = newNode;
                ++theSize;
                return iterator(newNode);
            }
            catch(const char* msg)
            {
                std::cerr << msg << '\n';
            }
        }
        iterator erase(iterator itr) {
            try
            {
                itr.assertIsValid();
                Node * p = itr.current;
                Node * next = p->next;
                Node * prev = p->prev;
                prev->next = next;
                next->prev = prev;
                itr.delete_current();
            }
            catch(const char* msg)
            {
                std::cerr << msg << '\n';
            }
            --theSize;
            return iterator(next);
        }

    public:
        //application
        void adjacentElementsSwap(iterator itr) {
            Node * current = itr.current;
            Node * prev = current->prev;
            Node * next = current->next;
            Node * next_next = next->next;
            next_next->prev = current;
            next->next = current;
            next->prev = prev;
            current->next = next_next;
            current->prev = next;
            prev->next = next;
        }
        Object josephus_game(int m) {
            DoubleLinkedList m_list;
            m_list = *this;
            const_iterator begin_itr = m_list.begin();
            const_iterator end_itr = m_list.end();
            if (m == 0) {
                return end_itr.current->prev->data;
            } else {
                int n = m_list.size();
                m = m % n;
                while(m_list.size() != 1) {
                    for (int i = 0; i < m; i++) {
                        if (++begin_itr == end_itr) begin_itr = m_list.begin();
                    }
                    begin_itr = m_list.erase(begin_itr);
                    if (begin_itr == end_itr) begin_itr = m_list.begin();
                }
            }
            return begin_itr.current->data;
        }

};

#endif