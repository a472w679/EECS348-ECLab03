#include <iomanip>
#include <algorithm>
#include "current_account.hpp"

void CurrentAccount::displayDetails() const{
    std::cout << *this << std::endl;
}

bool CurrentAccount::withdraw(double amount) {
    if (amount > balance_ + overdraftLimit_) return false;
    balance_ -= amount;
    return true;
}

double CurrentAccount::getMaxWithdrawable() const {
    return std::max(balance_ + overdraftLimit_, 0.0);
}

CurrentAccount& CurrentAccount::operator+(Account& rhs) {
    double amount = rhs.getMaxWithdrawable();
    this->deposit(amount);
    rhs.withdraw(amount);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CurrentAccount& acc) {
    return os << std::fixed << std::showpoint << std::setprecision(2)
              << "Account Details for Current Account (ID: "   << acc.accountNumber_ << "):\n"
              << "  Holder: "           << acc.accountHolder_  << "\n"
              << "  Balance: $"         << acc.balance_        << "\n"
              << "  Overdraft Limit: $" << acc.overdraftLimit_ << "\n";
}