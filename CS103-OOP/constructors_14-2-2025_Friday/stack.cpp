#include<iostream>

using namespace std;

class stack
{
    private:
        int data[10];
        int top;
    
    public:
        /*void init()
        {
            top=-1;
        }*/
       
       stack()
       {
        top=-1;
       }
        void push(int x)
        {
            if(top==9)
            {
                cout<< "Over flow, can't push anymore elements"<<endl;
                return;
            }
            top = top + 1;
            data[top] = x;

        }

        void pop()
        {
            if(top == -1)
            {
                cout<<"Under flow: occured";
                return;
            }

            cout<<"The popped element is: "<<data[top]<<endl;
            top = top-1;

        }
    void display()
    {
        if(top==-1)
        {
            cout<<"The stack is empty: There are no elements to display"<<endl;
            return;
        }
        
        for(int i=0;i<=top;i++)
            cout << data[i]<<" ";
        cout<<"\n";
    }
};

int main()
{
    stack s;
    //s.initialize();
    //s.top=100;
    //s.init();
    for(int i=0;i<=10;i++)
        s.push(i);
    s.display();
    s.pop();
    s.display();
    //s.init();
    s.display();
    return 0;
}