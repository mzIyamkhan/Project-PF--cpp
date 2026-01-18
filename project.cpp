#include <iostream>
using namespace std;

// Function to get a valid (non-negative) amount
double ValidAmount(const string& message)
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

// Function to calculate monthly tax based on current balance
double MonthlyTax(double balance, double monthlyTaxRate)
{
    return balance * monthlyTaxRate;
}

int main()
{
    double annualTaxRate, initialBalance;
    int months;

    cout << "\n\t\tWELCOME TO SAVING ACCOUNT MANAGEMENT SYSTEM";
    cout << "\n\t\t-------------------------------------------\n\n";

    cout << "ENTER THE STARTING BALANCE OF THE ACCOUNT: ";
    cin >> initialBalance;

    cout << "ENTER THE ANNUAL TAX RATE (e.g. 0.12 for 12%): ";
    cin >> annualTaxRate;

    cout << "ENTER THE TOTAL NUMBER OF MONTHS SINCE THE ACCOUNT WAS OPENED: ";
    cin >> months;

    cout << "\n-------------------------------------------------------------\n\n";

    // Arrays to store monthly data
    double deposit[months];
    double withdrawal[months];
    double tax[months];

    double monthlyTaxRate = annualTaxRate / 12;

    double balance = initialBalance;
    double totalDeposit = 0;
    double totalWithdrawal = 0;
    double totalTax = 0;

    for (int i = 0; i < months; i++)
    {
        cout << "MONTH " << i + 1 << " TRANSACTIONS\n";

        // Deposit
        deposit[i] = ValidAmount("ENTER DEPOSIT AMOUNT: ");
        balance += deposit[i];
        totalDeposit += deposit[i];

        // Withdrawal
        withdrawal[i] = ValidAmount("ENTER WITHDRAWAL AMOUNT: ");
        balance -= withdrawal[i];
        totalWithdrawal += withdrawal[i];

        // Tax calculation
        tax[i] = MonthlyTax(balance, monthlyTaxRate);
        balance -= tax[i];
        totalTax += tax[i];

        cout << "BALANCE AFTER MONTH " << i + 1 << ": " << balance << "\n\n";
    }

    cout << "\n=============================================================\n";
    cout << "FINAL ACCOUNT SUMMARY\n";
    cout << "=============================================================\n";
    cout << "FINAL BALANCE: " << balance << endl;
    cout << "TOTAL AMOUNT DEPOSITED: " << totalDeposit << endl;
    cout << "TOTAL AMOUNT WITHDRAWN: " << totalWithdrawal << endl;
    cout << "TOTAL TAX DEDUCTED: " << totalTax << endl;

    return 0;
}

