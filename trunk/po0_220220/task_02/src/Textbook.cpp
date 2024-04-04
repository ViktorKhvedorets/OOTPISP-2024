#include "Textbook.h"

Textbook::Textbook(const std::string &name, const uint32_t pages)
    : PrintPublication(name), mPages(pages)
{
}

void Textbook::Set(std::string_view name, const uint32_t pages)
{
    this->SetName(name);
    this->mPages = pages;
}

void Textbook::Show() const
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