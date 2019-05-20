#include "iterator.hpp"
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<gof::Teacher> you = std::make_unique<gof::MyTeacher>(gof::MyTeacher());
    you->createStudentList();
    you->callStudents();
}
