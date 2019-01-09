#include <iostream>


class MyClass {
public:
    MyClass(int x, int y, int z)
    :day(x), month(y), year(z)
    {
        std::cout<<day<<"/"<<month<<"/"<<year<<"\n";
    }
private:
    int day;
    int month;
    int year;
};

class ParentClass {
public:
    ParentClass(int p, MyClass) {
        name = p;
        std::cout<<"In ParentClass\n";
    }
    void printVar() {
        std::cout<<name;
    }
private:
    int name;
};


int main() {

    std::cout<<"test\n";
    MyClass myClassObj(30,11,1991);
    ParentClass parentClassObj(10, myClassObj);
    parentClassObj.printVar();


    return 0;
}
