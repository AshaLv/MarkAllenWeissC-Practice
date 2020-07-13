#ifndef StackApplicationCpp
#define StackApplicationCpp
#include "../list/Stack.cpp"
#include "../list/Queue.cpp"
#include "../list/Vector.cpp"
#include "../application/VectorApplication.cpp"
#include <string>
#include <math.h>
#include "../list/DoubleLinkedList.cpp"

class StackApplication {
    public:
        static float float_it(const string & operand) {
            return operand[0] - 48; // only consider 0-9;
        }
        static void calculte(Stack<float> & expression_stack, const string & m_operator) {
            float right_operand = expression_stack.top();
            expression_stack.pop_back();
            float left_operand = expression_stack.top();
            expression_stack.pop_back();
            if (m_operator == "+") expression_stack.push_back(left_operand + right_operand);
            else if (m_operator == "-") expression_stack.push_back(left_operand - right_operand);
            else if (m_operator == "*") expression_stack.push_back(left_operand * right_operand);
            else if (m_operator == "/") expression_stack.push_back(left_operand / right_operand);
            else if (m_operator == "^") expression_stack.push_back(pow(left_operand,right_operand));
            else throw "Exception: operator exception";
        }   
        static float evaluate_postfix_expression(const string * postfix_expression) {
            string end_flag = "\n";
            Stack<float> expression_stack;
            Vector<string> operator_vector;
            string operators[5] = {"+","-","*","/","^"};
            VectorApplication<string>::populate(operator_vector, operators, 5);
            while (*postfix_expression != end_flag) {
                if ( operator_vector.contain(*(postfix_expression)) ) {
                    calculte(expression_stack, *(postfix_expression));
                } else {
                    expression_stack.push_back(float_it(*(postfix_expression)));
                }
                ++postfix_expression;
            }
            return expression_stack.top();
        }
        static int priority(const string & m_operator) {
            if (m_operator == "+" || m_operator == "-") return 0;
            else if (m_operator == "*" || m_operator == "/") return 1;
            else if (m_operator == "^") return 2;
            else if (m_operator == "(") return 3;
            else return -1;
        };
        static string * infix_to_postfix(string * postfix_expresstion, const string * infix_expression) {
            string end_flag = "\n";
            Stack<string> control_stack;
            Queue<string> postfix_expresstion_queue;
            Vector<string> operator_vector;
            string operators[6] = {"+","-","*","/","(","^"};
            VectorApplication<string>::populate(operator_vector, operators, 6);
            while (*infix_expression != "\n") {
                if (*infix_expression == ")") {
                    while (control_stack.top() != "(") {
                        postfix_expresstion_queue.push_back(control_stack.top());
                        control_stack.pop_back();
                    }
                    control_stack.pop_back();
                    ++infix_expression;
                    continue;
                }
                if (operator_vector.contain(*infix_expression)) {
                    if (priority(*infix_expression) > priority(control_stack.top()) || control_stack.top() == "(") {
                        NULL;
                    } else {
                        control_stack.pop_back();
                        postfix_expresstion_queue.push_back(control_stack.top());
                    }
                    control_stack.push_back(*infix_expression);
                } else {
                    postfix_expresstion_queue.push_back(*infix_expression);
                }
                ++infix_expression;
            }
            while (!control_stack.empty()) {
                postfix_expresstion_queue.push_back(control_stack.top());
                control_stack.pop_back();
            }
            int m_size = postfix_expresstion_queue.size();
            string * old_postfix_expresstion = postfix_expresstion;
            postfix_expresstion = new string[m_size+1];
            for (int i = 0; i < m_size; i++) {
                postfix_expresstion[i] = postfix_expresstion_queue.front();
                postfix_expresstion_queue.pop_front();
            }
            postfix_expresstion[m_size] = "\n";
            delete[] old_postfix_expresstion;
            return postfix_expresstion;
        }
        static string postfix_to_infix(const string * postfix_expression) {
            Stack<string> expression_stack;
            Vector<string> operator_vector;
            string operators[6] = {"+","-","*","/","(","^"};
            VectorApplication<string>::populate(operator_vector, operators, 5);
            string m_expression;
            while (*postfix_expression != "\n") {
                m_expression = "";
                if (operator_vector.contain(*postfix_expression)) {
                    string right_operand = expression_stack.top();
                    expression_stack.pop_back();
                    string left_operand = expression_stack.top();
                    expression_stack.pop_back();
                    m_expression = "(" + left_operand + *postfix_expression + right_operand + ")";
                    expression_stack.push_back(m_expression);
                } else {
                    expression_stack.push_back(*postfix_expression);
                }
                ++postfix_expression;
            }
            return expression_stack.top();
        }
        static void check_balancing_symbols_for_all_languages(const string & source) {
            Stack<string> check_stack;
            char language_first_letter = source[1];
            Vector<string> v_open_symbol;
            Vector<string> v_close_symbol;
            string open_symbols[5] = {"(","[","{","begin","/*"};
            string close_symbols[5] = {")","]","}","end","*/"};
            VectorApplication<string>::populate(v_open_symbol,open_symbols,5);
            VectorApplication<string>::populate(v_close_symbol,close_symbols,5);
            string collect_string;
            int open_symbol_find_result_index;
            int close_symbol_find_result_index;
            for (int i = 0; i < source.size(); i++)  {
                collect_string = "";
                open_symbol_find_result_index = -1;
                close_symbol_find_result_index = -1;
                if (language_first_letter == 'P') {
                    for (int j = i; source[i] == 'b' && j < i+5; j++) {
                        collect_string += source[j];
                    }
                    if (collect_string == "begin") {
                        open_symbol_find_result_index = 3;
                        i = i + 4;
                    }
                    for (int j = i; source[i] == 'e' && j < i+3; j++) {
                        collect_string += source[j];
                    }
                    if (collect_string == "end") {
                        close_symbol_find_result_index = 3;
                        i = i + 2;
                    }
                } else if (language_first_letter == 'C') {
                    for (int j = i; source[i] == '/' && j < i+2; j++) {
                        collect_string += source[j];
                    }
                    if (collect_string == "/*") {
                        open_symbol_find_result_index = 4;
                        i = i + 1;
                    }
                    for (int j = i; source[i] == '*' && j < i+2; j++) {
                        collect_string += source[j];
                    }
                    if (collect_string == "*/") {
                        close_symbol_find_result_index = 4;
                        i = i + 1;
                    }
                } 
                if (open_symbol_find_result_index == -1 && close_symbol_find_result_index == -1) {
                    collect_string = source[i];
                    open_symbol_find_result_index = v_open_symbol.find(collect_string);
                    close_symbol_find_result_index = v_close_symbol.find(collect_string);
                }
                if (open_symbol_find_result_index != -1) {
                    check_stack.push_back(open_symbols[open_symbol_find_result_index]);
                } else if (close_symbol_find_result_index != -1) {
                    if (check_stack.top() != open_symbols[close_symbol_find_result_index]) {
                        throw "Exception: balancing symbol\n";
                    } else {
                        check_stack.pop_back();
                    }
                } else {}
            }
            if (!check_stack.empty()) throw "Exception: balancing symbol\n";
        }
};
#endif