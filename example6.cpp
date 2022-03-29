#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

ShoppingList makeFile(const char* filename, const char* flags)
{
    auto fp = std::fopen(filename, flags);
    if (!fp)
        throw std::runtime_error("Could not open file");
    return std::shared_ptr<std::FILE>(fp, std::fclose);
}

class Partner
{
public:
    void addToFile(std::string element)
    {
        fprintf(shoppingList.get(), "%s\n", element.c_str());
    }
    ShoppingList shoppingList;
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
}
