#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int s; // s is the size of array used here

public:
    Queue(int s)
    {
        this->s = s;
        arr = new int[s];
        qfront = -1;
        rear = -1;
    }

    void push(int data) // to insert the element from the backside
    {
        if (qfront == -1 && rear == -1)
        {
            qfront = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == s - 1)
            cout << "Queue is Full." << endl;

        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    int pop() // to remove the element one by one from the front side
    {
        int ans;
        if (rear == -1 && qfront == -1)
            cout << "Queue is Empty." << endl;

        else if (qfront == rear)
        {
            ans = arr[qfront];
            qfront = -1;
            rear = -1;
            return ans;
        }

        else if (qfront >= 0 && qfront <= rear)
        {
            ans = arr[qfront];
            qfront++;
            return ans;
        }
    }

    bool empty() // to check whether queue is empty or not
    {
        if (qfront == -1 && rear == -1)
            return true;
        else
            return false;
    }

    int front() // to find the front element of the queue
    {
        if (qfront == -1 && rear == -1)
            return -1;
        else
            return arr[qfront];
    }
    int back() // to find the back element of the queue
    {
        if (qfront == -1 && rear == -1)
            return -1;
        else
            return arr[rear];
    }

    int size()
    {
        if (qfront == -1 && rear == -1)
            return 0; // queue is empty

        else
            return (rear - qfront + 1);
    }

    void display() // to display the queue
    {
        int i = qfront;
        int j = rear;
        if (i == -1 && j == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        while (i <= j)
        {
            cout << arr[i] << " ";
            i++;
        }
    }
};

int main()
{
    int s = 7; // size of array
    Queue q(s);

    q.push(10);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    // int d1 = q.pop();
    //  cout << endl << "After delete one element : ";
    q.display();

    int d2 = q.pop();
    cout << endl
         << "Deleted element is : " << d2 << endl;

    int f = q.front();
    int b = q.back();

    cout << endl
         << "Front element is : " << f << endl;

    cout << "back element is : " << b << endl;

    q.display();

    cout << endl
         << "Size of the queue : " << q.size();

    // STL Queue------------------------------------------------------
    /*

        queue<int> qu;
        qu.push(20);
        qu.push(30);
        qu.push(40);

        cout << qu.front();
        cout << qu.back();       */
}