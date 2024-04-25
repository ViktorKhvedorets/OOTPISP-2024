#include <iostream>
#include "Document.h"
#include "invoice.h"
#include "receipt.h"
#include "check.h"

using namespace std;
int main()
{
    auto receipt_1 = receipt("receipt1", "payment");
    auto invoice_1 = invoice("invoice1", 5);
    auto check_1 = check("check1", 32);
    auto print = Document();

    receipt_1.SetName("receipt1_");
    invoice_1.SetName("invoice1_");
    check_1.SetName("check1_");
    print.SetName("print");

    print.Add();

    cout << "Non static method" << endl;

    check_1.Show();

    cout << endl;
    cout << "Static method" << endl;

    Document::PrintAll();
}