#include <iomanip>
#include "account.hpp"

void Account::displayDetails() const {
    std::cout << *this << std::endl;
}

void Account::deposit(double amount) {
    balance_ += amount;
}

double Account::getMaxWithdrawable() const {
    return balance_;
}

bool Account::withdraw(double amount) {
    if (amount > balance_) return false;
    balance_ -= amount;
    return true;
}

Account& Account::operator+(Account& rhs) {
    double amount = rhs.getMaxWithdrawable();
    this->deposit(amount);
    rhs.withdraw(amount);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    return os << std::fixed << std::showpoint << std::setprecision(2)
              << "Account Details for Account (ID: "  << acc.accountNumber_ << "):\n"
              << "  Holder: "   << acc.accountHolder_ << "\n"
              << "  Balance: $" << acc.balance_       << "\n";
}