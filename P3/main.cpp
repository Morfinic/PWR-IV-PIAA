#include <iostream>
#include "./include/TicTacToe.h"
using namespace std;

int main(){
    // tic-tac-toe, minimum board size 3x3. minimum win size 2
    int size, num2win, ai_depth;
    char start_game{'n'};

    while(start_game == 'n'){
        system("cls");
        cout<<"Minimum board size 3x3. Minimum win size 2\n"
              "Input board size: ";
        do {
            cin>>size;
        }while(size < 3);
        cout<<"Input win size: ";
        do {
            cin>>num2win;
        }while(num2win < 2 && num2win > size);

        cout<<"Set AI recursion depth: ";
        cin>>ai_depth;

        cout<<"Rules: \n"
              "\t* AI always plays second\n"
              "\t* Player symbol: o, AI symbol: x";

        cout<<"\nGame parameters: \n"
              "\t* TicTacToe dim: "<<size<<"x"<<size<<"\n"
              "\t* chars to win: "<<num2win<<"\n"
              "\t* Ai recursion depth: "<<ai_depth<<"\n"
              "\nStart game (y/n) ";

        cin>>start_game;
    }

    TicTacToe _board(size, num2win, ai_depth);

    while(_board.gameState() == 0 && !_board.isFull()){
        _board.print();
        if(_board.isPlayerTurn()){
            int x, y;
            while(true){
                cout<<"Your turn (x, y) ...\n";
                cin>>x>>y;

                if(x >= 1 && x <= _board.getSize() && y >= 1 && y <= _board.getSize() && !_board.isOccupied(x, y))
                    break;

                if(x < 1 || x > _board.getSize() || y < 1 || y > _board.getSize()){
                    _board.print();
                    cout<<"Wrong coords.\n";
                    continue;
                }

                if(_board.isOccupied(x, y)){
                    _board.print();
                    cout<<"Field ("<<x<<","<<y<<") taken by ";
                    if(_board.coordCheck(x, y) == _board.getPlayerSymbol())
                        cout<<"player.\n";
                    else
                        cout<<"ai.\n";
                    continue;
                }
            }
            _board.set(x, y);
            _board.switchTo("ai");
        } else {
            _board.makeBestMove();
            _board.switchTo("player");
        }
    }

    _board.print();
    if(_board.gameState() == 10)
        cout<<"Player wins.";
    else if(_board.gameState() == -10)
        cout<<"AI wins.";
    else
        cout<<"Draw.";

    return 0;
}