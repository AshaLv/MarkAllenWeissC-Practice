#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>

#define NUM 100000

using namespace std;
using namespace std::chrono;



void pre_populate_to_arr(vector<float> & arr);
void linear_sort(vector<float> & arr);
void linear_sort_k_elements(vector<float> & arr);
float get_kth_maximum_element(const vector<float> & arr, int k);

int main() {
	vector<float> arr;
	pre_populate_to_arr(arr);
	long start_time = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
	).count();
	// linear_sort(arr);
	linear_sort_k_elements(arr);
	cout << "The kth maximum element is: " << get_kth_maximum_element(arr,NUM/2) << "\n\n";
	long end_time = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
	).count();
	cout << "The count of elements in this array: " << NUM << "\n";
	cout << "The algorithm costs: " << end_time - start_time << " millisecond(s)" << "\n";
	return 0;
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


