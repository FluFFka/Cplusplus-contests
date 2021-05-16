#include <functional>
#include <vector>
#include <map>
#include <string>

namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack info;
        std::map<std::string, std::function<void(complex_stack &, complex)> > commands {
            {"z", [](complex_stack &info, complex z) { info = info << z; }},
            {"+",
            [](complex_stack &info, complex z) {
                complex tmp1 = +info;
                info = ~info;
                complex tmp2 = +info;
                info = ~info;
                info = info << tmp1 + tmp2;
            }},
            {"-",
            [](complex_stack &info, complex z) {
                complex tmp1 = +info;
                info = ~info;
                complex tmp2 = +info;
                info = ~info;
                info = info << tmp2 - tmp1;
            }},
            {"*",
            [](complex_stack &info, complex z) {
                complex tmp1 = +info;
                info = ~info;
                complex tmp2 = +info;
                info = ~info;
                info = info << tmp1 * tmp2;
            }},
            {"/",
            [](complex_stack &info, complex z) {
                complex tmp1 = +info;
                info = ~info;
                complex tmp2 = +info;
                info = ~info;
                info = info << tmp2 / tmp1;
            }},
            {"!", [](complex_stack &info, complex z) { info = info << (+info); }},
            {";", [](complex_stack &info, complex z) { info = ~info; }},
            {"~",
            [](complex_stack &info, complex z) {
                complex tmp = +info;
                info = ~info;
                info = info << ~tmp;
            }},
            {"#",
            [](complex_stack &info, complex z){
                complex tmp = +info;
                info = ~info;
                info = info << -tmp;
            }}
        };
        for (size_t i = 0; i < args.size(); ++i) {
            if (args[i][0] == '(') {
                commands["z"](info, complex(args[i]));
            } else {
                commands[args[i]](info, z);
            }
        }
        return +info;
    }
}