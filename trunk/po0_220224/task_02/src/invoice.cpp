#include "invoice.h"

invoice::invoice(const std::string &name, const uint32_t pages)
    : Document(name), mPages(pages)
{
}

void invoice::Show() const
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