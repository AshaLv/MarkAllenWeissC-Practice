#ifndef VectorApplicationCpp
#define VectorApplicationCpp
#include "../datastructure/Vector.cpp"

template<typename Object>
class VectorApplication {
    public:
        static void printLots(const Vector<Object> & L, const Vector<Object> & P) {
            int p_size = P.size();
            for (int i = 0; i < p_size; i++) {
                cout << L[P[i]] << " ";
            }
            cout << "\n";
        }
        static void populate(Vector<Object> & L, Object * p) {
            while (*p != -1) {
                L.push_back(*(p++));
            }
        } 
};

#endif