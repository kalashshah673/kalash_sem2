#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Loan
{
private:
    string loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;
    double emi;

public:

    // Parameterized Constructor
    Loan(string id, string name, double amount, double rate, int tenure)
    {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
        calculateEMI();
    }

    // Default Constructor
    Loan()
    {
        loanID = "";
        applicantName = "";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;
        emi = 0;
    }

    void setData(string id, string name, double amount, double rate, int tenure)
    {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
        calculateEMI();
    }

    void calculateEMI()
    {
        if(loanAmount > 0 && annualInterestRate > 0 && tenureMonths > 0)
        {
            double monthlyRate = annualInterestRate / 12 / 100;
            double powerValue = pow(1 + monthlyRate, tenureMonths);

            emi = (loanAmount * monthlyRate * powerValue) / (powerValue - 1);
        }
        else
        {
            emi = 0;
        }
    }

    void display()
    {
        cout<<"\nLoan ID: "<<loanID<<endl;
        cout<<"Applicant Name: "<<applicantName<<endl;
        cout<<"Loan Amount: "<<loanAmount<<endl;
        cout<<"Annual Interest Rate: "<<annualInterestRate<<"%"<<endl;
        cout<<"Tenure (Months): "<<tenureMonths<<endl;
        cout<<"Monthly EMI: "<<emi<<endl;
    }
};

int main()
{
    Loan loans[100];
    int count = 0;
    int choice;

    do
    {
        cout<<"\n1. Create Loan Account";
        cout<<"\n2. Display All Loans";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
        {
            if(count < 100)
            {
                string id, name;
                double amount, rate;
                int tenure;

                cout<<"Enter Loan ID: ";
                cin>>id;

                cout<<"Enter Applicant Name: ";
                cin>>name;

                cout<<"Enter Loan Amount: ";
                cin>>amount;

                cout<<"Enter Annual Interest Rate (%): ";
                cin>>rate;

                cout<<"Enter Tenure (Months): ";
                cin>>tenure;

                loans[count].setData(id, name, amount, rate, tenure);
                count++;

                cout<<"Loan Account Created Successfully.\n";
            }
            else
            {
                cout<<"Loan storage limit reached.\n";
            }
            break;
        }

        case 2:
        {
            if(count == 0)
            {
                cout<<"No Loan Records Found.\n";
            }
            else
            {
                for(int i=0; i<count; i++)
                {
                    loans[i].display();
                }
            }
            break;
        }

        case 3:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice.\n";
        }

    }while(choice != 3);

    return 0;
}
