#include "cli/command_handler.hpp"
#include "category/category_type.hpp"
#include "category/unit_parser.hpp"

#include <iostream>
#include <sstream>

namespace cli {

void CommandHandler::execute(const std::string& inputLine) {
    std::istringstream iss(inputLine);
    std::string command;
    iss >> command;

    std::string remainingArgs;
    std::getline(iss >> std::ws, remainingArgs);

    if (command == "CONVERT" || command == "CV") {
        handleConvert(remainingArgs);
    } else if (command == "LIST" || command == "LS") {
        handleList(remainingArgs);
    } else if (command == "HELP" || command == "H") {
        printHelp();
    } else {
        std::cout << "Unknown command. Type HELP for available commands.\n";
    }
}

void CommandHandler::handleConvert(const std::string& args) {
    std::istringstream iss(args);
    std::string categoryStr, fromUnitStr, toUnitStr;
    double value;

    // Syntax: CONVERT <CATEGORY> <VALUE> <FROM_UNIT> <TO_UNIT>
    if (!(iss >> categoryStr >> value >> fromUnitStr >> toUnitStr)) {
        std::cout << "Usage: CONVERT <CATEGORY> <VALUE> <FROM_UNIT> <TO_UNIT>\n"
                  << "Example: CONVERT LENGTH 100 FT METER\n";
        return;
    }

    category::CategoryType catType = category::stringToCategory(categoryStr);

    switch (catType) {
        case category::CategoryType::LENGTH: {
            auto from = category::stringToLengthUnit(fromUnitStr);
            auto to = category::stringToLengthUnit(toUnitStr);
            if (from == category::LengthUnit::UNKNOWN || to == category::LengthUnit::UNKNOWN) {
                std::cout << "[Error] Invalid length unit specified.\n";
                return;
            }
            auto res = convertor.convertLength(value, from, to);
            if (res) {
                std::cout << value << " " << category::lengthUnitToString(from)
                          << " = " << *res << " " << category::lengthUnitToString(to) << "\n";
            }
            break;
        }

        case category::CategoryType::WEIGHT: {
            auto from = category::stringToWeightUnit(fromUnitStr);
            auto to = category::stringToWeightUnit(toUnitStr);
            if (from == category::WeightUnit::UNKNOWN || to == category::WeightUnit::UNKNOWN) {
                std::cout << "[Error] Invalid weight unit specified.\n";
                return;
            }
            auto res = convertor.convertWeight(value, from, to);
            if (res) {
                std::cout << value << " " << category::weightUnitToString(from)
                          << " = " << *res << " " << category::weightUnitToString(to) << "\n";
            }
            break;
        }

        case category::CategoryType::TEMPERATURE: {
            auto from = category::stringToTempUnit(fromUnitStr);
            auto to = category::stringToTempUnit(toUnitStr);
            if (from == category::TempUnit::UNKNOWN || to == category::TempUnit::UNKNOWN) {
                std::cout << "[Error] Invalid temperature unit specified.\n";
                return;
            }
            auto res = convertor.convertTemp(value, from, to);
            if (res) {
                std::cout << value << " " << category::tempUnitToString(from)
                          << " = " << *res << " " << category::tempUnitToString(to) << "\n";
            }
            break;
        }

        case category::CategoryType::DATA: {
            auto from = category::stringToDataUnit(fromUnitStr);
            auto to = category::stringToDataUnit(toUnitStr);
            if (from == category::DataUnit::UNKNOWN || to == category::DataUnit::UNKNOWN) {
                std::cout << "[Error] Invalid data unit specified.\n";
                return;
            }
            auto res = convertor.convertData(value, from, to);
            if (res) {
                std::cout << value << " " << category::dataUnitToString(from)
                          << " = " << *res << " " << category::dataUnitToString(to) << "\n";
            }
            break;
        }

        default:
            std::cout << "[Error] Unknown category: " << categoryStr << "\n";
            break;
    }
}

void CommandHandler::handleList(const std::string& args) {
    category::CategoryType catType = category::stringToCategory(args);

    if (args == "*" || args.empty()) {
        std::cout << "\nSupported Categories & Units:\n"
                  << "  • LENGTH:      METER, KILOMETER, CENTIMETER, MILLIMETER, MILE, FOOT, INCH\n"
                  << "  • WEIGHT:      GRAM, KILOGRAM, MILLIGRAM, POUND, OUNCE\n"
                  << "  • TEMPERATURE: KELVIN, CELSIUS, FAHRENHEIT\n"
                  << "  • DATA:        BYTE, KILOBYTE, MEGABYTE, GIGABYTE, TERABYTE\n\n";
        return;
    }

    switch (catType) {
        case category::CategoryType::LENGTH:
            std::cout << "LENGTH Units: METER (MT), KILOMETER (KM), CENTIMETER (CM), MILLIMETER (MM), MILE (MI), FOOT (FT), INCH (IN)\n";
            break;
        case category::CategoryType::WEIGHT:
            std::cout << "WEIGHT Units: GRAM (GM), KILOGRAM (KG), MILLIGRAM (MG), POUND (PD), OUNCE (OU)\n";
            break;
        case category::CategoryType::TEMPERATURE:
            std::cout << "TEMPERATURE Units: KELVIN (K), CELSIUS (C), FAHRENHEIT (F)\n";
            break;
        case category::CategoryType::DATA:
            std::cout << "DATA Units: BYTE (B), KILOBYTE (KB), MEGABYTE (MB), GIGABYTE (GB), TERABYTE (TB)\n";
            break;
        default:
            std::cout << "[Error] Unknown category specified for LIST.\n";
            break;
    }
}

void CommandHandler::printHelp() const {
    std::cout << "\nAvailable Commands:\n"
              << "  CONVERT <CATEGORY> <VAL> <FROM> <TO> - Convert values across units\n"
              << "  LIST <CATEGORY> | LIST *             - List supported units\n"
              << "  HELP                                 - Display help menu\n"
              << "  EXIT                                 - Exit application\n\n";
}

} // namespace cli