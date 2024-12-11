#include <iostream>
#include <string>
using namespace std;
const int Size = 50;

int front = -1, rear = -1;

class job{
	public:
		int job_id;
		string job_name;
};

class Queue{
	job Q[Size];
	public:
		void enqueue();
		int dequeue();
		void display();
};


void Queue::enqueue()
{
    int x;
    string name;
    if (rear == (Size - 1))
    {
        cout << "Queue Overflow \n"<< endl;
        return;
    }
        
        rear++;
        cout << "\nEnter Job value ";
        cin >> x;
        Q[rear].job_id = x;
        cout << "\nEnter Job Name ";
        cin >> name;
        Q[rear].job_name = name;
        
       if (front == -1)
    		front++;
 
}

int Queue::dequeue()
{
    int val;

    if (front == -1)
    {
        cout << "\nQueue is empty"<<endl;
        return -1;
    }
    else
    {
        val = Q[front].job_id;
        cout << "\n"<< val << " was removed from queue\n";
        front++;
    }
    if (front == rear )
    {
	  front = -1;
	  rear = -1;
    }
    return val;
}

void Queue::display()
{
    if (front == -1)
    {
        cout << "Queue is Empty";
    }
    else
    {
    	  cout<<"Index"<<"	"<<"JOB ID"<<"	"<<"JOB Name"<<endl;
        for (int i = front; i <= rear; i++)
        {
            cout << i <<"	"<<Q[i].job_id<<"	"<<Q[i].job_name<<endl;
        }
    }

}

int main()
{
    int ch1;
    char choice;
    Queue queue;
    do
    {
        cout << "\n______________MENU___________";
        cout << "\n1. Add a job";
        cout << "\n2. Remove a job";
        cout << "\n3. Display Current jobs";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch1;
        switch (ch1) {
            case 1:
                queue.enqueue();
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
            	break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        
        cout << "\nDo you want to continue (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    return 0;
}

