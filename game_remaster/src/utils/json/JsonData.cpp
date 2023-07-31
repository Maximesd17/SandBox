#include "JsonData.hpp"


JsonData::JsonData(const json& j) 
: j_(j) 
{

}

void JsonData::print() const 
{
    print_recursive(j_, 0);
}

void JsonData::print_recursive(const json& j, int indent) 
{
    std::string indent_str(indent * 2, ' ');

    if (j.is_array()) 
    {
        std::cout << indent_str << "[\n";

        for (const nlohmann::json& element : j) 
            print_recursive(element, indent + 1);
        std::cout << indent_str << "]\n";
    } 
    else if (j.is_object()) 
    {
        std::cout << indent_str << "{\n";

        for (const nlohmann::detail::iteration_proxy_value<nlohmann::detail::iter_impl<const nlohmann::json>>& element : j.items()) 
        {
            std::cout << indent_str << "  \"" << element.key() << "\": ";
            print_recursive(element.value(), indent + 1);
        }

        std::cout << indent_str << "}\n";
    } 
    else 
        std::cout << indent_str << j << "\n";
}

void JsonData::writeToFile(const std::string& filename) const 
{
    std::ofstream outFile(filename);

    if (!outFile.is_open()) 
    {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    outFile << j_;
    outFile.close();
}
