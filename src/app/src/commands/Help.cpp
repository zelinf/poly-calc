#include "Help.h"
#include <sstream>
#include "../Executor.h"

namespace Zelinf {
namespace PolyCalc {
namespace App {
namespace Commands {


std::vector<std::string> Help::names() const {
    return {"help", "h"};
}

std::string Help::run(std::vector<std::string> args) {
    std::ostringstream os;
    os << "Commands start with ':', such as ':help'\n";
    os << "Lines without leading ':' are treated as statements.\n";
    os << "Available commands:\n";
    for (auto cmd_pt : executor.getCommands()) {
        os << "\t:";
        std::vector<std::string> names = cmd_pt->names();
        for (size_t i = 0; i < names.size(); i++) {
            os << names[i];
            if (i != names.size() - 1) {
                os << '|';
            }
        }
        os << " --> " << cmd_pt->helpInfo() << '\n';
    }
    os << "Statement Syntax(TODO):\n";
    // TODO

    return os.str();
}

std::string Help::helpInfo() const {
    return "Shows this help";
}

}
}
}
}
