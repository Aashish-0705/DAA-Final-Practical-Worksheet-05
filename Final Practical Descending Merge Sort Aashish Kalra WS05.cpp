#include <iostream>
using namespace std;
void merge(int array[], int const left, int const mid, int const right)
{
    auto const int subArrayOne = mid - left + 1;
    auto const int subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    for (auto int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto int indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left; 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
    auto int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
int main()
{
    int arr[20],x;
	cout<<"Enter the number of elements you want to enter:";
	cin>>x;
    for(int i=0;i<x;i++)
{
	cout<<"Enter the element "<<(i+1)<<":";
	cin>>arr[i];
}
    mergeSort(arr, 0, x-1);
    cout << "\nSorted array is \n";
    for(int j=0;j<x;j++)
{
	cout<<arr[j]<<"\n";
}
    return 0;
}
