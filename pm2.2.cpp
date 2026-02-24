#include<iostream>
#include<string>

using namespace std;

class student
{

private:
    int roll,mark1,mark2,mark3;
    string name ;

public:
    student(int r,string n,int m1,int m2 ,int m3)
    {
        roll=r;
        mark1=m1;
        mark2=m2;
        mark3=m3;
        name=n;
    }
    student()
    {
        roll=0;
        mark1=mark2=mark3=0;
        name="kalash";
    }
     void add(int r,string n,int m1,int m2 ,int m3)
    {
        roll=r;
        mark1=m1;
        mark2=m2;
        mark3=m3;
        name=n;
    }
    float getavg()
    {
        return (mark1+mark2+mark3)/3.0;
    }
    void display()
    {
                cout << "\n------------------------\n";
        cout << "Roll No : " << roll<< endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << mark1<< ", " << mark2<< ", " << mark3<< endl;
        cout << "Average : " << getavg() << endl;
        cout << "------------------------\n";
    }
};
int main()
{

    student s1[100];
    int co=0,ch;


    do
    {
        cout<<"1.Add students--\n ";
        cout<<"2.add students by default \n";
        cout<<"3.display all students \n";
        cout<<"4.Exist\n";
        cout<<"Enter your choice \n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            {

            int r;
            string n;
            float a, b, c;

            cout << "Enter Roll No: ";
            cin >> r;

            cout << "Enter Name: ";
            cin >> n;

            cout << "Enter Marks 1: ";
            cin >> a;

            cout << "Enter Marks 2: ";
            cin >> b;

            cout << "Enter Marks 3: ";
            cin >> c;
            s1[co].add(r,n,a,b,c);
            co++;
             cout << "Student Added Successfully!\n";

                break;
            }
        case 2:
            {
                s1[co]=student();
                co++;
                cout<<"Default added ..\n";
                break;
            }
        case 3:
            {
                 if (co== 0)
                {
                    cout << "No Records Found!\n";
                }
                else
                {
                    for (int i = 0; i < co; i++)
                    {
                        s1[i].display();
                    }
                }
                    break;
            }
        case 4:
            {
                break;
            }
        default:
            cout<<"Invalid choice !!!\n";
        }

    }while(ch!=5);
}
