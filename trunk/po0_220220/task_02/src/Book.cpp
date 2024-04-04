
#include "Book.h"

Book::Book(const std::string &name, const std::string &ganre)
    : PrintPublication(name), mGanre(ganre)
{
}

void Book::Set(std::string_view name, std::string_view ganre)
{
    this->SetName(name);
    this->mGanre = ganre;
}

void Book::Show() const
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        std::cout << ptr->GetName() << std::endl;
        ptr = ptr->GetNext();
        if (ptr == this->GetNext())
            break;
    }
}