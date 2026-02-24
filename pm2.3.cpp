#include<iostream>
#include<string>

using namespace std;

class Account
{

private:
    string name;
    string uid;
    float balance;
public:
    Account(string n, string id , float bal)
    {
        name=n;
        uid=id;
        balance=bal;
    }
    Account()
    {
        name="";
        uid="";
        balance=0;
    }
    void add(string n, string id , float bal)
    {
        name=n;
        uid=id;
        balance=bal;
    }
    void deposit(float dm)
    {
                if(dm>0)
                {
                    balance+=dm;
                    cout<<"money added successfully \n";
                }
                else
                {
                        cout<<"Invalid money number \n";
                }
    }
    void withdraw(float wm)
    {
                if(balance>=wm)
                {
                    if(wm>0)
                    {
                        balance-=wm;
                        cout<<"money withdraw successfully \n";
                    }
                }
                else
                {
                        cout<<"Invalid money number \n";
                }
    }
    void display()
    {
        cout<<"Your name is :\n"<<name<<endl;
        cout<<"Your ID is : \n"<<uid<<endl;
        cout<<"Your current balance is : \n"<<balance<<endl;

    }
};
int main()
{
    Account acc[100];
    int c=0,ch,dm,wm;

    do
    {
        cout<<"\n 1. Create account";
        cout<<"\n 2. Deposit money";
        cout<<"\n 3. Withdraw money";
        cout<<"\n 4.Display";
        cout<<"\n 5. Exist";
        cout<<"\n Enter your choice!!";
        cin>>ch;

        switch(ch)
        {
        case 1:
            {
                string n,i;
                float b;
                cout<<"Enter your name : ";
                cin>>n;
                cout<<"Enter your unique id :";
                cin>>i;
                cout<<"Enter your current balance : ";
                cin>>b;
                acc[c].add(n,i,b);
                c++;
                break;
            }
        case 2:
            {
                int index;
            float dmm;
            cout<<"Enter account number (0 to "<<c-1<<"): ";
            cin>>index;

            if(index >= 0 && index < c)
            {
                cout<<"Enter amount to deposit: ";
                cin>>dmm;
                acc[index].deposit(dmm);
            }
            else
            {
                cout<<"Invalid account number\n";
            }


                break;
            }
        case 3:
            {
                 int index;
            float wmm;
            cout<<"Enter account number (0 to "<<c-1<<"): ";
            cin>>index;

            if(index >= 0 && index < c)
            {
                cout<<"Enter amount to withdraw: ";
                cin>>wmm;
                acc[index].withdraw(wmm);
            }
            else
            {
                cout<<"Invalid account number\n";
            }


                break;
            }
        case 4:
            {
                if(c==0)
                {
                    cout<<"No accounts found \n";
                }
                else
                {
                    for(int i=0;i<c;i++)
                    {
                        acc[i].display();

                    }
                    break;
                }
            }
        case 5:
            {
                cout<<"Invalid choice !!!\n ";
                break;
            }
        default:
            cout<<"Invalid number !! \n";
        }
    }while(ch!=5);

}



