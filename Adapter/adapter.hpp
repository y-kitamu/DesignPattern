#include <iostream>


namespace gof {

class Taro {
  public:
    void enjoyWithAll() {
        std::cout << "enjoy" << std::endl;
    }
};

class Chairman {
  public:
    virtual void organizeClass() = 0;
};

class NewTaro : public Chairman, Taro {
  public:
    void organizeClass() override { enjoyWithAll(); }
};

class Hanako : public Chairman {
  public:
    void organizeClass() override { taro.enjoyWithAll(); }
    
  private:
    Taro taro;
};

class Teacher {
  public:
    Teacher() {
        Chairman *chairman = new NewTaro();
        chairman->organizeClass();

        Chairman *chairman2 = new Hanako();
        chairman2->organizeClass();
    }
};

}
