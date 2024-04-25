#include "Document.h"
#include<iostream>

using namespace std;

Document::Document(const std::string &name)
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

void Document::ShowNonVirtual() const
{
    cout << "This is print publication" << endl;
}

void Document::Show() const
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        cout << ptr->GetName() << endl;
        ptr = ptr->next;
    }
}

void Document::Add()
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

void Document::SetName(std::string_view name)
{
    this->mName = name;
}

void Document::PrintAll()
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        cout << ptr->GetName() << endl;
        ptr = ptr->GetNext();
    }
}

void Document::SetNext(Document *nextNode)
{
    next = nextNode;
}

Document *Document::begin = nullptr;
Document *Document::last = nullptr;