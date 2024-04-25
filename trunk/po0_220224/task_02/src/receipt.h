#include "Document.h"

class receipt : public Document
{
public:
    receipt() = default;
    receipt(const std::string &name, const std::string &ganre);

    void Set(std::string_view name, std::string_view ganre);

    inline std::string GetGanre() const { return mGanre; };

    void Show() const override;

private:
    std::string mGanre;
};