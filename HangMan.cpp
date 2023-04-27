#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cctype>
using namespace std;

const int OPPORTUNITIES = 6;
string words[8] = { "house", "mirror", "floor", "tiger", "inter", "mapache","cantador","programing"};
string selectedWord;
bool guessedLetters[6];
int guessCount = 0;
string gallows[7];
void title() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 2);

    cout << R"(
    ___     ___          ___        _____        __     ________
   |   |   |   |        / _ \       | |\ \      | |   / _______|
   |   |___|   |       / / \ \      | | \ \     | |  / /
   |           |      / /___\ \     | |  \ \    | | | |
   |    ___    |     / ______\ \    | |   \ \   | | | |    ______     
   |   |   |   |    / /       \ \   | |    \ \  | | | |    |___ |
   |   |   |   |   / /         \ \  | |     \ \ | |  \ \______| |    
   |___|   |___|  /_/           \_\ |_|      \_\|_|   \_________|
)";

    cout << R"( 
    ___        ___          ___        _____        __
   |   \      /   |        / _ \       | |\ \      | |
   |    \    /    |       / / \ \      | | \ \     | |
   |  |\ \  / /|  |      / /___\ \     | |  \ \    | |
   |  | \ \/ / |  |     / ______\ \    | |   \ \   | |
   |  |  \__/  |  |    / /       \ \   | |    \ \  | |
   |  |        |  |   / /         \ \  | |     \ \ | |
   |__|        |__|  /_/           \_\ |_|      \_\|_|
)";
    Sleep(4000);
    system("cls");
}
void Init() {
    srand(time(NULL)); // Seed random number generator
    int rIndex = rand() % 5; // Get random index
    selectedWord = words[rIndex]; // Select word
    for (int i = 0; i < 6; i++) {
        guessedLetters[i] = false;
    }

    gallows[0] = R"( 
        _____ 
        | |   
        |     
        |     
        |     
        |______ 
)";

    gallows[1] = R"( 
        _____ 
        | |   
        | O   
        |     
        |     
        |______ 
)";
 
    gallows[2] = R"( 
        _____ 
        | |   
        | O   
        | |    
        |     
        |______ 
)";

    gallows[3] = R"( 
        _____ 
        | |   
        | O   
        | |\    
        |     
        |______ 
)";
  
    gallows[4] = R"( 
        ______ 
        |  |   
        |  O   
        | /|\    
        |     
        |______ 
)";

    gallows[5] = R"( 
        ______ 
        |  |   
        |  O   
        | /|\    
        | /   
        |______ 
)";
 
    gallows[6] = R"( 
        ______ 
        |  |   
        |  O   
        | /|\    
        | / \  
        |______ 
)";


}
void ShowGameStartScreen() {
    cout << "Welcome to Hangman" << endl;
}

void ShowBoard() {
    system("cls");
    cout << gallows[guessCount] << endl;

    for (int i = 0; i < selectedWord.length(); i++) {
        if (guessedLetters[i] == true) {
            cout << selectedWord[i] << " ";

        }
        else {
            cout << "_ ";
        }
    }

    cout << endl;

}

void ShowInputOptions() {
    cout << "You have " << OPPORTUNITIES - guessCount << " tries left." << endl;
    cout << "Enter any letter" << endl;
}

string GetInput() {
    string input;
    cin >> input;
    return input;
}

bool IsValidInput(string input) {
    if (input.length() == 1 && input != " " && isalpha(input[0])) {//isalpha means is it a letter
        return true;
    }
    else {
        cout << "Invalid input. Please enter a single letter." << endl;
        return false;
    }
}

void ProcessInput(string input)
{
    int counter = 0;

    for (int i = 0; i < selectedWord.length(); i++)
    {
        if (input[0] == selectedWord[i])
        {
            guessedLetters[i] = true;
            counter++;
        }

    }
    if (counter == 0)
    {
        guessCount++;

    }
}


bool CheckWin()
{

    for (int i = 0; i < selectedWord.length(); i++)
    {
        if (guessedLetters[i] == false)
        {
            return false;
        }
    }
    return true;
}

bool CheckLoss()
{
    if (guessCount >= OPPORTUNITIES)//if guessCount is greater or equal then OPERTUNITIES that means the player lost
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsGameOver()
{
    return (CheckWin() || CheckLoss());
}
void ShowGameOverScreen()
{
    ShowBoard();
    cout << endl;
    cout << "Game Over!";
    if (CheckWin())
    {
        cout << "You Won!" << endl;
        cout << "You have" << guessCount << "incorrect guesses" << endl;
    }
    else
    {
        cout << "You Lost! The word was: " << selectedWord;
    }
}

void Start() {
    string input;
    Init();
    ShowGameStartScreen();
    do {
        ShowBoard();
        do {
            ShowInputOptions();
            input = GetInput();
        } while (!IsValidInput(input));
        ProcessInput(input);
    } while (!IsGameOver());
    ShowGameOverScreen();
}
int main()
{
    title();
    Start();

    return 0;
}


