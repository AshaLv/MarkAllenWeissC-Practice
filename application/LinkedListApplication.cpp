#ifndef LinkedListApplicationCpp
#define LinkedListApplicationCpp
#include "../list/SingleLinkedList.cpp"
#include "../list/DoubleLinkedList.cpp"

template<typename Object>
class LinkedListApplication {
    public:
        static void populate(DoubleLinkedList<Object> & L, Object * p) {
            while (*p != -1) {
                L.push_back(*(p++));
            }
        } 
        static void printAll(const DoubleLinkedList<Object> & L) {
            typename DoubleLinkedList<Object>::const_iterator itr = L.begin();
            typename DoubleLinkedList<Object>::const_iterator end_itr = L.end();
            while(itr != end_itr) cout << *(itr++) << "\n";
        } 
};

#endif
