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
int get_random_number_between(int i, int j);

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

template <typename Object>
class Matrix {
	public:
		Matrix(int rows = 3, int cols = 3) : array(rows) {
			for(int i = 0; i < rows; i++) {
				array[i].resize(cols);
			}
		}
		const vector<Object> & operator[](int row) const {
			return array[row];
		}
		vector<Object> & operator[](int row) {
			return array[row];
		}
		int numrows() const {
			return array.size();
		}
		int numcols() const {
			return numrows() ? array[0].size() : 0;
		}
		void resize(int new_rows, int new_cols) {
			array.resize(new_rows);
			for(int i = 0; i < new_rows; i++) {
				array[i].resize(new_cols);
			}
		}
	private:
		vector< vector<Object> > array;
};

class func_obj {
	public:
		func_obj() {}
		virtual void run(int n) = 0;
};

class sum1 : public func_obj {
	public:
		sum1() {}
		void run(int n);
};

class sum2 : public func_obj  {
	void run(int n);
};

class sum3 : public func_obj {
	void run(int n);
};

class sum4 : public func_obj {
	void run(int n);
};

class sum5 : public func_obj {
	void run(int n);
};

class sum6 : public func_obj {
	void run(int n);
};

class permutation1: public func_obj {
	void run(int n);
};

class permutation2: public func_obj {
	void run(int n);
};

class permutation3: public func_obj {
	void run(int n);
};

class max_sub_sequence_sum1: public func_obj {
	public:
		max_sub_sequence_sum1() {}
		explicit max_sub_sequence_sum1(int * array) : m_array(array) {}
		void run(int n);
	protected:
		int * m_array;
};

class max_sub_sequence_sum2: public max_sub_sequence_sum1 {
	public:
		explicit max_sub_sequence_sum2(int * array) : max_sub_sequence_sum1(array) {}
		void run(int n);
};

class max_sub_sequence_sum3: public max_sub_sequence_sum1 {
	public:
		explicit max_sub_sequence_sum3(int * array) : max_sub_sequence_sum1(array) {}
		void run(int n);
};

void hornerrule(float x, int n, float * a);

void print_running_time(func_obj * func_obj,int n);

bool binary_search(int * arr, int k, int n);

int gcd(int a, int b);

int get_minimum_subsequence_sum(int * arr, int n);

int get_minimum_positive_subsequence_sum(int * arr, int low, int high);

int start_minimum_positive_subsequence_sum(int * arr, int low, int high);

float get_maximum_positive_subsequence_product(float * arr, int low, int high);

float start_minimum_positive_subsequence_product(float * arr, int low, int high);

template<typename T>
const T & min3(const T & t1, const T & t2, const T & t3);

template<typename T>
const T & max3(const T & t1, const T & t2, const T & t3);

class simple_linear_f {
	public:
		float f(float x) const;
		float guess_x(float low, float high) const;
};

bool is_a_prime(int n);

void print_all_prime_until(int n);

double m_pow(float n, int power);

int start_get_majority_element(const int * arr, int size);

int get_majority_element(int * arr, int size);

int main() {
	//prepare data
	int arr[12] = {2,5,4,2,3,3,5,3,3,3,3,3};
	int size = 12;
	//solve problem
	cout << start_get_majority_element(arr,size) << "\n";
}

int start_get_majority_element(const int * arr, int size) {
	int copied_arr[size];
	for (int i = 0; i < size; i++) {
		copied_arr[i] = arr[i];
	}
	int result = get_majority_element(copied_arr,size);
	// make sure this is the majority element whose amount is greater than 2/size
	int standard_count = size / 2;
	int count = 0;
	for (int i = 0; i < size; i ++) {
		if (arr[i] == result) count++;
	}
	if (count > standard_count) return result;
	return NULL;
}

int get_majority_element(int * arr, int size) {
	int equal_count = 0; // indicates how many equal numbers found
	// compare connected elements
	for (int i = 0; i < size - 1; i += 2) {
		if (arr[i] != arr[i+1]) continue; // if not equal, ignore it
		else {
			arr[equal_count] = arr[i]; // if equal, replace element in order from 0 with this equal value
			equal_count += 1;
		}
	}
	if (size % 2 == 1) {
		arr[equal_count] = arr[size - 1]; // if the array size is odd, replace element in order from 0 with the last element
		equal_count += 1;
	} 
	if (equal_count == 0){
		return NULL;
	} 
	else if (equal_count == 1) {
		return arr[0];
	}
	else {
		return get_majority_element(arr,equal_count);
	}
}	

double m_pow(float n, int power) {
	double even_result = 1;
	double odd_result = 1;
	if (power == 0) return 1;
	else if (power == 1) return n;
	while (power >= 2) {
		if (power % 2 == 0) {
			// even number
			power = power / 2;
			even_result = n * n;
			n = even_result;
		}
		else {
			// odd number
			power = power - 1;
			odd_result *= n;
		}
	}
	return odd_result * even_result;
}

void print_all_prime_until(int n) {
	// Sieve of Eratosthenes Method
	int table[n-1];
	int smallest_prime;
	int k;
	for (int i = 2; i <= n; i++) {
		table[i-2] = i;
	} 
	for (int i = 0; i <= n-2; i++) {
		smallest_prime = table[i];
		if (smallest_prime == NULL) continue;
		else if (smallest_prime > pow(n,0.5)) {
			cout << smallest_prime << "  ";
			continue;
		} else {
			k = 2;
			int product = smallest_prime * k;
			while (product <= n) {
				table[product - 2] = NULL;
				k++;
				product = smallest_prime * k;
			}
		}
		cout << smallest_prime << "  ";
	}
	cout << "\n";
}

bool is_a_prime(int n) {
	if (n == 1) return false;
	if (n == 3 || n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= pow(n,0.5); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

float simple_linear_f::f(float x) const {
	float r =  3 * x + 1;
	if (abs(r) < 0.000001) return 0;
	return r;
}

float simple_linear_f::guess_x(float low, float high) const {
	//3x + 1
	float half = (low + high) / 2;
	float r = f(half);
	cout << r << "\n";
	if (r == 0) return half;
	else if (r > 0) {
		return guess_x(low, half);
	} else {
		return guess_x(half,high);
	}
}

template<typename T>
const T & max3(const T & t1, const T & t2, const T & t3) {
	if (t1 > t2) {
		if (t1 > t3) {
			return t1;
		} else {
			return t3;
		}
	} else {
		if (t2 > t3) {
			return t2;
		} else {
			return t3;
		}
	}
};

template<typename T>
const T & min3(const T & t1, const T & t2, const T & t3) {
	if (t1 < t2) {
		if (t1 < t3) {
			return t1;
		} else {
			return t3;
		}
	} else {
		if (t2 < t3) {
			return t2;
		} else {
			return t3;
		}
	}
};

float start_minimum_positive_subsequence_product(float * arr, int low, int high) {
	return get_maximum_positive_subsequence_product(arr,low,high);
}

float get_maximum_positive_subsequence_product(float * arr, int low, int high) {
	if (low == high) {
		if (arr[low] > 0) {
			return arr[low];
		} 
		return 0;
	}
	int middle = (low + high) / 2;
	int left_low = low;
	int left_high = middle;
	int right_low = middle + 1;
	int right_high = high;
	int left_minimum_pos_product = get_maximum_positive_subsequence_product(arr,left_low,left_high);
	int right_minimum_pos_product = get_maximum_positive_subsequence_product(arr,right_low,right_high);
	int left_product = 1;
	int right_product;
	int middle_minimum_pos_product = 0;
	float result_product;
	for (int i = left_high; i >= left_low; i--) {
		left_product *= arr[i];
		right_product = 1;
		for (int j = right_low; j <= right_high; j++) {
			right_product = right_product * arr[j];
			result_product = right_product * left_product;
			if (middle_minimum_pos_product < result_product) middle_minimum_pos_product = result_product;
		}
		
		
	}
	return max3<int>(left_minimum_pos_product,right_minimum_pos_product,middle_minimum_pos_product);
}

int start_minimum_positive_subsequence_sum(int * arr, int low, int high) {
	return get_minimum_positive_subsequence_sum(arr,low,high);
}

int get_minimum_positive_subsequence_sum(int * arr, int low, int high) {
	if (low == high) {
		if (arr[low] > 0) {
			return arr[low];
		} 
		return INT_MAX;
	}
	int middle = (low + high) / 2;
	int left_low = low;
	int left_high = middle;
	int right_low = middle + 1;
	int right_high = high;
	int left_minimum_pos_sum = get_minimum_positive_subsequence_sum(arr,left_low,left_high);
	int right_minimum_pos_sum = get_minimum_positive_subsequence_sum(arr,right_low,right_high);
	int left_sum = 0;
	int right_sum;
	int middle_minimum_pos_sum = INT_MAX;
	int result_sum;
	for (int i = left_high; i >= left_low; i--) {
		left_sum += arr[i];
		right_sum = 0;
		for (int j = right_low; j <= right_high; j++) {
			right_sum = right_sum + arr[j];
			result_sum = right_sum + left_sum;
			if (right_sum > 0 && middle_minimum_pos_sum > right_sum) middle_minimum_pos_sum = right_sum;
		}
	}
	return min3<int>(left_minimum_pos_sum,right_minimum_pos_sum,middle_minimum_pos_sum);
}

int get_minimum_subsequence_sum(int * arr, int n) {
	int sum = 0;
	int inner_sum = 0;
	for (int i = 0; i < n; i++) {
		inner_sum += arr[i];
		if (inner_sum < sum) sum = inner_sum;
		if (inner_sum > 0) inner_sum = 0;
	}
	return sum;
}

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a ? a : b;
	}
	if (a % 2 == 0 && b % 2 == 0) {
		// a,b is an even number
		return 2*gcd(a/2,b/2);
	} else if (a % 2 == 0 && b % 2 == 1) {
		// a is even and b is odd
		return gcd(a/2,b);
	} else if (a % 2 == 1 && b % 2 == 0) {
		// a is odd and b is even
		return gcd(a,b/2);
	} else {
		// a is even and b is even
		return gcd((a+b)/2,(a > b ? a-b : b-a)/2);
	}
}

bool binary_search(int * arr, int k, int n) {
	int low = 0;
	int high = n - 1;
	int middle = (low + high) / 2;
	while(high >= low) {
		if (arr[middle] == k) return true;
		else if (arr[middle] > k) {
			high = middle - 1;
			middle = (low + high) / 2;
		} 
		else {
			low = middle + 1;
			middle = (low + high) / 2;
		}
	}
	return false;
}

void hornerrule(float x, int n, float * a){
	float sum = 0;
	for (int i = n; i >= 0; i--) {
		sum = x*sum + a[i];
	}
	cout << "sum: " << sum << "\n";
}

void max_sub_sequence_sum1::run(int n) {
	//running time n3
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int inner_sum = 0;
			for (int k = i; k <= j; k++) {
				inner_sum += m_array[k];
			}
			if (sum < inner_sum) sum = inner_sum;
		}
	}
	cout << "sum:" << sum << "\n";
}
void max_sub_sequence_sum2::run(int n) {
	//running time n2
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int inner_sum = 0;
		for (int j = i; j < n; j++) {
			inner_sum += m_array[j];
			if (sum < inner_sum) sum = inner_sum;
		}
	}
	cout << "sum:" << sum << "\n";
}
void max_sub_sequence_sum3::run(int n) {
	//running time n
	int sum = 0;
	int inner_sum = 0;
	int temp_start_index;
	int start_index = 0;
	int end_index;
	bool changed;
	for (int i = 0; i < n; i++) {
		inner_sum += m_array[i];
		if (sum < inner_sum){
			if (changed) {
				start_index = temp_start_index;
				changed = false;
			}
			sum = inner_sum;
			end_index = i;
		} 
		if (inner_sum < 0) {
			temp_start_index = i+1;
			inner_sum = 0;
			changed = true;
		}
	}
	cout << start_index << " " << end_index << "\n";
	cout << "sum:" << sum << "\n";
}

int get_random_number_between(int i, int j) {
	srand( (unsigned)time( NULL ) );
	int subtraction_random = rand()%(j-i);
	int num =  i + subtraction_random;
    return num;
}

void permutation1::run(int n) {
	unsigned int *permutaion = new unsigned int[n];
	bool unique;
	unsigned int c;
	for(int i = 0; i < n ; i++) {
		do {
			unique = true;
			c = get_random_number_between(0,n);
			for(int j = 0; j < i; j++) {
				if (c == permutaion[j]) 
					unique = false;
			}
		} while(!unique);
		permutaion[i] = c;
	}
	for (int i = 0; i < n; i++) {
		cout << permutaion[i] << " ";
	}
	cout << "\n";
	delete[] permutaion;
}

void permutation2::run(int n) {
	unsigned int *permutaion = new unsigned int[n];
	bool *used = new bool[n];
	bool unique;
	unsigned int c;
	for(int i = 0; i < n ; i++) {
		do {
			unique = true;
			c = get_random_number_between(0,n);
			if (used[c]) unique = false;
		} while(!unique);
		permutaion[i] = c;
		used[c] = true;
	}
	for (int i = 0; i < n; i++) {
		cout << permutaion[i] << " ";
	}
	cout << "\n";
	delete[] permutaion;
	delete[] used;
}	

void permutation3::run(int n) {
	unsigned int *permutaion = new unsigned int[n];
	int index;
	unsigned int temp;
	for(int i = 0; i < n ; i++) {
		permutaion[i] = i + 1;
	}
	for(int i = 0; i < n ; i++) {
		index = get_random_number_between(0,i+1);
		temp = permutaion[i];
		permutaion[i] = permutaion[index];
		permutaion[index] = temp;
	}
	delete[] permutaion;
}	

void sum1::run(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum++;
	}
	cout << "sum1:" << sum << "\n";
}
void sum2::run(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sum++;
		}
	}
	cout << "sum2:" << sum << "\n";
}
void sum3::run(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n * n; j++) {
			sum++;
		}
	}
	cout << "sum3:" << sum << "\n";
}
void sum4::run(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			sum++;
		}
	}
	cout << "sum4:" << sum << "\n";
}
void sum5::run(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i * i; j++) {
			for(int k = 0; k < j; k++) {
				sum++;
			}
		}
	}
	cout << "sum5:" << sum << "\n";
}
void sum6::run(int n) {
	int sum = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < i * i; j++) {
			if (j % i == 0) {
				for (int k = 0; k < j; k++) {
					sum++;
				}
			}
		}
	}
	cout << "sum6:" << sum << "\n";
}

void print_running_time(func_obj * func_obj,int n) {
	//prepare data
	
	//---------
	long start_time = duration_cast< microseconds >(
		system_clock::now().time_since_epoch()
	).count();
	//solve problem
	func_obj->run(n);
	//----------
	long end_time = duration_cast< microseconds >(
		system_clock::now().time_since_epoch()
	).count();
	cout << "The algorithm costs: " << end_time - start_time << " microsecond(s)" << "\n";
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


