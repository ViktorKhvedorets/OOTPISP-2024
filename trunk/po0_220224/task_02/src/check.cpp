#include "check.h"

check::check(const std::string &name, const uint32_t pages)
    : Document(name), mPages(pages)
{
}

void check::Set(std::string_view name, const uint32_t pages)
{
    this->SetName(name);
    this->mPages = pages;
}

void check::Show() const
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