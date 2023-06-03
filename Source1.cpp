#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BrunchFinances
{
private:

    void clearProfit()
    {
        Revenue();
        Expenses();
        profit = revenue - expenses;
    }

    void Rent()
    {
        if (revenue < amountWithInterest)
        {
            rent = bet;
        }
        else rent = bet + ((revenue - amountWithInterest) * percent);
    }

    void Expenses()
    {
        if (revenue > amountWithInterest)
        {
            expenses = salary + services + (bet + ((revenue - amountWithInterest) * percent));
        }
        else
        {
            expenses = salary + services + bet;
        }
    }

    void Revenue()
    {
        srand(time(NULL));
        revenue = 250 + rand() % (500 - 250 + 1);
    }

public:
    BrunchFinances() {}
    ~BrunchFinances() {}
    const int bet = 50;
    const int amountWithInterest = 270;
    const double percent = 0.07;
    const int salary = 35;
    const int services = 15;
    double rent;
    double expenses;
    double profit;
    int revenue;

    void printRent()
    {
        Rent();
        cout << "Арендная плата составляет: " << rent << endl;
    }

    void printExpenses()
    {
        Expenses();
        cout << "Все расходы составляют: " << expenses << endl;
    }

    void printClearProfit()
    {
        clearProfit();
        cout << "Чистая выручка составляет: " << profit << endl;
    }

};

class NewBrunch : public BrunchFinances
{
private:
    string name;
public:
    NewBrunch(string n)
    {
        name = n;
    }
    ~NewBrunch() {}
};

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите название магазина! ";
    string name;
    cin >> name;
    NewBrunch b(name);
    b.printClearProfit();
    b.printExpenses();
    b.printRent();
}