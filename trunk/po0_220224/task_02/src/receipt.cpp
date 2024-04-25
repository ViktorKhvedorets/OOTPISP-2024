#include "receipt.h"

receipt::receipt(const std::string &name, const std::string &ganre)
    : Document(name), mGanre(ganre)
{
}

void receipt::Set(std::string_view name, std::string_view ganre)
{
    this->SetName(name);
    this->mGanre = ganre;
}

void receipt::Show() const
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