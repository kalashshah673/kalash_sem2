#include<iostream>
#include<string>

using namespace std;

class RMS
{

private:
    float length;
    float width;
public:
    RMS()
    {
        length=0.0;
        width=0.0;
    }
    RMS(float l, float w)
    {
        length=l;
        width=w;
    }
    void add(float l , float w)
    {
        length=l;
        width=w;
    }
    float area()
    {
        return length*width;
    }
    float perimeter()
    {
        return 2*(length+width);
    }
    void display()
    {
        cout<<"length : \n"<<length<<endl;
        cout<<"width : \n"<<width<<endl;
        cout<<"The area is : \n"<<area()<<endl;
        cout<<"The perimeter  is : \n"<<perimeter()<<endl;
    }

};
int main()
{

    RMS rect[100];
    int c=0,ch;

    do
    {
         cout << "\n===== RECTANGLE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Rectangle\n";
        cout << "2. Update Rectangle\n";
        cout << "3. Display All Rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            {
                float l,w;
                cout<<"enter the length \n";
                cin>>l;
                cout<<"enter the width \n";
                cin>>w;
                if(l>0 && w>0)
                {
                    rect[c].add(l,w);
                    c++;
                    cout<<" added succesfully...\n";

                }
                else
                {
                    cout<<" Invalid dimesions \n";
                }
                break;
            }
        case 2:
            {
                float l,w;
                    int index;
                    cout<<"enter the number of the rectangle which dimensions u want to update\n";
                    cin>>index;
                     if(index >= 1 && index <= c)
                        {
                            cout << "Enter New Length: ";
                            cin >> l;
                            cout << "Enter New Width: ";
                            cin >> w;
                            rect[index - 1].add(l, w);
                        }
                    else
                        cout<<" invalid number \n";

                break;
            }
        case 3:
            {
                for (int i = 0; i < c; i++)
                {
                    cout << "\nRectangle " << i + 1 << ":";
                    rect[i].display();
                }
                break;
            }
             case 4:
        {
            cout << "Exiting Program...\n";
            break;
        }

        default:
            cout << "Invalid Choice! Try Again.\n";
        }
    }while(ch!=4);
    return 0;
}
