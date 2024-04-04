#include "PrintPublication.h"

PrintPublication::PrintPublication(const std::string &name)
    : mName(name)
{
    if (begin == nullptr)
    {
        begin = this;
    }
    next = nullptr;
    if (last != nullptr)
    {
        last->SetNext(this);
    }
    last = this;
}

void PrintPublication::ShowNonVirtual() const
{
    std::cout << "This is print publication" << std::endl;
}

void PrintPublication::Show() const
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        std::cout << ptr->GetName() << std::endl;
        ptr = ptr->next;
    }
}

void PrintPublication::Add()
{
    if (begin == nullptr)
    {
        begin = this;
    }
    next = nullptr;
    if (last != nullptr)
    {

        last->SetNext(this);
    }
    last = this;
}

void PrintPublication::SetName(std::string_view name)
{
    this->mName = name;
}

void PrintPublication::PrintAll()
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        std::cout << ptr->GetName() << std::endl;
        ptr = ptr->GetNext();
    }
}

void PrintPublication::SetNext(PrintPublication *nextNode)
{
    next = nextNode;
}

PrintPublication *PrintPublication::begin = nullptr;
PrintPublication *PrintPublication::last = nullptr;
