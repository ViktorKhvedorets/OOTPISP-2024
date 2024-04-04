
#include <iostream>
#include "PrintPublication.h"
#include "Journal.h"
#include "Book.h"
#include "Textbook.h"

int main()
{
    auto book_1 = Book("book_1", "novel");
    auto journal_1 = Journal("journal_1", 5);
    auto textbook_1 = Textbook("textbook_1", 32);
    auto print = PrintPublication();

    book_1.SetName("Book_1_");
    journal_1.SetName("Journal_1_");
    textbook_1.SetName("Textbook_1_");
    print.SetName("print");

    print.Add();

    std::cout << "Non static method" << std::endl;

    textbook_1.Show();

    std::cout << std::endl;
    std::cout << "Static method" << std::endl;

    PrintPublication::PrintAll();
}
