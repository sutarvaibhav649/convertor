#pragma once

#include "convertor/unit_convertor.hpp"
#include <string>

namespace cli {

class CommandHandler {
private:
    convertor::UnitConvertor convertor;

    void handleConvert(const std::string& args);
    void handleList(const std::string& args);
    void printHelp() const;

public:
    CommandHandler() = default;
    void execute(const std::string& inputLine);
};

} // namespace cli