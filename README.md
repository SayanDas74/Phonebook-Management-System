
# Phonebook Management System

A C++ Phonebook console application.


## About
This mini project is on a simple Phonebook Management System implemented in C++. It allows users to perform various phonebook operations, such as adding contacts, displaying all contacts, searching contacts by name or number, updating contact information, deleting contacts and more. 
## Algorithms Used
**Binary Search**: The binarySearch function implements the binary search algorithm. It is used to search for a specific name or number in the phonebook. Binary search is an efficient searching algorithm that works on sorted arrays by repeatedly dividing the search range in half until the desired element is found or the search range becomes empty.

**QuickSort**: The quickSort function implements the QuickSort algorithm. It is used to sort the arrays of names and numbers in the phonebook. QuickSort is a divide-and-conquer sorting algorithm that recursively divides the array into smaller subarrays and sorts them based on a pivot element.
## Functions Used
- [menu():](#menu) -----> Displays the main menu and returns the user's choice.\
- [binarySearch():](#binarySearch) -----> Performs binary search on a sorted array of strings to find a specific contact in the phonebook.\
- [quickSort():](#quickSort) -----> Sorts the arrays of names and numbers using the QuickSort algorithm.\
- [partition():](#partition) -----> Partitions the array for the QuickSort algorithm.\
- [contactExists():](#contactExists)-----> Checks if a contact with the same name or number already exists in the phonebook
## Source Code for Functions
### menu():
```cpp
int menu()
{
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t|           PHONEBOOK APPLICATION            |\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t|             [1] Add Contacts               |\n";
    cout << "\t\t\t\t|             [2] Display all Contacts       |\n";
    cout << "\t\t\t\t|             [3] Search by Name             |\n";
    cout << "\t\t\t\t|             [4] Search by Number           |\n";
    cout << "\t\t\t\t|             [5] Update                     |\n";
    cout << "\t\t\t\t|             [6] Delete                     |\n";
    cout << "\t\t\t\t|             [7] Delete All                 |\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t|             [8] Exit                       |\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tEnter your choice: ";
    int a;
    cin >> a;
    system("cls");
    return a;
}
```
### binarySearch():
```cpp
int binarySearch(string arr[], int l, int r, string key)
{
	if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid].compare(key) == 0)							//if key is middle element
            return mid;
        if (arr[mid].compare(key) > 0)							// If key smaller than mid, do recursion for left subarray
            return binarySearch(arr, l, mid - 1, key);
        return binarySearch(arr, mid + 1, r, key);				// Else in right subarray
    }
    // When element not present
    return -1;
}
```
### partition():
```cpp
int partition(string arr[], string arr2[], int low, int high)
{
    string pivot = arr[high];
    
    int i = (low - 1);											// Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {									  // If current element is smaller than the pivot
            i++;												  // Increment index of smaller element
            swap(arr[i], arr[j]);
            swap(arr2[i], arr2[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    swap(arr2[i + 1], arr2[high]);
    return (i + 1);
}
```
### quickSort():
```cpp
void quickSort(string arr[], string arr2[], int low, int high)
{
     if (low < high) 
	 {
        int pi = partition(arr, arr2, low, high);
        quickSort(arr, arr2, low, pi - 1);
        quickSort(arr, arr2, pi + 1, high);
    }
}
```
### contactExists():
```cpp
bool contactExists(string arr[], int size, string key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].compare(key) == 0)
            return true;
    }
    return false;
}
```

