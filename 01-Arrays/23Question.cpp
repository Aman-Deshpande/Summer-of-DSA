// Print all possible combinations of r elements in a given array of size n

// Problem Link: https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

#include <bits/stdc++.h>
using namespace std;

void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
	// Current combination is ready, print it
	if (index == r)
	{
		for (int j = 0; j < r; j++){
			cout << data[j] << " ";
        }
		cout << endl;
		return;
	}

	// When no more elements are there to put in data[]
	if (i >= n) return;

	// current is included, put next at next location
	data[index] = arr[i];
	combinationUtil(arr, n, r, index + 1, data, i + 1);

	// current is excluded, replace it with next (Note that
	// i+1 is passed, but index is not changed)
	combinationUtil(arr, n, r, index, data, i+1);
}


void printCombination(int arr[], int n, int r)
{
	// A temporary array to store all combination one by one
	int data[r];

	// Print all combination using temporary array 'data[]'
	combinationUtil(arr, n, r, 0, data, 0);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int r = 3;
	int n = sizeof(arr)/sizeof(arr[0]);
	printCombination(arr, n, r);
	return 0;
}
