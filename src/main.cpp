#include "cli/command_handler.hpp"

#include <iostream>
#include <string>

int main() {
    cli::CommandHandler commandHandler;

    std::cout << "=========================================\n";
    std::cout << "        Unit Converter CLI Ready         \n";
    std::cout << "=========================================\n";
    std::cout << "Type HELP to view available commands.\n\n";

    std::string line;
    while (true) {
        std::cout << "converter> ";
        if (!std::getline(std::cin, line) || line == "EXIT" || line == "exit") {
            std::cout << "Goodbye!\n";
            break;
        }

        if (line.empty()) {
            continue;
        }

        commandHandler.execute(line);
    }

    return 0;
}