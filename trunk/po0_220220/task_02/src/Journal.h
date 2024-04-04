#include "PrintPublication.h"

class Journal : public PrintPublication
{
public:
    Journal() = default;
    Journal(const std::string &name, const uint32_t pages);

    inline uint32_t GetPages() const { return mPages; };

    void Show() const override;

private:
    uint32_t mPages;
};