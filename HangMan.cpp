
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

bool gameRunning = true;

#define color SetConsoleTextAttribute

void hangman1() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    color(hConsole, 7);
    cout << R"(

                      ___  
                      |  
                      |  
                      |   
                      |   
                      |__  
    
)";
}
void hangman2() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 2);
    cout << R"(
                      ___  
                      |  |  
                      |  
                      |  
                      |  
                      |__  
    
)";
}
void hangman3() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 6);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      |  
                      |   
                      |__  
    
)";
}
void hangman4() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 3);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      |  |  
                      |   
                      |__  
    
)";
}
void hangman5() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 1);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      | /|\  
                      |   
                      |__  
    
)";
}
void hangman6() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 4);
    cout << R"(
                      ___  
                      |  |  
                      |  O  
                      | /|\  
                      | / \  
                      |__  
    
)";

}
int main()
{

    hangman1();
    hangman2();
    hangman3();
    hangman4();
    hangman5();
    hangman6();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 7);
}


