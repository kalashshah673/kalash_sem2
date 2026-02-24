#include<iostream>
#include<string>

using namespace std;

class Stock
{
private:
    string uid;
    string name;
    float price;
    int quantity;

public:

    Stock(string id, string n, float p, int q)
    {
        uid = id;
        name = n;
        price = p;
        quantity = q;
    }

    Stock()
    {
        uid = "";
        name = "";
        price = 0.0;
        quantity = 0;
    }

    void setData(string id, string n, float p, int q)
    {
        uid = id;
        name = n;
        price = p;
        quantity = q;
    }

    string getId()
    {
        return uid;
    }

    string getName()
    {
        return name;
    }

    void increase(int add)
    {
        if(add > 0)
        {
            quantity += add;
            cout<<"Stock increased successfully.\n";
        }
        else
        {
            cout<<"Invalid quantity.\n";
        }
    }

    void decrease(int sub)
    {
        if(sub > 0 && sub <= quantity)
        {
            quantity -= sub;
            cout<<"Stock decreased successfully.\n";
        }
        else
        {
            cout<<"Invalid quantity or insufficient stock.\n";
        }
    }

    bool validateSale(int sellQty)
    {
        if(sellQty > 0 && sellQty <= quantity)
        {
            quantity -= sellQty;
            return true;
        }
        return false;
    }

    void display()
    {
        cout<<"\nItem ID: "<<uid<<endl;
        cout<<"Item Name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
};

int main()
{
    Stock s[100];
    int c = 0, ch;

    do
    {
        cout<<"\n1. Initialize Stock";
        cout<<"\n2. Increase Stock";
        cout<<"\n3. Decrease Stock";
        cout<<"\n4. Validate & Sell";
        cout<<"\n5. Display All Stock";
        cout<<"\n6. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            string id, name;
            float price;
            int qty;

            cout<<"Enter Item ID: ";
            cin>>id;
            cout<<"Enter Item Name: ";
            cin>>name;
            cout<<"Enter Price: ";
            cin>>price;
            cout<<"Enter Quantity: ";
            cin>>qty;

            s[c].setData(id, name, price, qty);
            c++;
            cout<<"Item added successfully.\n";
            break;
        }

        case 2:
        {
            string id;
            int qty;
            cout<<"Enter Item ID: ";
            cin>>id;

            bool found = false;

            for(int i=0; i<c; i++)
            {
                if(s[i].getId() == id)
                {
                    cout<<"Enter quantity to add: ";
                    cin>>qty;
                    s[i].increase(qty);
                    found = true;
                    break;
                }
            }

            if(!found)
                cout<<"Item not found.\n";
            break;
        }

        case 3:
        {
            string id;
            int qty;
            cout<<"Enter Item ID: ";
            cin>>id;

            bool found = false;

            for(int i=0; i<c; i++)
            {
                if(s[i].getId() == id)
                {
                    cout<<"Enter quantity to decrease: ";
                    cin>>qty;
                    s[i].decrease(qty);
                    found = true;
                    break;
                }
            }

            if(!found)
                cout<<"Item not found.\n";
            break;
        }

        case 4:
        {
            string id;
            int qty;
            cout<<"Enter Item ID: ";
            cin>>id;

            bool found = false;

            for(int i=0; i<c; i++)
            {
                if(s[i].getId() == id)
                {
                    cout<<"Enter quantity to sell: ";
                    cin>>qty;

                    if(s[i].validateSale(qty))
                        cout<<"Sale successful.\n";
                    else
                        cout<<"Insufficient stock.\n";

                    found = true;
                    break;
                }
            }

            if(!found)
                cout<<"Item not found.\n";
            break;
        }

        case 5:
        {
            if(c == 0)
                cout<<"No items available.\n";
            else
            {
                for(int i=0; i<c; i++)
                    s[i].display();
            }
            break;
        }

        case 6:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice.\n";
        }

    }while(ch != 6);

    return 0;
}
