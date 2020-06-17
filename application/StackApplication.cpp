#ifndef StackApplicationCpp
#define StackApplicationCpp
#include "../datastructure/Stack.cpp"
class StackApplication {
    public:
        static int priority(char c) {
            if (c == '+' || c == '-') {
                return 1;
            } else if (c == '*' || c == '/') {
                return 2;
            } else if (c == '(') {
                return 3;
            } else if (c == ')') {
                return 0;
            } else {
                return -1;
            }
        }

        static float calculate(float lhs, float rhs, char mOperator) {
            if (mOperator == '+') return lhs + rhs;
            else if (mOperator == '-') return lhs - rhs;
            else if (mOperator == '*') return lhs * rhs;
            else if (mOperator == '/') return lhs / rhs;
        }

        static float basicCalculate(char * source, int size) {
            Stack<char> layer1;
            Stack<float> layer2;
            char topOperator;
            float lhs;
            float rhs;
            for (int i = 0; i < size; i++) {
                char c = source[i];
                if (c == ')') {
                    while (layer1.top() != '(') {
                        topOperator = layer1.top();
                        layer1.pop_back();
                        rhs = layer2.top();
                        layer2.pop_back();
                        lhs = layer2.top();
                        layer2.pop_back();
                        layer2.push_back(calculate(lhs,rhs,topOperator));
                    }
                    layer1.pop_back();
                    continue;
                }
                int priorityC = priority(c);
                if (priorityC == -1) { // count a number
                    layer2.push_back((int)(c) - 48);
                } else { // count an operator
                    topOperator = layer1.top();
                    if (priorityC <= priority(topOperator) && topOperator != '(') {
                        rhs = layer2.top();
                        layer2.pop_back();
                        lhs = layer2.top();
                        layer2.pop_back();
                        layer2.push_back(calculate(lhs,rhs,topOperator));
                        layer1.pop_back();
                    } 
                    layer1.push_back(c);
                }
            }
            while (!layer1.empty()) {
                topOperator = layer1.top();
                layer1.pop_back();
                rhs = layer2.top();
                layer2.pop_back();
                lhs = layer2.top();
                layer2.pop_back();
                layer2.push_back(calculate(lhs,rhs,topOperator));
            }
            return layer2.top();
        }
};
#endif