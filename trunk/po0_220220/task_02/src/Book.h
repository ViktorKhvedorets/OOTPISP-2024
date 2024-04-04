#include "PrintPublication.h"

class Book : public PrintPublication
{
public:
    Book() = default;
    Book(const std::string &name, const std::string &ganre);

    void Set(std::string_view name, std::string_view ganre);

    inline std::string GetGanre() const { return mGanre; };

    void Show() const override;

private:
    std::string mGanre;
};
