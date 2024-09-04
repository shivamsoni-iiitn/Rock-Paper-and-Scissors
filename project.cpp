#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class Choice
{
    STONE,
    PAPER,
    PENCIL,
    SCISSORS
};

class RockPaperScissors
{
private:
    Choice playerChoice;
    Choice computerChoice;

    Choice generateComputerChoice()
    {
        int random = rand() % 4;
        return static_cast<Choice>(random);
    }

    void printResult()
    {
        if (playerChoice == computerChoice)
            cout << "It's a tie!" << endl;
        else if ((playerChoice == Choice::STONE && computerChoice == Choice::SCISSORS) ||
                 (playerChoice == Choice::PAPER && computerChoice == Choice::STONE) ||
                 (playerChoice == Choice::PENCIL && computerChoice == Choice::PAPER) ||
                 (playerChoice == Choice::SCISSORS && computerChoice == Choice::PENCIL))
            cout << "You win!" << endl;
        else
            cout << "Computer wins!" << endl;
    }

    void printChoices()
    {
        cout << "Your choice: ";
        if (playerChoice == Choice::STONE)
            cout << "Stone.     ";
        else if (playerChoice == Choice::PAPER)
            cout << "Paper.     ";
        else if (playerChoice == Choice::PENCIL)
            cout << "Pencil.    ";
        else
            cout << "Scissors.  ";

        cout << "Computer's choice: ";
        if (computerChoice == Choice::STONE)
            cout << "Stone.     ";
        else if (computerChoice == Choice::PAPER)
            cout << "Paper.     ";
        else if (computerChoice == Choice::PENCIL)
            cout << "Pencil.    ";
        else
            cout << "Scissors.  ";
    }

public:
    void play()
    {
        cout << "Welcome to Stone, Paper, Pencil, Scissors Game!" << endl;
        while (true)
        {
            char playerInput;
            cout << "           S -->Stone" << endl;
            cout << "Enter      P --> Paper                     Q --> Quit" << endl;
            cout << "           N --> Pencil" << endl;
            cout << "           C --> Scissors" << endl;

            cin >> playerInput;
            playerInput = toupper(playerInput);

            if (playerInput == 'Q')
            {
                cout << "Thanks for playing!" << endl;
                break;
            }

            if (playerInput != 'S' && playerInput != 'P' && playerInput != 'N' && playerInput != 'C')
            {
                cout << "Invalid input. Enter S, P, N, C, or Q." << endl;
                continue;
            }

            if (playerInput == 'S')
                playerChoice = Choice::STONE;
            else if (playerInput == 'P')
                playerChoice = Choice::PAPER;
            else if (playerInput == 'N')
                playerChoice = Choice::PENCIL;
            else
                playerChoice = Choice::SCISSORS;

            computerChoice = generateComputerChoice();

            printChoices();
            cout << "Result: ";
            printResult();
        }
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    RockPaperScissors game;
    game.play();
    return 0;
}