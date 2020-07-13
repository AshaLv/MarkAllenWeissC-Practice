#ifndef TwoStacksCpp
#define TwoStacksCpp

template <typename T>
class TwoStacks {
    private:
        short size;
        T * objects;
        short left;
        short right;
    private:
        void check_overflow() {
            if (left > right || left < 0 || right > size - 1) {
                throw "Exception: Overflow";
            }
        }
    public:
        TwoStacks() {
            size = 16;
            objects = new T[size];
            left = 0;
            right = size - 1;
        }
        ~TwoStacks() {
            delete[] objects;
        }
        TwoStacks(const TwoStacks & rhs) {
            *this = rhs;
        }
        const TwoStacks & operator=(const TwoStacks & rhs) {
            if (this != & rhs) {
                for (short i = 0; i < 16; i++)
                {
                    objects[i] = rhs.objects[i];
                }
            }
            return *this;
        }
    public:
        void push1(const T & x) {
            check_overflow();
            objects[left] = x;
            ++left;
        }
        void push2(const T & x) {
            check_overflow();
            objects[right] = x;
            --right;
        }
        const T & top1() const {
            return objects[left - 1];
        }
        const T & top2() const {
            return objects[right + 1];
        }
        bool empty1() {
            if (left == 0) return true;
            return false;
        }
        bool empty2() {
            if (right == size - 1) return true;
            return false;
        }
        void pop1() {
            if (!empty1()) --left;
        }
        void pop2() {
            if (!empty2()) ++right;
        }
};

#endif