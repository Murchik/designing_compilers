#include <cctype>
#include <fstream>
#include <iostream>

#include "Country.hpp"

enum State { END, START, NAME, SIZE, CLOSE_BRACKET, INVALID_VALUE, ERROR };

class StateMachine {
   public:
    State getNewState(const State& state, int ch) {
        switch (state) {
            case START: {
                if (std::isalpha(ch)) {
                    _strBuff.push_back(ch);
                    return NAME;
                }
                return ERROR;

            } break;

            case NAME: {
                if (std::isalpha(ch)) {
                    _strBuff.push_back(ch);
                    return NAME;
                } else if (ch == ':') {
                    if (_strBuff.empty()) {
                        return ERROR;
                    }
                    if (_areaPtr->setName(_strBuff) != _strBuff) {
                        return INVALID_VALUE;
                    }
                    _strBuff.clear();
                    return SIZE;
                }
                return ERROR;
            } break;

            case SIZE: {
                if (std::isdigit(ch)) {
                    _strBuff.push_back(ch);
                    return SIZE;
                } else if (ch == '{') {
                    if (_strBuff.empty()) {
                        return ERROR;
                    }
                    int num = std::stoi(_strBuff);
                    if (_areaPtr->setArea(num) != num) {
                        return INVALID_VALUE;
                    }
                    _strBuff.clear();

                    Area* tmpAreaPtr = _areaPtr->createChild();
                    if (!tmpAreaPtr) {
                        return ERROR;
                    }
                    _areaPtr = tmpAreaPtr;
                    return NAME;
                } else if (ch == ',') {
                    if (_strBuff.empty()) {
                        return ERROR;
                    }
                    int num = std::stoi(_strBuff);
                    if (_areaPtr->setArea(num) != num) {
                        return INVALID_VALUE;
                    }
                    _strBuff.clear();

                    Area* tmpAreaPtr = _areaPtr->createSibling();
                    if (!tmpAreaPtr) {
                        return ERROR;
                    }
                    _areaPtr = tmpAreaPtr;
                    return NAME;
                } else if (ch == '}') {
                    if (_strBuff.empty()) {
                        return ERROR;
                    }
                    int num = std::stoi(_strBuff);
                    if (_areaPtr->setArea(num) != num) {
                        return INVALID_VALUE;
                    }
                    _strBuff.clear();

                    Area* tmpAreaPtr = _areaPtr->getParent();
                    if (!tmpAreaPtr) {
                        return ERROR;
                    }
                    _areaPtr = tmpAreaPtr;
                    if (!_areaPtr->isValid()) {
                        return INVALID_VALUE;
                    }
                    return CLOSE_BRACKET;
                }
                return ERROR;
            } break;

            case CLOSE_BRACKET: {
                if (ch == ',') {
                    Area* tmpAreaPtr = _areaPtr->createSibling();
                    if (!tmpAreaPtr) {
                        return ERROR;
                    }
                    _areaPtr = tmpAreaPtr;
                    return NAME;
                } else if (ch == '}') {
                    Area* tmpAreaPtr = _areaPtr->getParent();
                    if (!tmpAreaPtr) {
                        return ERROR;
                    }
                    _areaPtr = tmpAreaPtr;
                    if (!_areaPtr->isValid()) {
                        return INVALID_VALUE;
                    }
                    return CLOSE_BRACKET;
                } else if (ch == '\n') {
                    return END;
                }
                return ERROR;
            } break;

            case INVALID_VALUE: {
                return INVALID_VALUE;
            } break;

            case ERROR: {
                return ERROR;
            } break;

            case END: {
                return END;
            } break;

            default:
                break;
        }
        return state;
    }

    Country& getCountry() { return _country; }

   private:
    State _state;
    std::string _strBuff;

    Country _country;
    Area* _areaPtr = &_country;
};

int main() {
    StateMachine sm;

    std::ifstream file("data.txt");

    std::istreambuf_iterator<char> it(file);
    std::istreambuf_iterator<char> oef;
    std::string data(it, oef);

    int i = 0;
    State s = START;
    while (s != END && s != ERROR && s != INVALID_VALUE) {
        s = sm.getNewState(s, data[i]);
        i++;
    }

    if (s == ERROR) {
        std::cout << "Syntax Error - symb: '" << data[i - 1] << "', i = " << i
                  << std::endl;
    } else if (s == INVALID_VALUE) {
        std::cout << "Invalid Value - symb: '" << data[i - 1] << "', i = " << i
                  << std::endl;
    } else {
        std::cout << sm.getCountry() << std::endl;
        for (const auto& region : sm.getCountry()) {
            std::cout << "\t" << *region << std::endl;
            for (const auto& district : *region) {
                std::cout << "\t\t" << *district << std::endl;
            }
        }
    }

    return 0;
}
