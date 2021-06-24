#include<iostream>
#include<vector>

//1.Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
//Определить методы переназначения имени, изменения возраста и веса. 
//Создать производный класс Student (студент), имеющий поле года обучения. 
//Определить методы переназначения и увеличения этого значения. 
//Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. 
//По запросу вывести определенного человека.

class Person{
    private:
        std::string m_name;
        int m_age;
        char m_sex;
        double m_weight;
    public:
        Person(std::string name, int age, char sex, double weight)
            : m_name(name), m_age(age), m_sex(sex), m_weight(weight) {}

        void setName(std::string name){
            m_name = name;
        }
        void setAge(int age){
            m_age = age;
        }
        void setWeight(double weight){
            m_weight = weight;
        }
        void printPersonInfo(){
            std::cout << "Имя: " << m_name << std::endl;
            std::cout << "Пол: " << m_sex << std::endl;
            std::cout << "Возраст: " << m_age << std::endl;
            std::cout << "Вес: " << m_weight << std::endl;
        }
};

class Student : public Person{
    private:
        int m_course;
    public:
        Student(std::string name, int age, char sex, double weight, int course =1 ) 
            : Person(name, age, sex, weight), m_course(course){
                counter++;
                students.push_back(this);
            }
        void yearEnd(){
            if(m_course < 5){
                m_course++;
            }
        }
        void AssignCourse(int course){
            if(course < 0 || course > 5){
                std::cout << "Некорректное назначение!" << std::endl;
                return;
            }
            m_course = course;
        }
        void printStudentInfo(){
            printPersonInfo();
            std::cout << "Курс: " << m_course<< std::endl;
        }
    static int counter;
    static std::vector<Student*> students;
    ~Student(){
        counter--;
    }
    static void searchStudent(int num);
};

    void Student::searchStudent(int num){
        if(num - 1 > students.size() || num - 1 <= 0){
            std::cout << "Студент с таким номером не числится!" << std::endl;
        }
        else {
            std::cout << "Даные студента под номером " << num << " - " << std::endl;
            students[num - 1]->printStudentInfo();
        }
    }

int Student::counter = 0;
std::vector<Student*> Student::students;

//2.Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
// У Fruit есть две переменные-члена: name (имя) и color (цвет). 
// Добавить новый класс GrannySmith, который наследует класс Apple.

class Fruit{
    private:
        std::string m_name;
        std::string m_color;
    public:
        Fruit(std::string color, std::string name="Fruit") 
            : m_color(color), m_name(name){}
        std::string getName(){
            return m_name;
        }
        std::string getColor(){
            return m_color;
        }
        void setName(std::string name){
            m_name = name;
        }
        void setColor(std::string color){
            m_color = color;
        }
};

class Apple : public Fruit{
    public:
        Apple(std::string color="green", std::string name="Apple") : Fruit(color, name){}

};

class Banana : public Fruit{
    public:
        Banana(std::string color="yellow", std::string name="Banana") : Fruit(color, name){}

};

class GrannySmith : public Apple{
    public:
        GrannySmith(std::string color="green", std::string name="Granny Smith") : Apple(color, name){}
};

//3. Базовый класс - Player производные: Diller, User
//класс Stek содержит Card
//enum value
//класс game

int main() {
    //1.
    Student s1("Alex", 21, 'm', 61);
    Student s2("Nadejda", 20, 'w', 45);
    Student s3("Anton", 30, 'w', 40);
    std::cout << Student::counter << std::endl;
    Student::searchStudent(2);
    //2.
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}

