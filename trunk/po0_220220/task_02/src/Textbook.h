#include "PrintPublication.h"

class Textbook : public PrintPublication
{
public:
    Textbook() = default;
    Textbook(const std::string &name, const uint32_t pages);

    void Set(std::string_view name, const uint32_t pages);

    inline uint32_t GetPages() const { return mPages; };

    void Show() const override;

private:
    uint32_t mPages;
};