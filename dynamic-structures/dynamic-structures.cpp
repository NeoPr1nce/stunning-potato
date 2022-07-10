// dynamic-structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T> struct node 
{
    node<T>* next;
    T value;
};

template <typename T> T getByIndex(node<T>* root, int index)
{
    // passing null as list return null result
    if (root == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < index; i++)
    {
        root = root->next;
        // index is higher than number of elements in list
        if (root == NULL)
        {
            return NULL;
        }
    }
    return root->value;
}

template <typename T> void traverseList(node<T>* root)
{
    while (root != NULL)
    {
        cout << root->value << ' ';
        root = root->next;
    }
}

/*
* {
*   next: pointer
*   value: T
* }
*
* traverse until current node == argument value
* index:  0      1     2     3     4
* root -> xA -> xB -> xC -> xD -> xE <- next
*         1      2     3     4     5
*                                  ^- value
*
*/
int getIndexByValue(node<int>* root, int value)
{
    int index = 0;
    while (root != NULL)
    {
        if (root->value == value)
        {
            return index;
        }

        root = root->next;
        index++;
    }
    return -1;
}

/*
* root -> xA -> xB -> xC -> xD -> xE -> NULL
*         1      2     3     4     5
* root = root->next:
* root -> xB -> xC -> xD -> xE
*          2     3     4     5
*/
template <typename T> int getLength(node<T>* root)
{
    int i = 0;
    while (root != NULL)
    {
        root = root->next;
        i++;
    }
    return i;
}

int main()
{
    // 1 -> 2 -> 3
    node<int>* list = new node<int>();
    list->value = 1;
    list->next = new node<int>();
    list->next->value = 2;
    list->next->next = new node<int>();
    list->next->next->value = 3;

    traverseList<int>(list);
    cout << endl << getLength<int>(list);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
