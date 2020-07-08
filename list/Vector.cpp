#ifndef VectorCpp
#define VectorCpp

template <typename Object>
class Vector {
    private:
        int theSize;
        int theCapacity;
        Object * objects;

    public:
        const static int minCapacity = 2;
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
        class const_iterator {
            protected:
                int index;
                Object * ptr;
                const_iterator(int i, Object * p) : index(i), ptr(p) {}
                friend class Vector<Object>;
                Object & retrive() const {
                    return ptr[index];
                }
            public:
                const_iterator() : index(-1), ptr(NULL) {}
                const_iterator operator+(int k) const {
                    const_iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        ++itr;
                    }
                    return itr;
                }
                const_iterator operator++() {
                    ++index;
                    return *this;
                }
                const_iterator operator++(int) {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }
                const_iterator operator--() {
                    --index;
                    return *this;
                }
                const_iterator operator--(int) const {
                    const_iterator old = *this;
                    --(*this);
                    return old;
                }
                bool operator==(const const_iterator & rhs) const  {
                    return index == rhs.index;
                }
                bool operator!=(const const_iterator & rhs) const  {
                    return !(*this == rhs);
                }
                const Object & operator*() const {
                    return retrive();
                }
                void assertIsValid(Object * p) const {
                    if (index == -1 || ptr == NULL || p != ptr) {
                        throw "bounds exception";
                    }
                }
        };
        class iterator : public const_iterator {
            protected:
                iterator(int i, Object * p) : const_iterator(i, p) {}
                friend class Vector<Object>;
            public:
                iterator() : const_iterator(-1) {}
                iterator operator+(int k) const {
                    iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        ++itr;
                    }
                    return itr;
                }
                iterator operator++() {
                    ++iterator::index;
                    return *this;
                }
                iterator operator++(int) {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }
                iterator operator--() {
                    --iterator::index;
                    return *this;
                }
                iterator operator--(int) const {
                    iterator old = *this;
                    --(*this);
                    return old;
                }
                Object & operator*() {
                    return iterator::retrive();
                }
                const Object & operator*() const {
                    return iterator::retrive();
                }
        };
        class const_reverse_iterator {
            protected:
                int index;
                Object * ptr;
                const_reverse_iterator(int i, Object * p) : index(i), ptr(p) {}
                friend class Vector<Object>;
                Object & retrive() const {
                    return ptr[index];
                }
            public:
                const_reverse_iterator() : index(-1), ptr(NULL) {}
                const_reverse_iterator operator+(int k) const {
                    const_reverse_iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        --itr;
                    }
                    return itr;
                }
                const_reverse_iterator operator++() {
                    --index;
                    return *this;
                }
                const_reverse_iterator operator++(int) {
                    const_reverse_iterator old = *this;
                    ++(*this);
                    return old;
                }
                const_reverse_iterator operator--() {
                    ++index;
                    return *this;
                }
                const_reverse_iterator operator--(int) const {
                    const_reverse_iterator old = *this;
                    --(*this);
                    return old;
                }
                bool operator==(const const_reverse_iterator & rhs) const  {
                    return index == rhs.index;
                }
                bool operator!=(const const_reverse_iterator & rhs) const  {
                    return !(*this == rhs);
                }
                const Object & operator*() const {
                    return retrive();
                }
        };
        class reverse_iterator : public const_reverse_iterator {
            protected:
                reverse_iterator(int i, Object * p) : const_reverse_iterator(i, p) {}
                friend class Vector<Object>;
            public:
                reverse_iterator() : const_reverse_iterator(-1, NULL) {}
                reverse_iterator operator+(int k) const {
                    reverse_iterator itr = *(this);
                    for (int i = 0; i < k; i++) {
                        --itr;
                    }
                    return itr;
                }
                reverse_iterator operator++() {
                    --reverse_iterator::index;
                    return *this;
                }
                reverse_iterator operator++(int) {
                    reverse_iterator old = *this;
                    ++(*this);
                    return old;
                }
                reverse_iterator operator--() {
                    ++reverse_iterator::index;
                    return *this;
                }
                reverse_iterator operator--(int) const {
                    reverse_iterator old = *this;
                    --(*this);
                    return old;
                }
                Object & operator*() {
                    return reverse_iterator::retrive();
                }
                const Object & operator*() const {
                    return reverse_iterator::retrive();
                }
        };

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
            objects = new Object[newCapacity];
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
            if (index > (theSize - 1) || index < 0) {
                cout << "Index Illegal: Vector class line 71;" << "\n";
            }
            return objects[index];
        }
        void push_back(const Object & obj) {
            insert(end(), obj);
        }
        Object & back() {
            return objects[theSize - 1];
        }
        const Object & back() const {
            return objects[theSize - 1];
        }
        void pop_back() {
            erase(--end());
        }

    public:
        iterator begin() {
            return iterator(0, objects);
        }
        const_iterator begin() const {
            return iterator(0, objects);
        }
        iterator end() {
            return iterator(theSize, objects);
        }
        const_iterator end() const {
            return iterator(theSize, objects);
        }
        reverse_iterator rbegin() {
            return reverse_iterator(theSize-1, objects);
        }
        const_reverse_iterator rbegin() const {
            return reverse_iterator(theSize-1, objects);
        }
        reverse_iterator rend() {
            return reverse_iterator(-1, objects);
        }
        const_reverse_iterator rend() const {
            return reverse_iterator(-1, objects);
        }

    public:
        iterator insert(iterator itr, const Object & x) {
            try
            {
                itr.assertIsValid(objects);
                int newSize = theSize + 1;
                resize(newSize); // when resize occurs, iterators may be invalidated
                iterator j = --end(); //the index in the (end - 1)
                iterator j_copy = j;
                while(itr != j) {
                    *j = *(--j_copy);
                    --j;
                }
                *j = x;
                return j;
            }
            catch(const char* msg)
            {
                std::cerr << msg << '\n';
            }
        }
        iterator erase(iterator itr) {
            try
            {
                itr.assertIsValid(objects);
                iterator j = end(); //the index in the end
                int newSize = theSize - 1;
                resize(newSize); // when resize occurs, iterators may be invalidated
                itr = iterator(itr.index, objects);
                iterator itr_copy = itr;
                iterator itr_result = itr;
                while(itr != j) {
                    *(itr++) = *(++itr_copy);
                }
                return itr_result;
            }
            catch(const char* msg)
            {
                std::cerr << msg << '\n';
            }
        }
};

#endif




