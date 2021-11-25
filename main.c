#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


void HoorSort(int* arr, int first, int last)
{
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do{
        while(arr[i] < x)i++;
        while(arr[j] > x)j--;

        if(i <= j)
            {
                SwapArrayInt(arr,i,j);
                i++;
                j--;
            }
    }while(i <= j);

    if (i < last) HoorSort(arr,i,last);
    if (first < j) HoorSort(arr,first,j);
}

void ThickSplit(int* a, int l, int r)
{
    int x = a[r];
    if(r<=l) return;
    int i = l;
    int j = r-1;
    int p = l-1;
    int q =r;

    while(i <= j)
        {
            while(a[i] < x) i++;
            while(a[j] > x) j--;

            if(i >= j) break;
            SwapArrayInt(a,i,j);
            if (a[i] == x)
                {
                    p++;
                    SwapArrayInt(a,p,i);
                    i++;
                }
            if(a[j] == x)
                {
                    SwapArrayInt(a, q - 1, j - 1);
                }

        }
        SwapArrayInt(a,i,r);
        j = i-1;
        i++;

        for(int k = l; k<= p; ++k, --j)
            {
                SwapArrayInt(a,k,i);
            }
        for(int k = r-1; k >= q; ++k, ++i)
            {
                SwapArrayInt(a,k,i);
            }

        ThickSplit(a,l,j);
        ThickSplit(a,i,r);
}

void sortShells(int* a, int len)
{
    int i, j, step, temp;
    for(step = len/2; step > 0; step /= 2)
        {
            for(i = step; i < len; ++i)
                {
                    temp = a[i];
                    for(j = i; j >= step; j-= step)
                        {
                            if(temp < a[j - step])
                            {
                                a[j] = a[j-step];
                            }
                            else{break;}
                        }
                        a[j] = temp;
                }
        }

}

int MedianSeeker(int* a, int SIZE_x, int SIZE_y)
{
    int l = SIZE_x;
    int r = SIZE_y;
    int SIZE;

    for(int i = l;i<=r;i++){SIZE=i;};
    int median;

        median = SIZE / 2;

    return median;
}

void BestSort(int* a,int SIZE)
{
    if(SIZE >= 10)
    {
        int i = (SIZE / 3);

        //определ€ем медиану первого элемента

        int Medianfirst = MedianSeeker(a,0,i);

        //определ€ем медиану среднего элемента

        int MedianSecond = MedianSeeker(a,i,SIZE-i);

        //определ€ем медиану последнего элемента

        int Medianlast = MedianSeeker(a,SIZE-i,SIZE);

        //мен€ем найденый эелемент с центральным элементом массива

        int TrueMedian;

        if(a[Medianfirst] >= a[MedianSecond] && a[Medianfirst] <= a[Medianlast] || a[Medianfirst] <= a[MedianSecond] && a[Medianfirst] >= a[Medianlast])
            {
                TrueMedian = Medianfirst;
            }
        else if(a[MedianSecond] >= a[Medianfirst] && a[MedianSecond] <= a[Medianlast] || a[MedianSecond] <= a[Medianfirst] && a[MedianSecond] >= a[Medianlast])
            {
                TrueMedian = MedianSecond;
            }
        else if(a[Medianlast] >= a[Medianfirst] && a[Medianlast] <= a[MedianSecond] || a[Medianlast] <= a[Medianfirst] && a[Medianlast] >= a[MedianSecond])
            {
                TrueMedian = Medianlast;
            }
        SwapArrayInt(a,TrueMedian,SIZE/2);

        //вызываем сортировку ’оара

        HoorSort(a,0,SIZE-1);
    }
    else
    {
        sortShells(a,SIZE);
    }

}


//€ провел несколько дней за решение этих задач и не могу пон€ть как решать 2 задание в видео уроке все объ€снили очень плохо и не пон€тно а на форумах и в юутубе ничего нет

void BlockSort(int* a, int len)
{
    const int max = len;
    const int b = 10;

    int busket[b][max+1];
    for(int i = 0; i < b; ++i)
        {
            busket[i][max]=0;
        }

    for(int digit = 1; digit < 1000000000; digit *= 10)
        {
            for(int i = 0; i<max;++i)
                {
                    int d = ( a[i] / digit) % b;

                    int counter = busket[d][max];

                        busket[d][counter] = a[i];
                        counter++;
                        busket[d][max] = counter;

                    //busket[d][busket[d][max]++]= a[i];

                }

                int idx = 0;
                for(int i = 0; i < b; ++i)
                    {
                        for(int j = 0; j < busket[i][max]; ++j )
                            {
                                    a[idx++]=busket[i][j];

                            }
                        busket[i][max] = 0;
                    }
        }
}


int main()
{
    const int SIZE_X = 10;
    int *a = ArrayFiller(SIZE_X);

    ArrayPrinterFirst(a, SIZE_X);

    BestSort(a,SIZE_X);

    ArrayPrinterFirst(a, SIZE_X);

    int *b = ArrayFiller(SIZE_X);

    ArrayPrinterFirst(b, SIZE_X);

BlockSort(b,SIZE_X);

    ArrayPrinterFirst(b, SIZE_X);

    return 0;
}
