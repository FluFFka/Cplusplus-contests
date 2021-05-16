#include <iostream>
#include <memory>
#include <functional>
#include <map>
#include <algorithm>

class Factory
{
    std::map<char, std::function<std::unique_ptr<Figure>(std::string)> > creators {
        {'R', [](std::string params){ return std::unique_ptr<Figure>(Rectangle::make(params)); }},
        {'S', [](std::string params){ return std::unique_ptr<Figure>(Square::make(params)); }},
        {'C', [](std::string params){ return std::unique_ptr<Figure>(Circle::make(params)); }},
    };
    Factory() = default;
public:
    Factory(const Factory&) = delete;
    Factory & operator=(Factory &) = delete;
    static Factory & factory_instance() {
        static Factory instance;
        return instance;
    }
    std::unique_ptr<Figure> Create(char type, std::string params) {
        return creators[type](params);
    } 
};

int main()
{
    char type;
    std::string params;
    std::vector<std::unique_ptr<Figure> > figures;
    while (std::cin >> type) {
        std::getline(std::cin, params);
        figures.push_back(Factory::factory_instance().Create(type, params));
    }
    stable_sort(figures.begin(), figures.end(),
            [](const std::unique_ptr<Figure> &lhs, const std::unique_ptr<Figure> &rhs) {
                return lhs->get_square() < rhs->get_square();
            });
    for (auto &el : figures) {
        std::cout << el->to_string() << std::endl;
    }
}