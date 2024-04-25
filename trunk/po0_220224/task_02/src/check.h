#include "Document.h"

class check : public Document
{
public:
    check() = default;
    check(const std::string &name, const uint32_t pages);

    void Set(std::string_view name, const uint32_t pages);

    inline uint32_t GetPages() const { return mPages; };

    void Show() const override;

private:
    uint32_t mPages;
};