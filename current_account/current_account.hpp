#ifndef CURRENT_ACCOUNT_H_
#define CURRENT_ACCOUNT_H_

#include "../account/account.hpp"

class CurrentAccount : public Account {
public:
    CurrentAccount(
        std::string accountNumber,
        std::string accountHolder,
        double balance,
        double overdraftLimit
    )
    : Account(accountNumber, accountHolder, balance)
    , overdraftLimit_(overdraftLimit)
    { }

    void displayDetails() const;
    bool withdraw(double);
    double getMaxWithdrawable() const;

    CurrentAccount& operator+(Account&);
    friend std::ostream& operator<<(std::ostream&, const CurrentAccount&);
private:
    double overdraftLimit_;
};

#endif // CURRENT_ACCOUNT_H_