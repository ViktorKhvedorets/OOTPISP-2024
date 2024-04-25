#include "Document.h"

class invoice : public Document
{
public:
    invoice() = default;
    invoice(const std::string &name, const uint32_t pages);

    inline uint32_t GetPages() const { return mPages; };

    void Show() const override;

private:
    uint32_t mPages;
};