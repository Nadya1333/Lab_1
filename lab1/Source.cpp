#include <iostream>    //Chekulaeva N., 21BI1
#include <ctime>
#include <chrono>

using namespace std;

//#1
void bubbleSort(int arrLen, int* arr) {
	int c;
	for (int i = 0; i < arrLen; i++) {             //the element is compared with the next
		for (int j = i + 1; j < arrLen; j++) {
			if (arr[i] > arr[j]) {                //if the elements are not in the correct order, then they are swapped
				c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}
}

//#2
int findSmPos(int arr[], int firstPos, int arrLen) {
	int smPos = firstPos;
	for (int i = firstPos; i < arrLen; i++) {           // finding the smallest element
		if (arr[i] < arr[smPos])
			smPos = i;                                  // put it at the beginning
	}
	return smPos;
}

void selectionSort(int arrLen, int* arr) {
	for (int i = 0; i < arrLen; i++) {                 //get index of smallest element
		int smPos = findSmPos(arr, i, arrLen);
		swap(arr[i], arr[smPos]);                  // swap the found smallest element
	}
}

//#3
void heapify(int mass[], int massLen, int root) {
	int big = root;    //initialize the largest element as the root
	int first = 2 * root + 1;  //left child
	int last = 2 * root + 2; //right child
	if (first<massLen && mass[first]>mass[big]) {
		big = first;
	}if (last<massLen && mass[last]>mass[big]) {
		big = last;
	}if (big != root) {
		swap(mass[root], mass[big]);
		heapify(mass, massLen, big);   //recursively convert a subtree into a heap
	}
}

void heapSort(int arrLen, int* arr) {
	for (int i = arrLen / 2 - 1; i >= 0; i--) {      //building a heap
		heapify(arr, arrLen, i);
	}
	for (int i = arrLen - 1; i >= 0; i--) {      //retrieving elements from the heap one by one
		swap(arr[0], arr[i]);               //move the current root to the end
		heapify(arr, i, 0);              //call procedure heapify on the reduced heap
	}
}

void printArray(int n, int* arr) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void fillArray(int n, int* arr) {
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 200 - 100;
	}
}

int main(){   
	//#1
	int arr[10] = { 34, 77, -14, 2, 4, 7, 93, 37, -7, 12 };
	cout << "#1 Sourse array: " << endl;
	printArray(10, arr);
	cout << endl;

	bubbleSort(10, arr);

	cout << "Bubble Sorted array: " << endl;
	printArray(10, arr);
	cout << endl;
	cout << endl;

	//#2
	int ar[9] = { 34, 77, -14, 4, 7, 93, 37, -21, 12 };
	cout << "#2 Sourse array: " << endl;
	printArray(9, ar);
	cout << endl;
	selectionSort(9, ar);
	cout << "Selection Sorted array: " << endl;
	printArray(9, ar);
	cout << endl;
	cout << endl;

	//#3
	int mass[8] = { 34, -77, -14, 4, 7, 93, 37, -7 };
	cout << "#3 Sourse array: " << endl;
	printArray(8, mass);
	cout << endl;
	heapSort(8, mass);
	cout << "Heap Sorted array: " << endl;
	printArray(8, mass);
	cout << endl;

	

	for (int i = 10; i <= 100000;) {
		cout << "Number of elements: " << i << endl;
		const int n = i;
		int* a = new int[n];
		srand(time(nullptr));

		fillArray(n, a);
		std::chrono::steady_clock clock;
		auto start = clock.now();
		bubbleSort(n, a);
		auto end = clock.now();
		std::chrono::duration<double> ans = end - start;
		std::cout << "Time for Bubble sort:" << ans.count() << " secs" << std::endl;

		fillArray(n, a);
		start = clock.now();
		selectionSort(n, a);
		end = clock.now();
		ans = end - start;
		std::cout << "Time for Selection sort: " << ans.count() << " ms\n";

		fillArray(n, a);
		start = clock.now();
		heapSort(n, a);
		end = clock.now();
		ans = end - start;
		std::cout << "Time for Heap sort: " << ans.count() << " ms\n";

		i *= 10;
		cout << endl;
	}
	return 0;
}
	
