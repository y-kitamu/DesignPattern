#include "iterator2.hpp"
#include <iostream>
#include <memory>

int main() {
    gof::Teacher you = gof::Teacher();

    you.createStudentList();
    you.callStudent();
}
