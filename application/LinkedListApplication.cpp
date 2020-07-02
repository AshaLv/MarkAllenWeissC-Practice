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
};

#endif
