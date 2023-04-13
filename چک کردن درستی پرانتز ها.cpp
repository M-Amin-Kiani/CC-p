
#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class Node
{
public:

    T data;
    Node<T>* next;

    Node(T d, Node <T>* n)
    {
        data = d;
        next = n;
    }
};

template <typename T>
class one_LinkedList
{
public:

    Node<T>* head, * tail;
    int size;

    one_LinkedList()
    {
        size = 0;
        head = tail = nullptr;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    T First()
    {
        if (IsEmpty())
        {
            return nullptr;
        }

        return head->data;
    }
    void addFisrt(T d)
    {
        head = new Node <T>(d, head);

        if (size == 0)
        {
            tail = head;
        }

        size++;
    }

    T removeFirst()
    {
        if (IsEmpty())
        {
            return '\0';
        }

        Node<T>* tmp_deleted = head;

        T first_of_l = head->data;
        head = head->next;
        delete tmp_deleted;

        size--;

        if (size == 0)
        {
            tail = nullptr;
        }

        return first_of_l;
    }
};

template <class T>
class stack_with_linkedlist
{
public:

    one_LinkedList <T>* my_stack = new one_LinkedList<T>();

    bool Is_Empty()
    {
        return my_stack->IsEmpty();
    }

    void push(T d)
    {
        my_stack->addFisrt(d);  // tah zarf...

    }
    T top()
    {
        return my_stack->First();
    }
    T pop()
    {
        return my_stack->removeFirst();
    }

    char IsClosed(char parantez_closer)  // for compare with .pop()
    {
        if (parantez_closer == ')')
        {
            return '(';
        }
        else if (parantez_closer == ']')
        {
            return '[';
        }
        else if (parantez_closer == '}')
        {
            return '{';
        }
    }

};

//----------------------------------------------------------------

int main()
{

    stack_with_linkedlist <char> my_input;
    string sentence;
    bool true_parantezes = true;
    int wrong_index = 0;

    getline(cin, sentence); // cin of strings

    for (wrong_index = 0; wrong_index < sentence.size(); wrong_index++)
    {
        if (sentence[wrong_index] == '(' || sentence[wrong_index] == '[' || sentence[wrong_index] == '{')
        {
            my_input.push(sentence[wrong_index]); // opener -> go to stack...
        }
        else if (sentence[wrong_index] == ')' || sentence[wrong_index] == ']' || sentence[wrong_index] == '}')
        {
            if (my_input.Is_Empty())
            {
                true_parantezes = false;

                break;
            }
            else
            {
                if (my_input.pop() != my_input.IsClosed(sentence[wrong_index]))  // compare opener in stack with is_closed
                {
                    true_parantezes = false;

                    break;
                }
            }
        }
    }

    if (my_input.Is_Empty() == false) // opener ezafi  ( { [
    {
        true_parantezes = false;
    }

    if (!true_parantezes)
    {
        cout << "NO" << " " << wrong_index + 1 << endl; // output is stack from 1 but in array from 0...
    }
    else
    {
        cout << "YES"<<endl;
    }

    return 0;
}
