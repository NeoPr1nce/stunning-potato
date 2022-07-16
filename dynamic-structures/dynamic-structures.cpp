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

/*
* root -> xA -> xB -> xC -> xD -> xE -> NULL
*         1      2     3     4     5
* root = root->next:
* root -> xB -> xC -> xD -> xE
*          2     3     4     5
* root -> xB -> xC -> n -> xD -> xE
* 1. найти нужный элемент по индексу i
* сделать от него шаг назад
*   2.1 провер€ть значени€ root до момента нахождени€ i
*   2.2 присвоить q = элемент по индексу i-1
* добавить новый элемент списка после i-1
*    xA -> xB -> xC -> xD -> xE
*     ^ root
*    xA -> xB -> xC -> n -> xD -> xE
*   
*    before:
* q->    xC = next  = xD
*             value = 3
* root-> xD = next  = xE
*             value = 4
*
*    after:
*q->     xC = next  = n
*             value = 3
*         n = next  = xD
*             value = ??
*root->  xD = next  = xE
*             value = 4
*
*    xA -> xB -> xC -> xD -> xE
*     ^ root
*    q -> NULL
*    xA -> xB -> xC -> xD -> xE
*     ^     ^ root
*    q
*    xA -> xB -> xC -> xD -> xE
*          ^     ^ root
*          q
*/

template <typename T> node<T>* getElement(node<T> *&root)
{
    //1. get rid from console and keyboard input dependency
    //2. fix insertion location
    int i = 0;
        cout << "i" << endl;
        cin >> i;
    int newValue = 0;
    cout << "newValue" << endl;
        cin >> newValue;
    if (i == 0)
    {
        return insertAtStart(root, newValue);
    }

    // предыдущий элемент
    node<T> *q = NULL;
    node<T> *p = root;
    int iterator = -1;
    while (p != NULL )
    {
        q = p;
        p = p->next;
        iterator++;
        if (iterator == i)
        {
            node<T>* newNode = new node<T>();
            newNode->value = newValue;
            newNode->next = p;
            q->next = newNode;
            return newNode;
        }
    }
}

// 1. добавить в начало списка
template <typename T> node<T>* insertAtStart(node<T> *&root, T valueToInsert)
{
    /*
    *    before:
    *    root = next  = xD
    *           value = 3
    *
    *    after:
    *    newValue = next = root
    *              value = valueToInsert
    *        root = next = xD
    *              value = 3
    */
    node<T>* newValue = new node<T>();
    newValue->value = valueToInsert;
    newValue->next = root;
    root = newValue;
    return root;
}

// 2. добавить в конец списка
template <typename T> node<T>* insertAtEnd(node<T>* root, T valueToInsert)
{
    /*
   * xA -> xB -> xC -> xD -> xE
   *    
   *      before:
   *    root = next  = xA
   *           value = ?
   *           ....
   *    xE   = next = NULL
   *           value= ?
   *
   *    after:
   *    xE       -> next = newValue
   *                value= ?
   *    newValue -> next = NULL
   *                value = ?
   */
    node<T>* newValue = new node<T>();
    newValue->value = valueToInsert;
    while (root != NULL && root->next != NULL)
    {
        root = root->next;
    }
    root->next = newValue;
    newValue->next = NULL;
    return newValue;
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
    cout << endl << "**********" << endl;
    insertAtEnd<int>(list, 4);
    traverseList<int>(list);
    // list -> xA -> xB -> xC -> xD -> xE
    getElement<int>(list);
    // if i == 0
    // returnedPointer -> x0 -> xA -> xB -> xC -> xD -> xE
    //                           ^- list
    traverseList<int>(list);
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
