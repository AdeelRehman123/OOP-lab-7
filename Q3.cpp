#include <iostream>
#include <iomanip>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual ~Currency() {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(const Currency& targetCurrency) const {
        return convertToBase() / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << fixed << setprecision(2) << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() const override {
        return amount;
    }

    void displayCurrency() const override {
        cout << "$" << fixed << setprecision(2) << amount << " (USD)" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() const override {
        return amount * exchangeRate;
    }

    void displayCurrency() const override {
        cout << "€" << fixed << setprecision(2) << amount << " (EUR)" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}

    double convertToBase() const override {
        return amount * exchangeRate;
    }

    void displayCurrency() const override {
        cout << "₹" << fixed << setprecision(2) << amount << " (INR)" << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(50);
    Rupee r(5000);

    cout << "\n--- Currency Display ---\n";
    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "\n--- Currency Conversion ---\n";
    cout << "100 USD to EUR: " << d.convertTo(e) << " EUR\n";
    cout << "50 EUR to INR: " << e.convertTo(r) << " INR\n";
    cout << "5000 INR to USD: " << r.convertTo(d) << " USD\n";

    return 0;
}
