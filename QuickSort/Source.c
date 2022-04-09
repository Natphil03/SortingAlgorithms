#include <stdio.h>
//defining methods
void swap(int* num1, int* num2);
void printArray(int arrayNums[], int size);
void quickSort(int arrayNums[], int low, int high);
int partition(int arrayNums[], int low, int high);

int main()
{
	int arrayNums[] = { 64, 34, 25, 12, 22, 11, 90, 59, 52, 67, 93, 13, 64, 2, 6, 2, 7, 9 };//data set
	int size = sizeof(arrayNums) / sizeof(arrayNums[0]);//gets size of array
	quickSort(arrayNums, 0, size - 1);
	printf_s("Sorted:\n");
	printArray(arrayNums, size);
	return 0;
}

void swap(int* num1, int* num2) //using pointers, no need to return 
{
	int temp;
	temp = *num1; //stores value in temp
	*num1 = *num2; // overwrites old value with new value of next index
	*num2  = temp; // writes new index element in new index
}

int partition(int arrayNums[], int low, int high) 
{
	int pivot = arrayNums[high];//pivot starts at top of array - 1
	int i = (low - 1); // partition index starts at beginning of array

	for (int k = low; k <= high - 1; k++)//iterate through bottom to top of array swapping elements
	{
		if (arrayNums[k] < pivot)
		{
			i++;//increment partition index
			swap(&arrayNums[i], &arrayNums[k]);//swap elements
		}
	}
	swap(&arrayNums[i + 1], &arrayNums[high]);
	return (i + 1);
}

void quickSort(int arrayNums[], int low, int high) 
{
	if (low < high)
	{
		int partitionIndex = partition(arrayNums, low, high);//gets partition index from method
		quickSort(arrayNums, low, partitionIndex - 1);
		quickSort(arrayNums, partitionIndex + 1, high);
	}
}

void printArray(int arrayNums[], int size)//output sorted array
{
	for (int i = 0; i < size; i++) //iterate through sorted array
	{
		printf_s("%d", arrayNums[i]);
		printf_s("\n");
	}
}