#pragma once

#include <iostream>
#include <string>

class PrintPublication
{
public:
    PrintPublication() = default;
    explicit PrintPublication(const std::string &name);

    inline std::string GetName() const { return mName; }
    inline PrintPublication *GetNext() const { return next; };
    void ShowNonVirtual() const;
    virtual void Show() const;
    void Add();
    void SetName(std::string_view name);

    virtual ~PrintPublication() = default;

    static void PrintAll();

private:
    std::string mName = "";
    PrintPublication *next = nullptr;

protected:
    void SetNext(PrintPublication *nextNode);

    static PrintPublication *begin;
    static PrintPublication *last;
};
