#include "receipt.h"

    receipt::receipt(int number, int date, float amount)
        : _number(number), _date(date), _amount(amount) {
        std::cout << "The constructor with parameters is called:  " << this << std::endl;
    }

    receipt::receipt()
        : _number(0), _date(0), _amount(0.0f) {
        std::cout << "The constructor without parameters is called: " << this << std::endl;
    }

    receipt::receipt(const receipt& other)
        : _number(other._number), _date(other._date), _amount(other._amount) {
        std::cout << "The copy constructor is called:  " << this << std::endl;
    }

    int receipt::GetNumber() const {
        return _number;
    }

    int receipt::GetDate() const {
        return _date;
    }

    float receipt::GetAmount() const {
        return _amount;
    }

    void receipt::SetNumber(int number) {
        _number = number;
    }

    void receipt::SetDate(int date) {
        _date = date;
    }

    void receipt::SetAmount(float amount) {
        _amount = amount;
    }

    void receipt::Set(int number, int date, float amount) {
        _number = number;
        _date = date;
        _amount = amount;
    }

    void receipt::Print() const {
        std::cout << "Receipt number: " << _number << std::endl;
        std::cout << "Date: " << _date << std::endl;
        std::cout << "Amount: " << _amount << std::endl;
        std::cout << std::endl;
    }

    receipt::~receipt() {
        std::cout << "The destructor called:  " << this << std::endl;
    }

