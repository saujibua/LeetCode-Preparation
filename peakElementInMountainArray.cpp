// CPP program for the above approach
#include<bits/stdc++.h>
using namespace std;

// Function to find the index of
// the peak element in the array
int findPeak(vector<int> arr)
{

// Stores left most index in which
// the peak element can be found
int left = 0;

// Stores right most index in which
// the peak element can be found
int right = arr.size() - 1;
while (left < right) 
{

	// Stores mid of left and right
	int mid = left + (right - left) / 2;

	// If element at mid is less than
	// element at (mid + 1)
	if (arr[mid] < arr[mid + 1]) 
	{

	// Update left
	left = mid + 1;
	}
	else
	{

	// Update right
	right = mid;
	}
}
return left;
}

// Function to perform binary search in an
// a subarray if elements of the subarray
// are in an ascending order
int BS(int X, int left, int right,
	vector<int> arr)
{
while (left <= right)
{

	// Stores mid of left and right
	int mid = left + (right - left) / 2;

	// If X found at mid
	if (arr[mid] == X) 
	{
	return mid;
	}

	// If X is greater than mid
	else if (X > arr[mid])
	{

	// Update left
	left = mid + 1;
	}

	else
	{

	// Update right
	right = mid - 1;
	}
}
return -1;
}

// Function to perform binary search in an
// a subarray if elements of the subarray
// are in an descending order
int reverseBS(int X, int left, int right, vector<int> arr)
{
while (left <= right) 
{

	// Stores mid of left and right
	int mid = left + (right - left) / 2;

	// If X found at mid
	if (arr[mid] == X)
	{
	return mid;
	}

	else if (X > arr[mid]) 
	{

	// Update right
	right = mid - 1;
	}
	else
	{

	// Update left
	left = mid + 1;
	}
}
return -1;
}

// Function to find the smallest index of X
void findInMA(int X, vector<int> mountainArr)
{

// Stores index of peak element in array
int peakIndex = findPeak(mountainArr);

// Stores index of X in the array
int res = -1;

// If X greater than or equal to first element
// of array and less than the peak element
if (X >= mountainArr[0] && X <= mountainArr[peakIndex]) 
{

	// Update res
	res = BS(X, 0, peakIndex, mountainArr);
}

// If element not found on
// left side of peak element
if (res == -1) 
{

	// Update res
	res = reverseBS(X, peakIndex + 1,
					mountainArr.size() - 1,
					mountainArr);
}

// Print res
cout<<res<<endl;
}

// Driver Code
int main()
{

// Given X
int X = 3;

// Given array
vector<int> list{1, 2, 3, 4, 5, 3, 1};

// Function Call
findInMA(X, list);
}

