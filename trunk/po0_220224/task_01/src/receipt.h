#ifndef receipt_H
#define receipt_H

#include <iostream>
#include <memory>

class receipt {
public:
    receipt();
    receipt(int number, int date, float amount);
    receipt(const receipt& other);

    int GetNumber() const;
    int GetDate() const;
    float GetAmount() const;

    void SetNumber(int number);
    void SetDate(int date);
    void SetAmount(float amount);
    void Set(int number, int date, float amount);

    void Print() const;

    ~receipt();

private:
    int _number=1;
    int _date=1;
    float _amount=1;
};

#endif
