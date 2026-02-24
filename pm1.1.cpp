#include<iostream>
#include<string>

using namespace std;

class wallet
{
private:
    string userid;
    string username;
    double balance;
public:
     wallet(string iid , string name , double bal)
     {
         userid=iid;
         username = name;
         balance=bal;
     }

    void loadmoney(double amount)
    {
        if(amount>0)
        {

            balance+=amount;
            cout << "Money Loaded Successfully!\n";
        }
        else
        {
            cout<<"invalid amount u are entering \n";
        }
    }
    void transfer(wallet &receiver , double amount)
    {

        if(amount<=0)
        {
            cout<<" Invalid amount \n";
        }
        else
        {

            balance-=amount;
            receiver.balance+=amount;
            cout<<"\n Trasfer amount successfully!!";
        }
    }
    void display()
    {
        cout << "Wallet ID : " << userid << endl;
        cout << "User Name : " << username << endl;
        cout << "Balance : " << balance << endl;
    }
};
    int main()
    {

        string id1 , id2 , name1 , name2;
        double bal1 , bal2 , amount;
        int choice ;
        cout<<"Enter first wallet id : \n ";
        cin>>id1;
        cout<<"Enter second  wallet id : \n ";
        cin>>id2;
        cout<<"Enter first wallet name : \n ";
        cin>>name1;
        cout<<"Enter second wallet name  : \n ";
        cin>>name2;
        cout<<"  Enter balace of 1 \n";
        cin>>bal1;
        cout<<" Enter balance of 2 \n ";
        cin>>bal2;

        wallet w1(id1,name1,bal1);
        wallet w2(id2,name2,bal2);

        do
        {
            cout << "\n===== DIGITAL WALLET MENU =====\n";
            cout << "1. Load Money (Wallet 1)\n";
            cout << "2. Transfer Money (Wallet 1 to Wallet 2)\n";
            cout << "3. Show Wallet 1 Details\n";
            cout << "4. Show Wallet 2 Details\n";
            cout << "5. Exit\n";
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter amount to load : ";
                cin>>amount;
                w1.loadmoney(amount);
                break;

                case 2:
                cout << "Enter amount to transfer: ";
                cin >> amount; w1.transfer(w2, amount);
                 break;

                  case 3: w1.display();
                  break;

                   case 4: w2.display();
                    break;

                    case 5: cout << "Exiting Program...\n";
                    break;

                     default: cout << "Invalid Choice! Try Again.\n";
                     }
                      } while (choice != 5);
                       return 0;
            }










