#ifndef StackCpp
#define StackCpp
#include <iostream>
using namespace std;

template <typename Object>
class Stack {
    private:
        int theSize;
        int theCapacity;
        Object * objects;

    public:
        const static int minCapacity = 16;
        Stack() : theSize(0), theCapacity(minCapacity) {
            objects = new Object[theCapacity];
        }
        explicit Stack(int capacity) : theSize(0), theCapacity(capacity) {
            int newCapacity = theCapacity > minCapacity ? theCapacity : minCapacity;
            objects = new Object[newCapacity];
        }
        ~Stack() {
            delete[] objects;
        }
        Stack(const Stack & rhs) : objects(NULL) {
            *this = rhs;
        }
        const Stack & operator=(const Stack & rhs) {
            if (this != &rhs) {
                int rhsSize = rhs.size();
                int rhsCapacity = rhs.capacity();
                if (this->capacity() < rhsCapacity){
                    Object * oldObjects = objects;
                    objects = new Object[rhsCapacity];
                    theCapacity = rhsCapacity;
                    delete[] oldObjects;
                } 
                for (int i = 0; i < rhsSize; i++) objects[i] = rhs[i];
                theSize = rhsSize;
            }
            return *this;
        }

    public:
        int size() const {
            return theSize;
        }
        int capacity() const {
            return theCapacity;
        }
        bool empty() const {
            return (theSize == 0);
        }
        void resize(int newSize) {
            if (newSize > theCapacity || newSize <= theCapacity / 4) {
                int newCapacity = theSize*2;
                if (newCapacity > minCapacity) reserve(newCapacity);
            }
            theSize = newSize;
        }
        void reserve(int newCapacity) {
            if (newCapacity <= theSize) return;
            Object * oldObjects = objects;
            Object * objects = new Object[newCapacity];
            for (int i = 0; i < theSize; i++) objects[i] = oldObjects[i];
            delete[] oldObjects;
            theCapacity = newCapacity;
        }

    public:
        //core methods
        void push_back(const Object & obj) {
            int newSize = theSize + 1;
            resize(newSize);
            objects[theSize-1] = obj;
        }
        const Object & top() const {
            return objects[theSize - 1];
        }
        void pop_back() {
            --theSize;
        }

};

#endif




