#include <iostream>

#include "Country.hpp"

int main() {
    Country country;
    country.setName("NetherLands");
    country.setArea(10);

    Region holland("Holland", 5);
    holland.addDistrict(District("Amsterdamn", 2));
    holland.addDistrict("City_17", 3);

    Region hohland("Hohland", 5);
    hohland.addDistrict("Somebody", 2);
    hohland.addDistrict(District("That_I", 3));

    country.addRegion(holland);
    country.addRegion(hohland);

    if (country.isValid()) {
        std::cout << country << std::endl;
        for (const auto& region : country) {
            std::cout << "\t" << region << std::endl;
            for (const auto& district : region) {
                std::cout << "\t\t" << district << std::endl;
            }
        }
    } else {
        std::cout << "Некорректные значения площадей" << std::endl;
    }

    return 0;
}
