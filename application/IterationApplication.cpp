#ifndef IterationApplicationCpp
#define IterationApplicationCpp

template<typename Iterator, typename Object>
class IterationApplication {
    public:
        static Iterator find(Iterator start, Iterator end, const Object & x) {
            while (start != end) {
                if (*(start) == x) return start;
                ++start;
            }
            return end;
        }
};

#endif