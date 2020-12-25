
#include <iostream>
using namespace std;

// Merges two sorted subarrays of A[].
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r)
{
    //Variables for the left and right side of the array.
    int x, y, z;
    int aL = m - l + 1;
    int aR = r - m;

    //temp arrays.
    int L[aL], R[aR];

    for(x  = 0; x < aL; x++)
        L[x] = A[l + x];
    for(y = 0; y < aR; y++)
        R[y] = A[m + 1 + y];

    x = 0;
    y = 0;
    z = l;
    while (x< aL && y < aR)
    {
        if (L[x] <= R[y])
        {
            A[z] = L[x];
            x++;
        }
        else
            {
            A[z] = R[y];
            y++;
        }
        z++;
    }
    while(x < aL)
    {
        A[z] = L[x];
        x++;
        z++;
    }

    while(y < aR)
    {
        A[z] = R[y];
        y++;
        z++;
    }

}

// using mergeSort to sort sub-array A[l..r]
// l is for left index and r is right index of the
// sub-array of A[] to be sorted
void mergeSort(int A[], int l, int r)
{
    if(l < r)
    {
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, m, r);

    }
}


int main()
{
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;

	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}

	int* A = new int [n];

	cout << "Please enter each element in the array" << endl;
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}

    cout << "Given array A[] is: ";
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;


    mergeSort(A, 0, n-1);

    cout << "After mergesort, sorted array A[] is: ";
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;


	delete [] A;
    return 0;
}