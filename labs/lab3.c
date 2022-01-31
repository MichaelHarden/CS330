#include <stdio.h>

/**
 * insertion sort, sorts the array passed in the parameter with an implementation of the insertion sort algorithm
 *
 * params:
 *      array: a pointer to the array that needs to be sorted
 *      size: the number of integers in the array
 *
 */
int *insertionSort(int array[], int size)
{
    // loop through array starting with the second element.
    // this is because we are assuming the first element is sorted.
    int i;
    for (i = 1; i < size; i++)
    {

        // the key is the current element that needs to be inserted
        int key = *(array + i);
        int j = i - 1;

        // j is indexing the array backward looking for the spot to insert the key
        // when j is negitave, the element should be inserted at the end of the list
        // when the value at the index j is less than the key, the next index (j + 1)
        // is where the key should be inserted
        while ((j >= 0) && (*(array + j) > key))
        {
            // scooting each element that is greater than the key one spot forward
            *(array + j + 1) = *(array + j);
            j--;
        }

        *(array + j + 1) = key;
    }

    return array;
}

/**
 * selection sort, sorts the array passed in the parameter with an implementation of the selection sort algorithm
 *
 * params:
 *      array: a pointer to the array that needs to be sorted
 *      size: the number of integers in the array
 *
 */
int *selectionSort(int array[], int size)
{
    // i is  iterating from the first to the second to last element of the list.
    // This is becasue once the array has been sorted up to the second to last element, the last element
    // will be in its proper place
    int i;
    for (i = 0; i < size - 1; i++)
    {

        // keeps track of the index of current smallest element found so far in this iteration
        int minValueIndex = i;

        // loops throught unsorted section of the array to find the smallest element
        int j;
        for (j = i + 1; j < size; j++)
        {
            if (*(array + j) < *(array + minValueIndex))
            {
                minValueIndex = j;
            }
        }
        // once the smallest has been found, it is inserted in to index i
        // if i is already the smallest, then the next iteration of the loop is run.
        if (minValueIndex != i)
        {
            int temp = *(array + i);
            *(array + i) = *(array + minValueIndex);
            *(array + minValueIndex) = temp;
        }
    }
    return array;
}

/**
 * main is always run first. Its job is to take the user input, and sort the provided integers
 */
int main(int argc, char const *argv[])
{
    // promts user for number of elements to sort
    // this is to know how many times to run the following for loop
    printf("Enter numer of integers that will be sorted, then press enter\n");
    int size;
    scanf("%d", &size);

    // promts user to enter the integers to be sorted
    printf("Enter all integers to be sorted. Press enter between each number\n");
    int array[size];
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &(*(array + i)));
    }

    // promts user to select a sorting option
    printf("How would you like to sort your integers?\n\tSelection Sort: enter 0\n\tInsertion Sort: enter 1\n");
    int chosen;
    scanf("%d", &chosen);

    switch (chosen)
    {
    case 0: // 0 selects to sort with selectionSort
        selectionSort(array, size);
        break;
    case 1: // 1 selects to sort with insertionSort
        insertionSort(array, size);
        break;
    default:
        printf("Not an option");
        break;
    }

    //prints out the array after it has been sorted
    int j;
    printf("\n[");
    for (j = 0; j < size - 1; j++)
    {
        printf("%d, ", *(array + j));
    }
    printf("%d]\n\n", *(array + size - 1));
    return 0;
}
