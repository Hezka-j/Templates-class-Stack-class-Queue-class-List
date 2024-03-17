#include <iostream>
#include<Windows.h>
using namespace std;
template<typename T>
class Stack{
    unsigned int capasity = 10;
    unsigned int size = 0;
    T* ar = new T[capasity];
public:
    ~Stack() {
        if(ar != nullptr)
            delete[] ar;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    bool IsFull()
    {
        return size == capasity;
    }

    void Push(T data)
    {
        if (size == capasity)
        {
            T* temp = new T[capasity * 2];
            for (int i = 0; i < size; i++)
                temp[i] = ar[i];
            delete[] ar;
            capasity *= 2;
            ar = temp;
        }
        ar[size++] = data;
    }

    T Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            return ar[--size];
        }
    }
};

//using unsint = unsigned int;
//typedef unsigned int unsint;
template<typename T>
class Queue{
    T* data = nullptr;
    unsigned int size = 0;
    unsigned int capasity;
public:
    Queue() : Queue(10){}

    Queue(int capasity)
    {
        data = new T[capasity];
        this->capasity = capasity;
    }

    ~Queue()
    {
        if(data != nullptr) delete[] data;
    }

    void Clear()
    {
        size = 0;
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    bool IsFull()
    {
        return size == capasity;
    }

    void Enqueue(T data)
    {
        if (capasity > 1000)
            throw "error, capasity too big";
        if (IsFull())
        {
            T* temp = new T[capasity * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = this->data[i];
            }
            delete[] this->data;
            this->data = temp;           
        }
        this->data[size++] = data;
    }

    int GetCount()
    {
        return size;
    }

    T Dequeue()
    {
        if (IsEmpty())
            return 0;
        T number = data[0];
        for (int i = 0; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
        /*data[size - 1] = number;*/
        return number;
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << "\n";
    }
};

template<typename T>
class List{
    struct Node {
        Node* next = nullptr;
        Node* prev = nullptr;
        T data = 0;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
public:
    /*~List()
    {
        Clear();
    }*/
    bool IsEmpty()
    {
        return count == 0;
    }

    int GetCount()
    {
        return count;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            PopBack();
        }
    }

    void PushBack(T data)
    {
        auto* new_elem = new Node();
        new_elem->data = data;
        new_elem->prev = tail;
        if (tail == nullptr)
        {
            head = new_elem;
        }
        else
        { 
            tail->next = new_elem;
        }
        tail = new_elem;
        count++;
    }

    void PushFront(T data)
    {
        auto* new_elem = new Node();
        new_elem->data = data;
        new_elem->next = head;    
        if (head == nullptr)
        {
            tail = new_elem;
        }
        else
        {
            head->prev = new_elem;
        }
        head = new_elem;
        count++;
    }

    T PopBack()
    {
        if (IsEmpty())
            return 0;
        T number = tail->data;
        auto* temp = tail;
        tail = tail->prev;
        delete temp;
        if (tail == nullptr)
        {
            head = nullptr;
        }
        else
        {
            tail->next = nullptr;
        }
        count--;
        return number;
    }

    T PopFront()
    {
        if (IsEmpty())
            return 0;
        T number = head->data;
        auto temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            head->prev = nullptr;
        }
        count--;
        return number;
    }

    void Print()
    {
        if (IsEmpty())
            return;
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main()
{
    /*Queue<int> q;
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);

    q.Print();
    cout << q.Dequeue() << " ";
    cout << q.Dequeue() << " ";
    cout << q.Dequeue() << " ";
    cout << q.Dequeue() << " ";*/
    /*while(true)
    {
        cout << q.Dequeue();
        Sleep(1000);
    }*/


    /*Stack<int> st;
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    for(int i = 0; i < 5; i++)
        cout << st.Pop() << " ";*/


    List<double> l;
    l.PushBack(5.8);
    l.PushFront(2.3);
    l.PushBack(7.5);
    l.PushFront(1.2);
    l.Print();
    l.PopBack();
    l.PopFront();
    l.Print();
    l.PopBack();
    l.PopBack();
}
