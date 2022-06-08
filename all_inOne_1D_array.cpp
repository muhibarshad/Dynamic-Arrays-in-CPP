/*The 1D dynamic arrays full explained with best exmaples
 */
#include<iostream>
using namespace std;

//Functions Prototypes
void display();
void input(int *&arr, int size);
void output(int *&arr, int size);
void add(int *&arr, int &size);
void insert(int *&arr, int &size);
void remove(int *&arr, int &size);
void shrink(int *&arr, int &size);
void all_inOne_1D_array();

//Main
int main()
{
    all_inOne_1D_array();
    return 0;
}

//Display
void display()
{
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
    cout << "\t\t\t\t Enter 1 to add the element :" << endl;
    cout << "\t\t\t\t Enter 2 to insert the element at specific position the element :" << endl;
    cout << "\t\t\t\t Enter 3 to delete the element at specific position the element :" << endl;
    cout << "\t\t\t\t Enter 4 to display the elements in the array:" << endl;
    cout << "\t\t\t\t Enter 5 to shrink the size of the array:" << endl;
    cout << "\t\t\t\t Enter 0 to exit the program :" << endl;
}

//Input
void input(int *&arr, int size)
{
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

//output
void output(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

//add the element in the array
void add(int *&arr, int &size)
{
    int num;
    cout << "Enter the element that you want to adde in the end of the array:" << endl;
    cin >> num;
    //temp arr to increase the size of the new array
    int *tempArr = new int[size + 1];
    //copying previous array into the new array
    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }
    //delete the previous array
    delete[] arr;
    //give address of the pointer of first new array to the previous array
    arr = tempArr;
    //putting the value in the index
    arr[size] = num;
    //by refernce increase the size of the array
    size++;
}
 
//insert the element at specific index and increase the sizeof the array 1 index
void insert(int *&arr, int &size)
{
    int index;
    int num;
    cout << "Enter the element index that you wnat to enter the number:" << endl;
    cin >> index;
    cout << "Enter the element that you want to add at the " << index << " position :" << endl;
    cin >> num;
    /// temp arr to increase the size of the new array
    int *tempArr = new int[size + 1];
    // copying previous array into the new array
    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }
    // delete the previous array
    delete[] arr;
    // give address of the pointer of first new array to the previous array
    arr = tempArr;
    // putting the value in the index as 0
    arr[size] = 0;
    // by refernce increase the size of the array
    size++;

    //now inserting at the specific position
    for (int i = size - 1; i > index - 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = num;
}

//remove the element at specific element and decrease the size of the array 1 index
void remove(int *&arr, int &size)
{
    int num;
    cout << "Enter the element that you want to delete in  the array:" << endl;
    cin >> num;

    //firstly remove the element in the array
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            for (int j = i; j < size; j++)
                arr[j] = arr[j + 1];
            break;
        }
    }
    // now shrinking the size of the aray as one index
    // temp arr to increase the size of the new array
    int *tempArr = new int[size - 1];
    // copying previous array into the new array
    for (int i = 0; i < size - 1; i++)
    {
        tempArr[i] = arr[i];
    }
    // delete the previous array
    delete[] arr;
    // give address of the pointer of first new array to the previous array
    arr = tempArr;
    // by refernce increase the size of the array
    size--;
}

//shrink the size of the array how many times you want
void shrink(int *&arr, int &size)
{
    int num;
    cout << "Enter the number how many index that that you want to shrink from last:" << endl;
    cin >> num;
    //check 
    if (num <= size)
    {
        // temp arr to increase the size of the new array
        int *tempArr = new int[size - num];
        // copying previous array into the new array
        for (int i = 0; i < size - num; i++)
        {
            tempArr[i] = arr[i];
        }
        // delete the previous array
        delete[] arr;
        // give address of the pointer of first new array to the previous array
        arr = tempArr;
        // by refernce increase the size of the array
        size = size - num;
    }
    else
    {
        cout << "The entered number is graeter than the size of the array:" << endl;
    }
}

//All in one
void all_inOne_1D_array()
{
    //local varibles
    int size;
    int n;
    bool flag = false;
    cout << "Enter the size of the array:" << endl;
    cin >> size;

    //allocating the memory
    int *arr = new int[size];

    //input
    input(arr, size);

    //clearing the screen
    system("cls");

    //switch statements
    do
    {
        display();
        cin >> n;
        switch (n)
        {
        case 1:
        {
            add(arr, size);
            break;
        }
        case 2:
        {
            insert(arr, size);
            break;
        }
        case 3:
        {
            remove(arr, size);
            break;
        }
        case 4:
        {
            output(arr, size);
            break;
        }
        case 5:
        {
            shrink(arr, size);
            break;
        }
        case 0:
        {
            cout << "Quiting............" << endl;
            flag = true;
            break;
        }
        }
    } while (flag == false);
    delete[] arr;
    arr = NULL;
  
}
