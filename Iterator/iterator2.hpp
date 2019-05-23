#include <vector>
#include <string>
#include <memory>


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
  public:
    virtual bool hasNext() = 0;
    virtual Student next() = 0;
};


class Aggregate {
  public:
    virtual std::shared_ptr<Iterator> iterator() = 0;
};


class StudentList : public Aggregate {
  public:
    StudentList() {};
    StudentList(int count) { students = std::vector<Student>(count); };

    void add(Student student) {
        students[last] = student;
        last++;
    }
    Student getStudentAt(int index) { return students[index]; }
    int getLastNum() { return last; }
    
    std::shared_ptr<Iterator> iterator() override;
    
  protected:
    std::vector<Student> students;
    
  private:
    int last = 0;
};


class StudentListIterator : public Iterator {
  public:
    StudentListIterator(StudentList student_list) : student_list(student_list) { idx = 0; }
    bool hasNext() override { return idx != student_list.getLastNum(); }
    Student next() override {
        Student s = student_list.getStudentAt(idx);
        idx++;
        return s;
    }

  private:
    int idx;
    StudentList student_list;
};


class Teacher {
  protected:
    StudentList student_list;

  public:
    void createStudentList();
    void callStudent();
};

} //namespace gof
