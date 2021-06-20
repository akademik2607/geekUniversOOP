#include<iostream>
#include<cmath>
#include<cstdint>
#include<climits>


//1. Создать класс Power, который содержит два вещественных числа. 
//Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
//Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate,
//который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.


class Power{
    private:
        double _value;
        double _pow;
    public:
        Power( double value=2, double pow=3) 
            : _value(value), _pow(pow) {}

        void set(double value, double pow) {
            _value = value;
            _pow = pow;
        }

        void calculate() {
            std::cout <<_value << " ^ " << _pow << " = " << pow(_value, _pow) << std::endl;
        }
};

//2.Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha 
//(#include cstdint для доступа к этому типу). 
//Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
//Создать конструктор со списком инициализации членов, 
//который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
//Написать функцию print(), которая будет выводить значения переменных-членов.

class RGBA{
    private:
        std::uint8_t m_red;
        std::uint8_t m_green;
        std::uint8_t m_blue;
        std::uint8_t m_alpha;
    public:
        RGBA(std::uint8_t red=0, std::uint8_t green=0, std::uint8_t blue=0, std::uint8_t alpha = 255) 
            : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}
        
        void print(){
            std::cout << "Цветовая схема: " << "R-" << static_cast<int>(m_red) << ", G-" << static_cast<int>(m_green) << ", B-" 
                << static_cast<int>(m_blue) << ", A-" << static_cast<int>(m_alpha) << std::endl;
        }
};

//3.Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
//private-массив целых чисел длиной 10;
//private целочисленное значение для отслеживания длины стека;
//public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
//public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
//public-метод с именем print(), который будет выводить все значения стека.

class Stack{
    private:
        int arr[10];
        int length;
    public:
        Stack() : length(0){}

        void reset(){
            length = 0;
            for(int i = 0; i < 10; i++){
                arr[i] = 0;
            }
        }

        bool push(int val){
            if(length == 10) return false;

            arr[length] = val;
            length++;
            return true;
        }

        int pop(){
            if(length == 0){
                std::cout << "Стек пуст!" << std::endl;
                return INT_MAX;
            }
            length--;
            return arr[length];
        }

        void print(){
            std::cout << "( ";
            for(int i = 0; i < length;i++){
                std::cout << arr[i] << " ";
            }
            std::cout << ")" << std::endl;
        }


};


int main(){
    std::cout << "1 задание: " << std::endl;
    Power p(3);
    p.calculate();
    p.set(4, 3);
    p.calculate();
    std::cout << std::endl;

    std::cout << "2 задание: " << std::endl;
    RGBA rgba(23, 45, 55);
    rgba.print();
    std::cout << std::endl;

    std::cout << "3 задание: " << std::endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
