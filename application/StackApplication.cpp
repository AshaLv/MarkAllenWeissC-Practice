#ifndef StackApplicationCpp
#define StackApplicationCpp
#include "../list/Stack.cpp"
#include "../list/Vector.cpp"
#include "../application/VectorApplication.cpp"
#include <string>
class StackApplication {
    public:
        // static void check_balancing_symbols(const Stack & stack1; const string & string1) {

        // }
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