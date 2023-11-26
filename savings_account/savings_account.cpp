#include <iomanip>
#include <algorithm>
#include "savings_account.hpp"

void SavingsAccount::displayDetails() const {
    std::cout << *this << std::endl;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount > balance_ - minimumBalance_) return false;
    balance_ -= amount;
    return true;
}

double SavingsAccount::getMaxWithdrawable() const {
    return std::max(balance_ - minimumBalance_, 0.0);
}

SavingsAccount& SavingsAccount::operator+(Account& rhs) {
    double amount = rhs.getMaxWithdrawable();
    this->deposit(amount);
    rhs.withdraw(amount);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SavingsAccount& acc) {
    return os << std::fixed << std::showpoint << std::setprecision(2)
              << "Account Details for Savings Account (ID: "    << acc.accountNumber_ << "):\n"
              << "  Holder: "        << acc.accountHolder_      << "\n"
              << "  Balance: $"      << acc.balance_            << "\n"
              << "  Interest Rate: " << acc.interestRate_ * 100 << "%\n";
}