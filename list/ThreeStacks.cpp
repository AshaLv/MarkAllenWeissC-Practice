#ifndef ThreeStacksCpp
#define ThreeStacksCpp

template <typename T>
class ThreeStacks {
    private:
        T * objects;
        short atomic_size;
        short size;
        short left;
        short middle;
        short right;
        void init() {
            atomic_size = 8;
            size = atomic_size * 3;
            left = 0;
            middle = atomic_size;
            right = size - 1;
            objects = new T[size];
        }
    public:
        ThreeStacks() {
            init();
        }
        ~ThreeStacks() {
            delete[] objects;
        }
        ThreeStacks(const ThreeStacks & rhs) {
            init();
            *this = rhs;
        }
        const ThreeStacks & operator=(const ThreeStacks & rhs) {
            if (this != &rhs) {
                for (short i = 0; i < size; i++)
                {
                    left = rhs.left;
                    right = rhs.right;
                    middle = rhs.middle;
                    objects[i] = rhs.objects[i];
                }
                
            }
            return *this;
        }
    public:
        void push1(const T & x) {
            if (!full1()) {
                objects[left] = x;
                ++left;
                return;
            }
            throw "Exception: full";
        }
        void push2(const T & x) {
            if (!full2()) {
                objects[middle] = x;
                ++middle;
                return;
            }
            throw "Exception: full";
        }
        void push3(const T & x) {
            if (!full3()) {
                objects[right] = x;
                --right;
                return;
            }
            throw "Exception: full";
        }
        const T & top1() {
            if (!empty1()) {
                return objects[left - 1];
            }
            throw "Exception: empty";
        }
        const T & top2() {
            if (!empty2()) {
                return objects[middle - 1];
            }
            throw "Exception: empty";
        }
        const T & top3() {
            if (!empty3()) {
                return objects[right + 1];
            }
            throw "Exception: empty";
        }
        bool full1() {
            if (left == atomic_size) {
                return true;
            }
            return false;
        }
        bool full2() {
            if (middle == atomic_size * 2) {
                return true;
            }
            return false;
        }
        bool full3() {
            if (right == atomic_size * 2 - 1) {
                return true;
            }
            return false;
        }
        bool empty1() {
            if (left == 0) {
                return true;
            }
            return false;
        }
        bool empty2() {
            if (middle == atomic_size) {
                return true;
            }
            return false;
        }
        bool empty3() {
            if (right == size - 1) {
                return true;
            }
            return false;
        }
        void pop1() {
            if (!empty1()) {
                --left;
            }
        }
        void pop2() {
            if (!empty2()) {
                --middle;
            }
        }
        void pop3() {
            if (!empty3()) {
                ++right;
            }
        }
};

#endif