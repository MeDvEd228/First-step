
#include <iostream>
#include <string>
#include <stack>

using namespace std;

    string dec2some(uint32_t num, uint32_t notation) //данная функция переводит числол из десятичной системы 
                                                     //исчесления в двоичную или шестнадцатеричную изпользуя очередь queue 
    {
        string res;
        if (notation >= 2 && notation <= 36)
        {
            const char digs[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            stack <uint32_t> st;
            while (num)
            {
                st.push(num % notation);
                num /= notation;
            }
            while (!st.empty())
            {
                res += digs[st.top()];
                st.pop();
            }
        }
        return res;
    }


    int main()
    {
        setlocale(LC_ALL, "Russian");
        cout << dec2some(19, 2); // первый передоваемый аргумент это число которое хотите перевести,
                                 //второй это система в которую вы хотите перевсти (2 - двоичная, 16 - шестнадцатеричная)
    }
   

