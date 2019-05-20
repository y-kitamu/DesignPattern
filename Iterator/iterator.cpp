#include "iterator.hpp"

namespace gof {

MyStudentList::MyStudentList() : StudentList(5) {
    add(Student("赤井亮太", 1));
    add(Student("赤羽里美", 0));
    add(Student("岡田美央", 0));
    add(Student("西森俊介", 1));
    add(Student("中ノ森玲菜", 0));
}


Iterator MyStudentList::iterator() {
    return MyStudentListIterator(*this);
}


MyStudentListIterator::MyStudentListIterator(MyStudentList list) {
    my_student_list = list;
    index = 0;

}

} // namespace gof
