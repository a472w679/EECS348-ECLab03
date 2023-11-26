#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iostream>

class Account {
public:
    Account(std::string accountNumber, std::string accountHolder, double balance)
    : accountNumber_(accountNumber)
    , accountHolder_(accountHolder)
    , balance_(balance)
    { }

    virtual void displayDetails() const;
    virtual bool withdraw(double);
    virtual double getMaxWithdrawable() const;
    void deposit(double);

    Account& operator+(Account&);
    friend std::ostream& operator<<(std::ostream&, const Account&);
protected:
    std::string accountNumber_;
    std::string accountHolder_;
    double balance_;
};

#endif // ACCOUNT_H_