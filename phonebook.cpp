#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int menu();

int k = 0;

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
 
void quickSort(string arr[], string arr2[], int low, int high)
{
     if (low < high) 
	 {
        int pi = partition(arr, arr2, low, high);
        quickSort(arr, arr2, low, pi - 1);
        quickSort(arr, arr2, pi + 1, high);
    }
}

bool contactExists(string arr[], int size, string key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].compare(key) == 0)
            return true;
    }
    return false;
}

int main()
{
    string name[100];
    string no[100];
    int selec = 0;
    do
    {
    	selec = menu();
    	//-----ADD CONTACT------
        if (selec == 1)
        {
        	string new_name, new_number;
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t Enter Name: ";
            cin >> new_name;											//k is the index of no. of entries
            cout << "\n\t\t\t\t Enter Phone No: ";
            cin >> new_number;
            bool nameExists = contactExists(name, k, new_name);
    		bool numberExists = contactExists(no, k, new_number);
    		if (nameExists || numberExists)
    		{
		        cout << "\n\n\t\t\t\t CONTACT WITH SAME NAME OR NUMBER \n\t\t\t\t ALREADY EXISTS IN THE PHONEBOOK !!" << endl;
				cout << "\n\n\t\t\t\t Press Enter for the menu...";
				cin.ignore(); 							
            	cin.get();
    		}
    		else
		    {
		        name[k] = new_name;
		        no[k] = new_number;
		        k++;
		    }
            system("cls");
        }
        
        //------DISPLAY CONTACTS------
        else if (selec == 2)
        {
        	int flag = 0;
        	quickSort(name, no, 0, k-1);
        	cout<<"\n\n\n\n\n\n\n\n";
            for (int i = 0; i < k; i++)
            {
                if (name[i] != "NULL")
                	{flag++;
                    cout << "\t\t\t\t Name: " << name[i] << "\t\tPhone no: " << no[i] << endl;}
            }
            if (flag==0)
            	cout<<"\n\n\t\t\t\t No contacts found...";
            cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
            cin.ignore(); 							// Wait for the user to press Enter before going back to the menu
            cin.get();
            system("cls"); 							// Clear the screen after displaying contacts
        }
        
        //-------SEARCH BY NAME------
        else if(selec == 3)
        {
        	string temp;
        	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t Enter Name to be searched: ";
        	cin>>temp;
        	quickSort(name, no, 0, k-1);  										//sort the numbers using Quick Sort
        	int index = (binarySearch(name, 0, k-1, temp));						//Binary Search to search the number
        	if(index!=-1)															
        	{
        		cout<<"\n\t\t\t\t Name: "<<name[index]<<"\t\t Number: "<<no[index];
        		cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
        	}
        	else
        	{
        		cout<<"\n\t\t\t\t NAME NOT FOUND !!";
        		cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
			}
			cin.ignore(); 		
            cin.get();
            system("cls");
		}
		
        //------SEARCH BY NUMBER-------
        else if(selec == 4)
        {
        	string temp;
        	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t Enter Number to be searched: ";
        	cin>>temp;
        	quickSort(no, name, 0, k-1);  						
        	int index = (binarySearch(no, 0, k-1, temp));
        	if(index!=-1)		
        	{
        		cout<<"\n\t\t\t\t Name: "<<name[index]<<"\t\t Number: "<<no[index];
        		cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
        	}
        	else
        	{
        		cout<<"\n\t\t\t\t NUMBER NOT FOUND !!";
        		cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
			}
			    cin.ignore(); 		
            	cin.get();
            	system("cls");
		}
		
		//-----UPDATE CONTACT------
		else if (selec == 5)
		{
		    cout << "\n\n\n\n\n\n\n\n\t\t\t\t Search by- \n\t\t\t\t\t 1. Name\n\t\t\t\t\t 2. Number\n\t\t\t\t\t Enter your choice: ";
		    int choice;
		    string temp;
		    cin >> choice;
		    system("cls");
		    if (choice == 1)
		    {
		        cout << "\n\n\n\n\n\n\n\t\t\t\t Enter name to be updated: ";
		        cin >> temp;
		        quickSort(name, no, 0, k - 1); // sort both name and no arrays using Quick Sort
		        int index = binarySearch(name, 0, k - 1, temp);
		        if (index != -1)
		        {
		            cout << "\n\t\t\t\t Name: " << name[index] << "\t\t Number: " << no[index];
		            cout << "\n\n\t\t\t\t Do you want to update -\n\t\t\t\t\t1. Name\n\t\t\t\t\t2. Number\n\t\t\t\t\tEnter your choice: ";
		            cin >> choice;
		            if (choice == 1)
		            {
		                string newname;
		                cout << "\n\t\t\t\t Enter new name: ";
		                cin >> newname;
		                name[index] = newname;
		                cout << "\n\t\t\t\t CONTACT UPDATED SUCCESSFULLY !!";
		            }
		            else if (choice == 2)
		            {
		                string newno;
		                cout << "\n\t\t\t\t Enter new number: ";
		                cin >> newno;
		                no[index] = newno;
		                cout << "\n\t\t\t\t CONTACT UPDATED SUCCESSFULLY !!";
		            }
		            else
		            {
		                cout << "\n\t\t\t\t INVALID CHOICE !!";
		            }
		        }
		        else
		        {
		            cout << "\n\t\t\t\t NAME NOT FOUND !!";
		        }
		    }
		    else if (choice == 2)
		    {
		        cout << "\n\n\n\n\n\n\n\t\t\t\t Enter number to be updated: ";
		        cin >> temp;
		        quickSort(no, name, 0, k - 1);
		        int index = binarySearch(no, 0, k - 1, temp);
		        if (index != -1)
		        {
		            cout << "\n\t\t\t\t Name: " << name[index] << "\t\t Number: " << no[index];
		            cout << "\n\n\t\t\t\t Do you want to update \n\t\t\t\t\t1. Name\n\t\t\t\t\t2. Number\n\t\t\t\t\tEnter your choice: ";
		            cin >> choice;
		            if (choice == 1)
		            {
		                string newname;
		                cout << "\t\t\t\t Enter new name: ";
		                cin >> newname;
		                // Find the original index in the name array
		                int originalIndex = binarySearch(name, 0, k - 1, name[index]);
		                name[originalIndex] = newname;
		                cout << "\n\t\t\t\t CONTACT UPDATED SUCCESSFULLY !!";
		            }
		            else if (choice == 2)
		            {
		                string newno;
		                cout << "\t\t\t\t Enter new number: ";
		                cin >> newno;
		                no[index] = newno;
		                cout << "\n\t\t\t\t CONTACT UPDATED SUCCESSFULLY !!";
		            }
		            else
		            {
		                cout << "\n\t\t\t\t INVALID CHOICE !!";
		            }
		        }
		        else
		        {
		            cout << "\n\t\t\t\t NUMBER NOT FOUND !!";
		        }
		    }
		    else
		    {
		    	cout<<"\n\t\t\t\t INVALID CHOICE !!";
			}
		
		    cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
		    cin.ignore();
		    cin.get();
		    system("cls");
		}

		//-----DELETE CONTACT------
		else if (selec == 6)
		{
		    cout << "\n\n\n\n\n\n\n\n\t\t\t\t Delete Contact By: \n\t\t\t\t\t 1. Name\n\t\t\t\t\t 2. Number\n\t\t\t\t\t Enter your choice: ";
		    int choice;
		    cin >> choice;
		    system("cls");
		
		    if (choice == 1)
		    {
		        string temp;
		        cout << "\n\n\n\n\n\n\n\n\t\t\t\t Enter Name to be deleted: ";
		        cin >> temp;
		        quickSort(name, no, 0, k - 1);
		        int index = binarySearch(name, 0, k - 1, temp);
		        if (index != -1)
		        {
		            cout << "\n\t\t\t\t CONTACT DELETED SUCCESSFULLY";
		            for (int i = index; i < k - 1; i++) 		// Shift elements, delete
		            {
		                name[i] = name[i + 1];
		                no[i] = no[i + 1];
		            }
		            k--;
		
		            // After deletion, sort the arrays again
		            quickSort(name, no, 0, k - 1);
		        }
		        else
		        {
		            cout << "\n\t\t\t\t NAME NOT FOUND !!";
		        }
		    }
		    else if (choice == 2)
		    {
		        string temp;
		        cout << "\n\n\n\n\n\n\n\n\t\t\t\t Enter Number to be deleted: ";
		        cin >> temp;
		        quickSort(no, name, 0, k - 1);
		        int index = binarySearch(no, 0, k - 1, temp);
		        if (index != -1)
		        {
		            cout << "\n\t\t\t\t CONTACT DELETED SUCCESSFULLY";
		            for (int i = index; i < k - 1; i++) // Shift elements, delete
		            {
		                no[i] = no[i + 1];
		                name[i] = name[i + 1];
		            }
		            k--;
		
		            // After deletion, sort the arrays again
		            quickSort(name, no, 0, k - 1);
		        }
		        else
		        {
		            cout << "\n\t\t\t\t NUMBER NOT FOUND !!";
		        }
		    }
		    else
		    {
		        cout << "\n\n\n\n\n\n\n\n\t\t\t\t INVALID CHOICE";
		    }
		
			cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
		    cin.ignore();
		    cin.get();
		    system("cls");
		}

		//--------DELETE ALL------
		else if(selec == 7)
		{
			k = 0;
    		cout << "\n\n\n\n\n\n\n\n\t\t\t\t ALL CONTACTS DELETED SUCCESSFULLY";
    		cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
    		cin.ignore();
    		cin.get();
    		system("cls");
		}
		
		//----- EXIT THE APPLICATION --------
		else if(selec == 8)
		{
			cout << "\n\n\n\t\t\t\t Phonebook application Closed";
            break; 	
		}
		
		else
        {
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t INVALID CHOICE";
    		cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
    		cin.ignore();
    		cin.get();
    		system("cls");
        }
    } while (true);
    return 0;
}

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
