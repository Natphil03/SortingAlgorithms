//Import Libraries
#include <stdio.h>
#include <stdbool.h>

//Declare Functions
void bubbleSort(int numArray[], int nsizeOfArray);
void swap(int* jPointer, int* jPointerPlus1);
void output(int numArray[], int sizeOfArray);

int main() //Starting point of program
{

	int numArray[] = { 64, 34, 25, 12, 22, 11, 90, 59, 52, 67, 93, 13, 64, 2, 6, 2, 7, 9 };//data set
	int sizeOfArray = sizeof(numArray) / sizeof(numArray[0]);//gets size of array

	bubbleSort(numArray, sizeOfArray);
	printf_s("Sorted: \n");
	output(numArray, sizeOfArray);

	return 0;
}

void bubbleSort(int numArray[], int sizeOfArray)
{
	int i, j;
	for ( i = 0; i < sizeOfArray - 1; i++)//goes through array
	{
		for (j = 0; j < sizeOfArray-i-1; j++)//for every 'i'th element, check if greater and swap if true
		{
			if (numArray[j] > numArray[j+1])
			{
				swap(&numArray[j], &numArray[j + 1]);//swap items
			}
		}
	}
}

void swap(int* jPointer, int* jPointerPlus1)
{
	int temp;
	temp = *jPointer;//stores value of j in temporary variable
	*jPointer = *jPointerPlus1;//changes j to j+1
	*jPointerPlus1 = temp;//stores temp in j+1 effectively swapping 
}

void output(int numArray[], int sizeOfArray)
{
	int i;
	for (i = 0; i < sizeOfArray; i++)//loops through new 
	{
		printf_s("%d", numArray[i]);
		printf_s("\n");
	}
}