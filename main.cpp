// This is a Periodic Table project,that displays Information About Elements and also has a Quiz
// Information Part By Kunal Borole
// Major Quiz Part By Hemil Ruparale

#include <iostream>
#include <random>
#include <stdlib.h>

#include"que.h"
using namespace std;


int main()
{
    int op;
    while(true)
    {
    start_menu();
    cin >> op;
    system("cls");
    switch(op)
    {
  case 1:
    Information();
    break;
  case 2:
    quiz();
    break;
  case 3:
    return 0;
  default:
    cout << "Invalid Option" << endl << endl;
    }

    }
    return 0;

}

