// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
#include <string>
#include "Lab6Example.h"
int main()
{
    std::cout << " Lab #6  !\n";
    
// Завдання 2
class Quadrilateral {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Square : public Quadrilateral {
private:
    float side;
public:
    Square(float s) {
        side = s;
    }
    float area() {
        return side * side;
    }
    float perimeter() {
        return 4 * side;
    }
};

class Rectangle : public Quadrilateral {
private:
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }
    float area() {
        return length * width;
    }
    float perimeter() {
        return 2 * (length + width);
    }
};

class Parallelogram : public Quadrilateral {
private:
    float base, height, side;
public:
    Parallelogram(float b, float h, float s) {
        base = b;
        height = h;
        side = s;
    }
    float area() {
        return base * height;
    }
    float perimeter() {
        return 2 * (base + side);
    }
};

class Trapezium : public Quadrilateral {
private:
    float base1, base2, height, side1, side2;
public:
    Trapezium(float b1, float b2, float h, float s1, float s2) {
        base1 = b1;
        base2 = b2;
        height = h;
        side1 = s1;
        side2 = s2;
    }
    float area() {
        return ((base1 + base2) / 2) * height;
    }
    float perimeter() {
        return base1 + base2 + side1 + side2;
    }
};

int main() {
    Quadrilateral* q;
    Square s(5);
    Rectangle r(4, 6);
    Parallelogram p(8, 10, 5);
    Trapezium t(5, 10, 7, 6, 8);

    q = &s;
    cout << "Area of square = " << q->area() << endl;
    cout << "Perimeter of square = " << q->perimeter() << endl;

    q = &r;
    cout << "Area of rectangle = " << q->area() << endl;
    cout << "Perimeter of rectangle = " << q->perimeter() << endl;

    q = &p;
    cout << "Area of parallelogram = " << q->area() << endl;
    cout << "Perimeter of parallelogram = " << q->perimeter() << endl;

    q = &t;
    cout << "Area of trapezium = " << q->area() << endl;
    cout << "Perimeter of trapezium = " << q->perimeter() << endl;

    return 0;
}
    
    
//     Завдання 3
    
class Entity {
protected:
    string name;
public:
    Entity() {
        name = "";
    }
    Entity(string n) {
        name = n;
    }
    virtual void printInfo() = 0;
    virtual void readInfo() = 0;
    virtual ~Entity() {}
};

class Person : virtual public Entity {
protected:
    int age;
public:
    Person() : Entity() {
        age = 0;
    }
    Person(string n, int a) : Entity(n) {
        age = a;
    }
    virtual void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual void readInfo() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    virtual ~Person() {}
};

class Father : virtual public Person {
protected:
    string occupation;
public:
    Father() : Entity(), Person() {
        occupation = "";
    }
    Father(string n, int a, string o) : Entity(n), Person(n, a) {
        occupation = o;
    }
    virtual void printInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Occupation: " << occupation << endl;
    }
    virtual void readInfo() {
        Person::readInfo();
        cout << "Enter occupation: ";
        cin >> occupation;
    }
    virtual ~Father() {}
};

class Mother : virtual public Person {
protected:
    string occupation;
public:
    Mother() : Entity(), Person() {
        occupation = "";
    }
    Mother(string n, int a, string o) : Entity(n), Person(n, a) {
        occupation = o;
    }
    virtual void printInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Occupation: " << occupation << endl;
    }
    virtual void readInfo() {
        Person::readInfo();
        cout << "Enter occupation: ";
        cin >> occupation;
    }
    virtual ~Mother() {}
};

class Son : public Father, public Mother {
protected:
    string hobby;
public:
    Son() : Father(), Mother() {
        hobby = "";
    }
    Son(string n, int a, string fo, string mo, string h) : Person(n, a), Father(n, a, fo), Mother(n, a, mo) {
        hobby = h;
    }
    void printInfo() {
        Father::printInfo();
    }
    void readInfo() {
        Father::readInfo();
        cout << "Enter hobby: ";
        cin >> hobby;
    }
    virtual ~Son() {}
};


int main() {
    Son son;
    son.readInfo();
    son.printInfo();
    return 0;
}
    
    
    Example();

}
