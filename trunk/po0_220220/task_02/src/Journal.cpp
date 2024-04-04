#include "Journal.h"

Journal::Journal(const std::string &name, const uint32_t pages)
    : PrintPublication(name), mPages(pages)
{
}

void Journal::Show() const
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