#include <iostream>
#include "menu/Menu.h"

void Menu::show() const {
    std::cout << "====== MSH MENU ======" << std::endl;
    std::cout << "1) Get Home Status" << std::endl;
    std::cout << "8) Manual" << std::endl;
    std::cout << "0) Shutdown" << std::endl;
}
