#include <iostream>
#include <queue>
using namespace std;

class circularQueue
{
    int *arr;
    int qfront;
    int rear;
    int s; // s is the size of array used here

public:
    circularQueue(int s)
    {
        this->s = s;
        arr = new int[s];
        qfront = -1;
        rear = -1;
    }

    void push(int data)
    {
        if (qfront == -1 && rear == -1)
        {
            qfront = 0;
            rear = 0;
            arr[qfront] = data;
        }

        else if (qfront == (rear + 1) % s)
        {
            cout << "Queue is full.." << endl;
        }

        else
        {
            rear = (rear + 1) % s;
            arr[rear] = data;
        }
    }

    int pop()
    {
        int ans = -1;
        if (qfront == -1 && rear == -1)
        {
            cout << "Queue is empty.." << endl;
            return -1;
        }

        else if (rear == qfront)
        {
            ans = arr[qfront];
            qfront = -1;
            rear = -1;
        }
        else
        {
            ans = arr[qfront];
            qfront = (qfront + 1) % s;
        }
        return ans;
    }

    int size()
    {
        if (qfront == -1 && rear == -1)
            return 0; // queue is empty

        else if (qfront <= rear)
            return (rear - qfront + 1);

        else // when rear < front
        {
            int i = qfront;
            int count = 0;
            while (i != rear)
            {
                count++;
                i = (i + 1) % s;
            }
            return count + 1;
        }
    }

    void display()
    {
        int i = qfront;
        if (qfront == -1 && rear == -1)
            cout << "Queue is empty.." << endl;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % s;
        }
        cout << arr[i] << endl;
    }
};

int main()
{
    int s = 6; // size of array
    circularQueue q(s);

    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    // int d1 = q.pop();
    cout << "Circular Queue is : ";
    q.display();
    cout << "Size of queue is : " << q.size();
}