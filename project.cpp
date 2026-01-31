#include <iostream>
#include <iomanip>
using namespace std;

double getValidAmount(const string& message)
{
    double amount;
    do
    {
        cout << message;
        cin >> amount;

        if (amount < 0)
        {
            cout << "ERROR: Negative values are not allowed. Please re-enter.\n";
        }
    } while (amount < 0);

    return amount;
}

int main()
{
    int months;
    double annualTaxRate;
    double balance;

    cout << "\n\nENTER ANNUAL TAX DEDUCTION RATE (%): ";
    cin >> annualTaxRate;

    cout << "ENTER INITIAL ACCOUNT BALANCE: ";
    cin >> balance;

    cout << "ENTER TOTAL NUMBER OF MONTHS: ";
    cin >> months;

    double monthlyTaxRate = (annualTaxRate / 100) / 12;

    double deposits[months];
    double withdrawals[months];
    double taxes[months];

    double totalDeposits = 0;
    double totalWithdrawals = 0;
    double totalTax = 0;

    for (int i = 0; i < months; i++)
    {
        cout << "\nMONTH " << i + 1 << "\n";

        deposits[i] = getValidAmount("Enter deposit amount: ");
        balance += deposits[i];
        totalDeposits += deposits[i];

        withdrawals[i] = getValidAmount("Enter withdrawal amount: ");
        balance -= withdrawals[i];
        totalWithdrawals += withdrawals[i];

        taxes[i] = balance * monthlyTaxRate;
        balance -= taxes[i];
        totalTax += taxes[i];
    }

    cout << "\n\nACCOUNT SUMMARY\n\n";
    cout << "Final Account Balance: " <<fixed << setprecision(2) << balance << endl;
    cout << "Total Deposited: " << totalDeposits << endl;
    cout << "Total Withdrawn: " << totalWithdrawals << endl;
    cout << "Total Tax Deducted: " <<fixed << setprecision(2)<< totalTax << endl;

}
