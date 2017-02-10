#include <iostream>
using namespace std;

// Print an array
// arr - the array to print
// size - size of the array
void PrintArray(int arr[], int size)
{
    for(int i=1; i<=size; i++)
    {
        cout << arr[i-1] << " ";
    }
}

// Sort an array using Selection Sort
// arr - the array to print
// size - size of the array
void SortArrayUsingSelectionSort(int arr[], int size)
{
    // minElement - integer variable to hold the minimum element (integer number) of the array
    // temp - integer variable to hold the temporary element (integer number)
    int minElement, temp;
    for (int i=0; i<size-1; ++i)
    {
        //Finding the minimum element in the unsorted array
        //Assume it is the first element
        minElement = i;

        // Loop through the array to find the minimum element
        for (int j=(i+1); j<size; ++j)
        {
          if (arr[j] < arr[minElement])
          {
            //Found a new minimum position
            minElement = j;
          }
        }

        // Swap the values
        temp = arr[i];
        arr[i] = arr[minElement];
        arr[minElement] = temp;
    }
}

// Search for an element in an array via Tertiary Search (using recursion)
// arr - the array from where to search a particular element
// numberToSearch - the element to search
// leftIndex - index at the left side
// rightIndex - index at the right side
int TertiarySearchUsingRecursion(int arr[], int numberToSearch, int leftIndex, int rightIndex)
{
   if (rightIndex >= leftIndex)
   {
        // First boundary - add 1/3rd of length to start
        int middle1 = leftIndex + (rightIndex-leftIndex)/3;

        // Second boundary - add 2/3rd of length to start
        int middle2 = leftIndex + 2*(rightIndex-leftIndex)/3;

        // If the number to search is present at 'middle1'
        if (arr[middle1] == numberToSearch)
            return middle1;

        // If the number to search is present at 'middle2'
        else if (arr[middle2] == numberToSearch)
            return middle2;

        // If the number to search is present in the left one-third of the array
        else if (numberToSearch < arr[middle1])
            return TertiarySearchUsingRecursion(arr, numberToSearch, leftIndex, (middle1-1));

        // If the number to search is present in the right one-third of the array
        else if (numberToSearch > arr[middle2])
            return TertiarySearchUsingRecursion(arr, numberToSearch, (middle2+1), rightIndex);

        // If the number to search is present in the middle one-third of the array
        else
            return TertiarySearchUsingRecursion(arr, numberToSearch, middle1, middle2);
   }
   // When the element is not present in the array, return -1
   return -1;
}

int main()
{
    int size;
    cout << "Please enter the array size: ";
    cin >> size;

    // Declaring an integer array of size (provided by the user)
    int array[size];

    // Filling up the array
    for(int i=1; i<=size; i++)
    {
        cout << "Enter the number: ";
        cin >> array[i-1];
    }

    // Printing the UNSORTED array
    cout << "Printing the UNSORTED array: " << '\n';
    PrintArray(array, size);

    // Sorting the array  using Selection Sort
    SortArrayUsingSelectionSort(array, size);

    // Printing the SORTED array
    cout << '\n' << "Printing the SORTED array: " << '\n';
    PrintArray(array, size);

    int number;
    cout <<  '\n' << "Enter the number to search: ";
    cin >> number;

    int indexOfNumber = TertiarySearchUsingRecursion(array, number, 0, (size-1));
    if(indexOfNumber > 0)
        cout << "The number EXISTS in the array and the index of the number is: " << indexOfNumber << '\n';
    else
        cout << "The number does not exist in the array!" << '\n';

    return 0;
}
