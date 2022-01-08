#include <iostream>
#include <random>
#include <chrono>
#include <stdlib.h>

using namespace std;

enum Cell
{
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_'
};

struct Coord 
{
    size_t y,x;
};

enum Progress 
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

#pragma pack(push, 1)
struct Game 
{
    Cell** ppField = nullptr;
    const short Size = 3;
    Progress progress = IN_PROGRESS;
    Cell ai;
    Cell human;
    short turn = 0;
};
#pragma pack(pop)

inline void clearScr() 
{
    system("cls");
}

int32_t getRandomNum(int32_t min, int32_t max) 
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);

}

void __fastcall initGame(Game & g) 
{
    g.ppField = new Cell * [g.Size];
    for (size_t i = 0; i < g.Size; i++)
    {
        g.ppField[i] = new Cell[g.Size];
    }

    for (size_t y = 0; y < g.Size; y++)
    {

        for (size_t x = 0; x < g.Size; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }

    if (getRandomNum(0, 1000) > 500) 
    {
        g.ai = CROSS;
        g.human = ZERO;
        g.turn = 1;
    }
    else 
    {
        g.ai = ZERO;
        g.human = CROSS ;
        g.turn = 0;
    }

}

void __fastcall deinitGame(Game& g)
{
    for (size_t i = 0; i < g.Size; i++) 
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}

void __fastcall printGame(const Game& g) 
{
    cout << "    ";
    for (size_t i = 0; i < g.Size; i++)
    {
        cout << i + 1 << "   ";
    }
    cout << endl;
    for (size_t y = 0; y < g.Size; y++)
    {
        cout << y + 1 << " | ";
        for (size_t x = 0; x < g.Size; x++)
        {
            cout << (char)g.ppField[y][x] << " | ";
        }
        cout << endl;
    }
    cout << endl << "Human: " << (char)g.human << endl;
    cout << "Computer: " << (char)g.ai << endl << endl;
}

Progress __fastcall getWon(const Game& g)
{
    //строки
    for (size_t y = 0; y < g.Size; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
            {
                return WON_HUMAN;
            }
            if (g.ppField[y][0] == g.ai)
            {
                return WON_AI;
            }
        }
    }
    //столбики
    for (size_t x = 0; x < g.Size; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
            {
                return WON_HUMAN;
            }
            if (g.ppField[0][x] == g.ai)
            {
                return WON_AI;
            }
        }
    }
    //главная диоганаль
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[0][0] == g.human)
        {
            return WON_HUMAN;
        }
        if (g.ppField[0][0] == g.ai)
        {
            return WON_AI;
        }
    }
    //побочная диоганаль
    if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[2][0])
    {
        if (g.ppField[1][1] == g.human)
        {
            return WON_HUMAN;
        }
        if (g.ppField[1][1] == g.ai)
        {
            return WON_AI;
        }
    }

    //DRAW
    bool draw = true;
    for (size_t y = 0; y < g.Size; y++)
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            if (g.ppField[y][x] != EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }

    if (draw)
    {
        return DRAW;
    }


}

Coord __fastcall getCoordHuman(const Game & g) 
{
    Coord c;
    do 
    {
        cout << "Enter x coord: ";
        cin >> c.x;
        cout << "Enter y coord: ";
        cin >> c.y;
    } while (c.x == 0 || c.x > 3 || c.y == 0 || c.y > 3 || g.ppField[c.y - 1][c.x - 1] != EMPTY);
    if (c.x == 10 || c.y == 10) 
    {
        exit;
    }
    c.x--;
    c.y--;
    return c;
}

Coord __fastcall getCoordAi(Game& g)
{
    if (g.ppField[1][1] == EMPTY)
        return { 1,1 };
    Coord arr[4];
    size_t count = 0;

    //angles
    if (g.ppField[0][0] == EMPTY)
    {
        arr[count] = { 0,0 };
        count++;
    };
    if (g.ppField[2][2] == EMPTY)
    {
        arr[count] = { 2,2 };
        count++;
    };
    if (g.ppField[2][0] == EMPTY)
    {
        arr[count] = { 2,0 };
        count++;
    };
    if (g.ppField[0][2] == EMPTY)
    {
        arr[count] = { 0,2 };
        count++;
    };

    if (count > 0) 
    {
        size_t index = getRandomNum(0, 1000) % count;
        return arr[index];
    }

    //centers
    count = 0;
    
    if (g.ppField[0][1] == EMPTY)
    {
        arr[count] = { 0,1 };
        count++;
    };
    if (g.ppField[2][1] == EMPTY)
    {
        arr[count] = { 2,1 };
        count++;
    };
    if (g.ppField[1][0] == EMPTY)
    {
        arr[count] = { 1,0 };
        count++;
    };
    if (g.ppField[1][2] == EMPTY)
    {
        arr[count] = { 1,2 };
        count++;
    };

    if (count > 0)
    {
        size_t index = getRandomNum(0, 1000) % count;
        return arr[index];
    };

    // pre win situation
    for (size_t y = 0; y < g.Size; y++) 
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            if (g.ppField[y][x]==EMPTY) 
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI) 
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    // pre lose situation
    for (size_t y = 0; y < g.Size; y++)
    {
        for (size_t x = 0; x < g.Size; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }
}

void __fastcall Congrats(const Game& g)
{
    if (g.progress == WON_HUMAN) 
    {
        cout << "Human won! =)" << endl;
    }
    else if (g.progress == WON_AI) 
    {
        cout << "Computer won! =/" << endl;
    }
    else if (g.progress == DRAW)
    {
        cout << "DRAW! =("<< endl;
    }
}

void Dvijok() 
{
    Game g;
       initGame(g);
       Coord c;
       clearScr();
       printGame(g);
    do
    {

        if (g.turn % 2 == 0)
        {
            c = getCoordHuman(g);
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {
            c = getCoordAi(g);
            g.ppField[c.y][c.x] = g.ai;
        }

        g.turn++;
        clearScr();
        printGame(g);

        g.progress = getWon(g);

    } while (g.progress == IN_PROGRESS);
    Congrats(g);
    deinitGame(g);

}
int main()
{
    Game g;
    do {
        /*
        initGame(g);
        Coord c;
        clearScr();
        printGame(g);

        do
        {

            if (g.turn % 2 == 0)
            {
                c = getCoordHuman(g);
                g.ppField[c.y][c.x] = g.human;
            }
            else
            {
                c = getCoordAi(g);
                g.ppField[c.y][c.x] = g.ai;
            }

            g.turn++;
            clearScr();
            printGame(g);

            g.progress = getWon(g);

        } while (g.progress == IN_PROGRESS);

        Congrats(g);
        */

        string Ans;
        cout << "Start game? y/n" << endl;
        cin >> Ans;
        if (Ans == "y" || Ans == "yes" || Ans == "Yes")
        {
            Dvijok();
        }
        else 
        {
            break;
        }
        cout << "AGAIN? y/n" << endl;
        cin >> Ans;
        if (Ans == "y" || Ans == "yes" || Ans == "Yes") 
        {
            clearScr();
            Dvijok();
        }
        else 
        {
            return false;
        }
        
    } while (true);
    deinitGame(g);
    return 0;
}