#include <iostream>
#include <cstdint>

class Power
{
public:
    int a = 10;
    int b = 5;
    int x, y;
    int tmp = 1;

    void Set()
    {
        x = a;
        y = b;
    };

    void calculate()
    {
        for(int i = 0; i < y; i++) 
        {
            tmp *= x;
        }
        std::cout << tmp;
    };



};

class RGBA 
{
    private:
       std::uint8_t m_red = 0;
       std::uint8_t m_green = 0;
       std::uint8_t m_blue = 0;
       std::uint8_t m_alpha = 255;

    public:
        RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) :
            m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
        {
        }

        void print()
        {
            std::cout << "r=" << static_cast<int>(m_red) <<
                " g=" << static_cast<int>(m_green) <<
                " b=" << static_cast<int>(m_blue) <<
                " a=" << static_cast<int>(m_alpha) << '\n';
        }
    ~RGBA() {};
};

class Stack 
{
private:
    int SizeOfArray;
    int arr[10];
    int TMPA;
    int tmp = 0;

public:
    void reset()
    {
        for (int i = 0; i < 10; i++) 
        {
            arr[i] = 0;

        }
        SizeOfArray = 0;
    };

public:
    bool push(int Value)
    {
        for (int i = 0; i < 10; i++) 
        {
            if (arr[i] > 0)
                tmp++;
            if (tmp == 10) 
            {
                printf("Error! Stack is full!\n"); return false;
            }
        }
        arr[tmp] = Value; 
        tmp = 0;
        return true;
    };

public: 
    void pop() 
    {
        for (int i = 9; i != 0; i--)
        {
            if (arr[i] == 0)
                tmp++;
            if (tmp == 10)
                printf("Error! Stack is Empty!\n");
            TMPA = 9 - tmp;
        }
        arr[TMPA] = 0;
        tmp = 0;
    };

public:
    void print()
    {
        std::cout << "( ";
        for (int j = 0; j < 10; j++) 
        {
            if (arr[j] != 0 && arr[j] > 0) 
            {
                std::cout << arr[j] <<' ';
            }
        }
        std::cout << ')'<<std::endl;
    };

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Power power;
    power.Set();
    power.calculate();

    std::cout << std::endl;

    RGBA rgba(10,153,147); // вводить здесь
    rgba.print();

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

    stack.push(20);
    stack.print();

    return 0;
}