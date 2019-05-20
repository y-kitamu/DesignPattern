#include <vector>
#include <string>
#include <iostream>

namespace gof {

class Student {
  public:
    Student() {}
    Student(std::string name, int gender) : name(name), gender(gender) {}
    std::string getName() { return name; }
    int getGender() { return gender; }
    
  private:
    std::string name;
    int gender;
};

class Iterator {
    virtual bool hasNext() = 0;
    virtual Student next() = 0;
};

class Aggregate {
    virtual Iterator iterate() = 0;
};


class StudentList {
  public:
    StudentList() {}
    virtual ~StudentList() {}
    StudentList(int student_count) {
        students = std::vector<Student>(student_count);
    }

    virtual Iterator iterator() = 0;

    void add(const Student &student) {
        students[last] = student;
        last++;
    }

    Student getStudentAt(int index)  { return students[index]; }

    int getLastNum() { return last; }
    
  protected:
    std::vector<Student> students;

  private:
    int last = 0;
};

class MyStudentList : public StudentList {
  public:
    MyStudentList();
    Iterator iterator();
};

class Teacher {
  public:
    virtual void createStudentList() = 0;
    virtual void callStudents() = 0;
    virtual ~Teacher() {};
    
  protected:
    StudentList studentList;
};


class MyStudentListIterator : Iterator {
  public:
    MyStudentListIterator(MyStudentList list);
    
    bool hasNext() { return index < my_student_list.getLastNum() - 1; }
    Student next() {
        Student s = my_student_list.getStudentAt(index);
        index++;
        return s;
    }
    
  private:
    MyStudentList my_student_list;
    int index;
};


class MyTeacher : public Teacher {
  public:
    virtual void createStudentList() override {
        studentList = MyStudentList();
    }
    
    virtual void callStudents() override {
        for (int i = 0; i < studentList.getLastNum(); i++) {
            std::cout << studentList.getStudentAt(i).getName() << std::endl;
        }
    }
};

} // gof
