#ifndef SelfAdjustingVectorCpp
#define SelfAdjustingVectorCpp

template <typename T>
class SelfAdjustingVector {
    private:
        T * objects;
        int size;
        int capicity;
        void init() {
            size = 0;
            capicity = 8;
            objects = new T[capicity];
        }
    public:
        SelfAdjustingVector() {
            init();
        }
        ~SelfAdjustingVector() {
            delete objects;
        }
        SelfAdjustingVector(const SelfAdjustingVector & rhs) {
            init();
            *this = rhs;
        }
        const SelfAdjustingVector & operator=(const SelfAdjustingVector & rhs) {
            if (this != &rhs) {
                size = rhs.size;
                if (capicity < rhs.capicity) {
                    capicity = rhs.capicity;
                    T * old_objects = objects;
                    delete[] old_objects; 
                    objects = new T[capicity];
                }
                for (int i = 0; i < size; i++)
                {
                    objects[i] = rhs.objects[i];
                }
            }
            return *this;
        }
    private:
        void resize(int new_size) {
            int old_size = size;
            T * old_objects = objects;
            if (new_size > capicity || new_size <= capicity/4) {
                capicity = new_size;
                objects = new T[capicity];
                for (int i = 0; i < old_size; i++)
                {
                    objects[i] = old_objects[i];
                }
                delete[] old_objects;
            }
            size = new_size;
        }
        void push_all_back(int msize) {
            for (int i = msize - 1; i >= 0; --i)
            {
                objects[i + 1] = objects[i];
            }
        }
    public:
        void push(const T & x) {
            int old_size = size;
            resize(size + 1);
            push_all_back(old_size);
            objects[0] = x; 
        }
        bool find(const T & x) {
            for (int i = 0; i < size; i++)
            {
                if (objects[i] == x) {
                    if (i == 0) return objects[0];
                    push_all_back(i);
                    objects[0] = x;
                    return true;
                }
            }
            return false;
        }
        const T & front() {
            return objects[0];
        }
};

#endif