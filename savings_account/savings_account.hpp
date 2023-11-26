#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include "../account/account.hpp"

class SavingsAccount : public Account {
public:
    SavingsAccount(
        std::string accountNumber,
        std::string accountHolder,
        double balance,
        double interestRate,
        double minimumBalance = 1200.0
    )
    : Account(accountNumber, accountHolder, balance)
    , interestRate_(interestRate)
    , minimumBalance_(minimumBalance)
    { }

    void displayDetails() const;
    bool withdraw(double);
    double getMaxWithdrawable() const;

    SavingsAccount& operator+(Account&);
    friend std::ostream& operator<<(std::ostream&, const SavingsAccount&);
private:
    double interestRate_;
    double minimumBalance_;
};

#endif // SAVINGS_ACCOUNT_H_