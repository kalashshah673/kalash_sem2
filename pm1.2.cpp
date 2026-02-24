#include<iostream>
#include<string>
using namespace std;


class library
{
private:
    string uid;
    string utitle;
    string uauthor;
    int ucopies;

public:
    library()
    {
        uid = "";
        utitle = "";
        uauthor = "";
        ucopies = 0;
    }
    library(string id,string title,string author,int copies)
    {
        uid=id;
        utitle=title;
        uauthor=author;
        ucopies=copies;
    }
    void add(string id, string title, string author, int copies)
    {
        uid = id;
        utitle = title;
        uauthor = author;
        ucopies = copies;
    }
      string getID()
    {
        return uid;
    }
    bool issue()
    {
        if(ucopies>0)
        {
            ucopies--;
            return true;
        }
        else
            return false;
    }
    void returnBook()
    {
        ucopies++;
    }
    void display()
    {
        cout << "\n--------------------------\n";
        cout << "Book ID  : " << uid<< endl;
        cout << "Title    : " << utitle << endl;
        cout << "Author   : " << uauthor << endl;
        cout << "Copies   : " << ucopies << endl;
        cout << "--------------------------\n";
    }
};
int main()
{
    library books[100];
    int ch,count=0;
    do
    {
          cout<<"-----library system menu------\n";
          cout<< "1.add new books\n";
          cout<<"2.issue a book\n";
          cout<<"3.returning a book\n";
          cout<<"4.diplay all the list of books\n";
          cout<<"5.Exist\n";
          cout<<"Enter choice number : ";
          cin>>ch;

            switch(ch)
            {
            case 1:
                {
                     string id, title, author;
                     int copies;

            cout << "Enter Book ID: ";
            cin >> id;

            cout << "Enter Title: ";
            cin >> title;

            cout << "Enter Author: ";
            cin >> author;

            cout << "Enter Copies: ";
            cin >> copies;

            books[count].add(id, title, author, copies);
            count++;

            cout << "Book Added Successfully!\n";
            break;

                break;
                }
            case 2:
                {
                    string id;
bool found = false;

cout << "Enter Book ID to Issue: ";
cin >> id;

for (int i = 0; i < count; i++)
{
    if (books[i].getID() == id)
    {
        found = true;

        if (books[i].issue())
        {
            cout << "Book Issued Successfully!\n";
        }
        else
        {
            cout << "No Copies Available!\n";
        }
        break;
    }
     if (!found)
            {
                cout << "Book Not Found!\n";
            }

            break;
        }


}            case 3:
                {
                  string id;
            bool found = false;

            cout << "Enter Book ID to Return: ";
            cin >> id;

            for (int i = 0; i < count; i++)
            {
                if (books[i].getID() == id)
                {
                    books[i].returnBook();
                    found = true;

                    cout << "Book Returned Successfully!\n";
                    break;
                }
            }
            if (!found)
            {
                cout << "Book Not Found!\n";
            }

                break;
                }
            case 4:
                {
                    if (count == 0)
            {
                cout << "No Books Available!\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    books[i].display();
                }
            }

                break;
                }
            case 5:
                {

            cout << "Exiting Program...\n";
                break;
                }
            default :
                cout<<"Invalid choice number !!!\n";

            }
    }while(ch!=5);
    return 0;
}
