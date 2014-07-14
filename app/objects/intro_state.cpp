#include "../heads/intro_state.h"
#include <iostream>

Intro::Intro() : area(MENU) {}

void Intro::init() { std::cout << "init Intro State \n"; }

int Intro::nextArea() { return area; }
