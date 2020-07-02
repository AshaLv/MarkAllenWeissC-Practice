#ifndef VectorApplicationCpp
#define VectorApplicationCpp
#include "../list/Vector.cpp"

template<typename Object>
class VectorApplication {
    public:
        static void printAll(const Vector<Object> & L) {
            int size = L.size();
            for (int i = 0; i < size; i++) {
                cout << L[i] << " ";
            }
            cout << "\n";
        }
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
        static const Vector<Object> common(const Vector<Object> & v1, const Vector<Object> & v2) {
            // v1 and v2 are sorted 
            int v1_size = v1.size();
            int v2_size = v2.size();
            Vector<Object> v;
            int i = 0;
            int j = 0;
            while (i < v1_size && j < v2_size) {
                Object v1_object = v1[i];
                Object v2_object = v2[j];
                if (v1_object == v2_object) {
                    v.push_back(v1[i]);
                    ++i;
                    ++j;
                } 
                else if (v1_object > v2_object) ++j;
                else ++i;
            }
            return v;
        }
        static const Vector<Object> combine(const Vector<Object> & v1, const Vector<Object> & v2) {
            // v1 and v2 are sorted 
            int v1_size = v1.size();
            int v2_size = v2.size();
            Vector<Object> v;
            int i = 0;
            int j = 0;
            while (i < v1_size || j < v2_size) {
                Object v1_object = v1[i];
                Object v2_object = v2[j];
                if (v1_object == v2_object) {
                    v.push_back(v1_object);
                    ++i;
                    ++j;
                } 
                else if (v1_object > v2_object){
                    v.push_back(v2_object);
                    ++j;
                } 
                else {
                    v.push_back(v1_object);
                    ++i;
                } 
            }
            return v;
        }
};

#endif