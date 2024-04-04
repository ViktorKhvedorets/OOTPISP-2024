#include <memory>
#include <vector>
#include <array>
#include "receipt.h"

int main()
{
    receipt* first = new receipt(52, 33, 111.50);
    receipt second;
    receipt* third = new receipt(*first);

    receipt** tramp = new receipt*;
    *tramp = third;
    (**tramp).Print();

    second.SetDate(3123);
    second.SetAmount(230.75);
    second.SetNumber(4234);
    second.Print();

    first->Set(965, 2345, 52.25);
    first->Print();

    void (receipt:: * pf)() const = &receipt::Print;

    std::array<receipt, 3> firstTeam = {
        receipt(111, 223, 150.00),
        receipt(222, 20202, 250.00),
        receipt(333, 503, 350.00) };

    for (int i = 0; i < 3; i++)
    {
        (firstTeam[i].*pf)();
    }

    receipt* secondTeam = new receipt[3];
    secondTeam[0].Set(444, 20601, 450.00);
    secondTeam[1].Set(555, 202, 550.00);
    secondTeam[2].Set(666, 12420603, 650.00);

    for (int i = 0; i < 3; i++)
    {
        secondTeam[i].Print();
    }

    receipt fourth = secondTeam[1];
    fourth.Print();

    delete first;
    delete third;
    delete tramp;
    delete[] secondTeam;

    return 0;
}
