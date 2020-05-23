#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>
#include <string>
#include <math.h>

#define NUM 10000000

using namespace std;
using namespace std::chrono;

#include "extra"

void pre_populate_to_arr(vector<float> & arr);
void linear_sort(vector<float> & arr);
void linear_sort_k_elements(vector<float> & arr);
float get_kth_maximum_element(const vector<float> & arr, int k);
void print_words(vector<string> words);
vector<string> find_valid_english_words(char* word_puzzle_board, string* dictionary);
bool look_up_word_in_dictionary(string word, string* dictionary);
int get_the_1s_number_in_n(int n);
float get_the_sum(int from, int to);

enum class Dirctions_enum {
	up = 0,
	down,
	left,
	right,
	left_up_diagonal,
	right_up_diagonal,
	left_down_diagonal,
	right_down_diagonal
};

template<typename Object>
class Collection {
	public:
		Collection() {}
		~Collection() {
			delete[] container;
		}
		Collection(const Collection & rhs) {
			container = new Object[limit_size];
			for(int i = 0; i < limit_size; i++) {
				container[i] = rhs.container[i];
			}
		}
		const Collection & operator=(const Collection & rhs) {
			if(this != &rhs) {
				container = new Object[limit_size];
				for(int i = 0; i < limit_size; i++) {
					container[i] = rhs.container[i];
				}
			}
			return *this;
		}
		bool isEmpty() const {
			if (size == 0) return true;
			return false;
		}
		void makeEmpty() {
			container = new Object(8);
			size = 0;
		}
		void insert(const Object & o) {
			if (size < limit_size) {
				container[size] = o;
			} else {
				add_resize();
				container[size] = o;
			}
			size++;
		}
		void remove(const Object & o) {
			for(int i = 0; i < size; i++) {
				if (container[i] == o) {
					Object temp = container[size-1];
					container[i] = NULL;
					container[size-1] = NULL;
					container[i] = temp;
					break;
				}
			}
			size--;
			if (limit_size / size == 4) {
				decrease_resize();
			}
		}
		bool contains(const Object & o) const {
			for(int i = 0; i < size; i++) {
				if (o == container[i]) return true;
			}
			return false;
		}
		int get_size() {
			return size;
		}
		int get_limit_size() {
			return limit_size;
		}
		const Object & operator[](int index) const {
			return container[index];
		} 
	protected:
		int limit_size = 8;
		Object *container = new Object[limit_size];
		int size = 0;
		void add_resize() {
			int original_limit_size = limit_size;
			limit_size *= 2;
			Object *temp = new Object[original_limit_size];
			for (int i = 0; i < size; i++) {
				temp[i] = container[i];
			}
			container = new Object[limit_size];
			for(int i = 0; i < original_limit_size; i++) {
				container[i] = temp[i];
			}
			delete[] temp;
		}
		void decrease_resize() {
			int original_limit_size = limit_size;
			limit_size /= 2;
			Object *temp = new Object[original_limit_size];
			for (int i = 0; i < original_limit_size; i++) {
				temp[i] = container[i];
			}
			container = new Object[limit_size];
			for(int i = 0; i < original_limit_size; i++) {
				if(temp[i]) container[i] = temp[i];
			}
			delete[] temp;
		}
};

char to_lower_case(char c) {
	if(c >= 65 && c <= 90) {
		c = c + 32;
	}
	return c;
};

int strings_compare(const string & lhs, const string & rhs) {
	char l;
	char r;
	int lhs_size = lhs.size();
	int rhs_size = rhs.size();
	for(int i = 0; i < lhs_size; i++) {
		if (rhs_size-1 >= i) {
			l = to_lower_case(lhs[i]);
			r = to_lower_case(rhs[i]);
			if (l > r) return 1;
			else if (l < r) return -1;
		}
	}
	return 0; 
};

class Employee {
	public:
		Employee() {}
		Employee(string name) : m_name(name) {}
		void set_name(string name) {
			m_name = name;
		}
		const string & get_name() const {
			return m_name;
		}
		void print(ostream & out) const {
			out << m_name << "\n";
		}
		bool operator<(const Employee & rhs) const {
			int r = strings_compare(m_name,rhs.get_name());
			if (r == -1) return true;
			return false;
		}
	private:
		string m_name;
};

class ComparableFunction {
	public:
	static const int name_flag = 1;
	static const int equal_flag = 0;
	static const int less_flag = -1;
	static const int greater_flag = 1;
	ComparableFunction() {}
	int compare(Employee & lhs, Employee & rhs, int flag) {
		switch(flag) {
			case name_flag:
				return strings_compare(lhs.get_name(),rhs.get_name());
		}
	}
};

template<typename Comparable>
class OrderedCollection : public Collection<Comparable> {
	public:
		OrderedCollection() : Collection<Comparable>() {
			
		}
		const Comparable & find_max() const {
			int index = 0;
			for (int i = 0; i < this->size; i++) {
				if (this->container[index] < this->container[i]) {
					index = i;
				}
			}
			return this->container[index];
		}
		const Comparable & find_min() const {
			int index = 0;
			for (int i = 0; i < this->size; i++) {
				if (this->container[i] < this->container[index]) {
					index = i;
				}
			}
			return this->container[index];
		}
		const Comparable & find_max(ComparableFunction & comparable_function, int flag) const {
			int index = 0;
			for (int i = 0; i < this->size; i++) {
				if (comparable_function.compare(this->container[index],this->container[i],flag) == comparable_function.less_flag) {
					index = i;
				}
			}
			return this->container[index];
		}
		const Comparable & find_min(ComparableFunction & comparable_function,int flag) const {
			int index = 0;
			for (int i = 0; i < this->size; i++) {
				if (comparable_function.compare(this->container[index],this->container[i],flag) == comparable_function.greater_flag) {
					index = i;
				}
			}
			return this->container[index];
		}
};

int main() {
	//prepare data
	Employee e1 = Employee("Ashax");
	Employee e2 = Employee("Peter");
	Employee e3 = Employee("Mel");
	//---------
	long start_time = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
	).count();
	//solve problem
	OrderedCollection<Employee> collection;
	ComparableFunction c;
	collection.insert(e1);
	collection.insert(e2);
	collection.insert(e3);
	collection.find_min().print(cout);
	collection.find_max().print(cout);
	collection.find_min(c,c.name_flag).print(cout);
	collection.find_max(c,c.name_flag).print(cout);
	//----------
	long end_time = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
	).count();
	cout << "The algorithm costs: " << end_time - start_time << " millisecond(s)" << "\n";
}

int get_the_1s_number_in_n(int n) {
	if (n <= 0) {
		return 0;
	} else if(n == 1) {
		return 1;
	} else if (n % 2 == 0) {
		return get_the_1s_number_in_n(n+1)-1;
	} else {
		return get_the_1s_number_in_n(n/2) + 1;
	}
}

float get_the_sum(int from, int to) {
	float sum = 0;
	for (float i = from; i <= to; i++) {
		sum += (1/i);
	}
	return sum;
}

void print_words(vector<string> words) {
	for(int i = 0; i < 4; i++) {
		cout << words[i] << "\t";
	}
	cout << "\n";
}
vector<string> find_valid_english_words(char* word_puzzle_board, string* dictionary) {
	vector<string> words;
	int rows = 4;
	int cols = 4;
	int index;
	int next_index;
	int max = 15;
	int min = 0;
	string word;
	const Dirctions_enum directions[8] = {Dirctions_enum::up,Dirctions_enum::down,Dirctions_enum::left,Dirctions_enum::right,Dirctions_enum::left_up_diagonal,Dirctions_enum::right_up_diagonal,Dirctions_enum::left_down_diagonal,Dirctions_enum::right_down_diagonal};
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			index = i*cols + j;
			for(int k = 0; k < 8; k++) {
				word = word_puzzle_board[index];
				switch(directions[k]) {
					case 0:
						next_index = index - cols;
						while(next_index >= min && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index -= cols;
						}
						break;
					case 1:
						next_index = index + cols;
						while(next_index >= min && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index += cols;
						}
						break;
					case 2:
						next_index = index - 1;
						while(next_index >= i*cols && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index -= 1;
						}
						break;
					case 3:
						next_index = index + 1;
						while(next_index >= min && next_index <= i*cols + 3) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index += 1;
						}
						break;
					case 4:
						next_index = index - (cols + 1);
						while(next_index >= min && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index -= (cols + 1);
						}
						break;
					case 5:
						next_index = index - cols + 1;
						while(next_index >= min && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index = next_index - cols + 1;
						}
						break;
					case 6:
						next_index = index + cols - 1;
						while(next_index >= min && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index = next_index + cols - 1;
						}
						break;
					case 7:
						next_index = index + cols + 1;
						while(next_index >= min && next_index <= max) {
							word += word_puzzle_board[next_index];
							if (look_up_word_in_dictionary(word,dictionary)) {
								words.push_back(word);
							}
							next_index = next_index + cols + 1;
						}
						break;
				}
			}
		}
	}
	return words;
}

bool look_up_word_in_dictionary(string word, string* dictionary) {
	for(int i = 0; i < 4; i++) {
		if (word == dictionary[i]) 
			return true;
	}
	return false;
}


void pre_populate_to_arr(vector<float> & arr) {
	srand( (unsigned)time( NULL ) );
    for (int i = 0; i < NUM; i++) 
    {
        arr.push_back(rand()%1000000);
    }
}
void linear_sort(vector<float> & arr) {
	int index;
	for(int i=0; i<NUM; i++) {
		index = i;
		for (int j=i; j<NUM; j++) {
			if (arr[index] < arr[j]) {
				index  = j;
			}
		}
		float temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}
void linear_sort(vector<float> & arr,int k) {
	int index;
	for(int i=0; i<k; i++) {
		index = i;
		for (int j=i; j<k; j++) {
			if (arr[index] < arr[j]) {
				index  = j;
			}
		}
		float temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}
void linear_sort_k_elements(vector<float> & arr) {
	int k = NUM/2;
	linear_sort(arr,k);
	int index;
	for(int i = k; i < NUM; i++) {
		if (arr[i] > arr[k-1]) {
			for (int j = k-1; j >= 0; j--) {
				if (arr[i] > arr[j]) {
					float temp = arr[j];
					arr[j] = arr[i];
					arr[j+1] = temp;
					index = j;
				} else {
					break;
				}
			}
		}
	}
}
float get_kth_maximum_element(const vector<float> & arr, int k) {
	return arr[k];
}


