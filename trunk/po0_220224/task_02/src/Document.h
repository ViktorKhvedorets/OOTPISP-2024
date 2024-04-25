#pragma once

#include <iostream>
#include <string>

class Document
{
public:
    Document() = default;
    explicit Document(const std::string &name);

    inline std::string GetName() const { return mName; }
    inline Document *GetNext() const { return next; };
    void ShowNonVirtual() const;
    virtual void Show() const;
    void Add();
    void SetName(std::string_view name);

    virtual ~Document() = default;

    static void PrintAll();

private:
    std::string mName = "";
    Document *next = nullptr;

protected:
    void SetNext(Document *nextNode);

    static Document *begin;
    static Document *last;
};