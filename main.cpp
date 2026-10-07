#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Task
{
    int id;
    string subject;
    string details;
    string priority;
    bool status;
    
    public:
    Task(int i, string sub, string det, string p);
    int getId()
    {
        return id;
    }
    void displayTask();
};

Task::Task(int i, string sub, string det, string p)
{
    id=i;
    subject=sub;
    details=det;
    priority=p;
    status=false;
}

void Task :: displayTask()
{
    cout<< "id =" << id <<"\n"
    << "subject =" << subject <<"\n"
    << "details =" << details <<"\n"
    << "priority =" << priority <<"\n";
    if (status == false)
    {
        cout<<"Status=Pending\n";
    }
    else 
    {
         cout<< "Status=Completed\n";
    }
    
    
   
    

}
int main()
{
   vector<Task> tasks;
    
   int choice;
    int nextId=1;

    do
    {
    cout<<"\n===Student Task Tracker===" << endl;
    cout<<"1. Add Task " << endl;
    cout<<"2. View Tasks" << endl;
    cout<<"3. Mark Task Completed" << endl;
    cout<<"4. Delete Task" << endl;
    cout<<"5. Exit" << endl;

    cout<<"Enter your choice:";
    cin>> choice;

    switch (choice)
{

    case 1:
    cout<<"\nAdd Task Selected\n";

    {
    string InputSubject;
    string InputDetails;
    string InputPriority; 

    cin.ignore();

    cout << "Enter subject: ";
    getline(cin, InputSubject);

    cout << "Enter Details: ";
    getline(cin, InputDetails);

    cout << "Enter priority: ";
    getline(cin, InputPriority);

    Task task1(nextId, InputSubject, InputDetails, InputPriority);
    
    tasks.push_back(task1);
    
    cout<<"Task created successfully! ID:"<<nextId <<"\n";
    
    nextId++;
    break;
}
   

    case 2:
    cout<<"\n=== Your Tasks ===\n";

    if (tasks.empty())

    {
        cout<< "No tasks available.\n";
    }

    else
    {
        for (Task task : tasks)
{
    task.displayTask();
    cout << "-----------------\n";
}
    }
    break;

    case 3:
    cout<<"Mark Task Completed\n";
    break;

    case 4:
    cout<<"Delete Task\n";
    break;

    case 5:
    cout<<"Exit\n";
    break;

    default:
    cout<<"Invalid Choice\n";

}
    } 
    while (choice !=5);
    
    return 0;
}