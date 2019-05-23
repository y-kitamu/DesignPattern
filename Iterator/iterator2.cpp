#include "iterator2.hpp"
#include <iostream>


namespace gof {

std::shared_ptr<Iterator> StudentList::iterator() {
    std::shared_ptr<Iterator> ptr;

    ptr = std::make_shared<StudentListIterator>(StudentListIterator(*this));
    return ptr;
}

void Teacher::createStudentList() {
    student_list = StudentList(5);

    student_list.add(Student("赤井亮太", 1));
    student_list.add(Student("赤羽里美", 0));
    student_list.add(Student("岡田美央", 0));
    student_list.add(Student("西森俊介", 1));
    student_list.add(Student("中ノ森玲菜", 0));
}

void Teacher::callStudent() {
    auto iter = student_list.iterator();

    while (iter->hasNext()) {
        auto s = iter->next();
        std::cout << s.getName() << " , " << s.getGender() << std::endl;
    }
}

} // namespace gof
