#ifndef VectorCpp
#define VectorCpp

template <typename Object>
class Vector {
    private:
        int theSize;
        int theCapacity;
        Object * objects;

    public:
        const static int minCapacity = 16;
        Vector() : theSize(0), theCapacity(minCapacity) {
            objects = new Object[theCapacity];
        }
        explicit Vector(int capacity) : theSize(0), theCapacity(capacity) {
            int newCapacity = theCapacity > minCapacity ? theCapacity : minCapacity;
            objects = new Object[newCapacity];
        }
        ~Vector() {
            delete[] objects;
        }
        Vector(const Vector & rhs) : objects(NULL) {
            *this = rhs;
        }
        const Vector & operator=(const Vector & rhs) {
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
        Object & operator[](int index) {
            if (index > (theSize - 1) || index < 0) {
                cout << "Index Illegal: Vector class line 71;" << "\n";
            }
            return objects[index];
        }
        const Object & operator[](int index) const {
            return objects[index];
        }
        void push_back(const Object & obj) {
            insert(theSize, obj);
        }
        Object & back() {
            return objects[theSize - 1];
        }
        const Object & back() const {
            return objects[theSize - 1];
        }
        void pop_back() {
            erase(theSize - 1);
        }

    public:
        typedef Object * iterator;
        typedef const Object * const_iterator;
        iterator begin() {
            return &objects[0];
        }
        const_iterator begin() const {
            return &objects[0];
        }
        iterator end() {
            return &objects[theSize];
        }
        const_iterator end() const {
            return &objects[theSize];
        }

    public:
        void insert(int i, const Object & x) {
            int j = theSize;
            int newSize = theSize + 1;
            resize(newSize);
            while(i != j) {
                objects[j] = objects[j-1];
                --j;
            }
            objects[i] = x;
        }
        void erase(int i) {
            int j = theSize;
            int newSize = theSize - 1;
            resize(newSize);
            while(i != j) {
                objects[i] = objects[i + 1];
                ++i;
            }
        }
};

#endif




