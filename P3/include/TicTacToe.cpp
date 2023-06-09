#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe(int size, int num2win): size(size), num2win(num2win), coords(size, std::vector<char>(size)){
    for(int x = 0; x < size; x++)
        for(int y = 0; y < size; y++)
            coords[x][y] = 0;

    player_symbol = 'o';
    ai_symbol = 'x';

    player_turn = true;
}

void TicTacToe::print() const{
    system("cls");
    std::cout<<" ";
    for(int i = 0; i < size; i++)
        std::cout<<std::string(3, ' ')<<i+1;
    std::cout<<"\n  ."<<std::string(size*4-1, '-') + ".\n";
    for(int y = 0; y < size; y++){
        std::cout<<y+1;

        for(int x = 0; x < size; x++){
            std::cout<<" | ";
            if(coords[x][y] == 0)
                std::cout<<" ";
            else
                std::cout<<coords[x][y];
        }

        std::cout<<" |\n";
        if(y != size-1)
            std::cout<<"  |";

        for(int i = 0; i < size; i++){
            if(y == size - 1){
                std::cout<<"  \'" + std::string(size*4-1, '-') + "\'\n";
                break;
            }
            else if(i == size - 1){
                std::cout<<std::string(3, '-');
                break;
            }
            std::cout<<std::string(3, '-') + '+';
        }

        if(y != size-1)
            std::cout<<"|\n";
    }
}

void TicTacToe::set(int x, int y){
    if(x >= 1 && x <= size && y >= 1 && y <= size){
        if(isPlayerTurn())
            coords[x-1][y-1] = player_symbol;
        else
            coords[x-1][y-1] = ai_symbol;
    }
}

void TicTacToe::reset(){
    for(int x = 0; x < size; x++)
        for(int y = 0; y < size; y++)
            coords[x][y] = ' ';
}

bool TicTacToe::switchTo(const std::string who) {
    if(who == "player")
        player_turn = true;
    else if(who == "ai")
        player_turn = false;
}

char TicTacToe::coordCheck(int x, int y) const {
    if(x >= 1 && x <= size && y >= 1 && y <= size)
        return coords[x-1][y-1];
    else
        return 0;
}

bool TicTacToe::isOccupied(int x, int y) const {
    return coordCheck(x, y);
}

bool TicTacToe::isFull() const {
    for(int x = 1; x < size+1; x++)
        for(int y = 1; y < size+1; y++)
            if(!isOccupied(x, y))
                return false;
    return true;
}

int TicTacToe::gameState() const {
    // 1 - player
    // 0 - draw
    // -1 - ai

    // vertical win check
    for(int y = 1; y <= size; y++){
        int player_win{0}, ai_win{0};
        for(int x = 1; x <= size; x++){
            if(coordCheck(x, y) == player_symbol){
                player_win++;
                ai_win = 0;
            }
            else if(coordCheck(x, y) == ai_symbol){
                ai_win++;
                player_win = 0;
            }

            if(coordCheck(x, y) == 0){
                player_win = 0;
                ai_win = 0;
            }

            if(player_win >= num2win)
                return 1;
            else if(ai_win >= num2win)
                return -1;
        }
    }

    // Horizontal win check
    for(int x = 1; x <= size; x++){
        int player_win{0}, ai_win{0};
        for(int y = 1; y <= size; y++){
            if(coordCheck(x, y) == player_symbol){
                player_win++;
                ai_win = 0;
            }
            else if(coordCheck(x, y) == ai_symbol){
                ai_win++;
                player_win = 0;
            }

            if(coordCheck(x, y) == 0){
                player_win = 0;
                ai_win = 0;
            }

            if(player_win >= num2win)
                return 1;
            else if(ai_win >= num2win)
                return -1;
        }
    }

    // Forgive me god, diagonal check
    for(int x = 1; x <= size - num2win + 1; x++)
        for(int y = size - num2win + 1; y >= 1; y--) {
            int player_win{0}, ai_win{0};
            for(int i = 0; i < size + 1 - y; i++){
                if(coordCheck(x+i, y+i) == player_symbol){
                    player_win++;
                    ai_win = 0;
                }
                else if(coordCheck(x+i, y+i) == ai_symbol){
                    ai_win++;
                    player_win = 0;
                }

                if(coordCheck(x+i, y+i) == 0){
                    player_win = 0;
                    ai_win = 0;
                }

                if(player_win >= num2win)
                    return 1;
                else if(ai_win >= num2win)
                    return -1;
            }
        }

    for(int x = size; x >= size + 1 - num2win; x--)
        for(int y = 1; y <= size + 1 - num2win; y++){
            int player_win{0}, ai_win{0};
            for(int i = 0; i < size + 1 - y; i++){
                if(coordCheck(x-i, y+i) == player_symbol){
                    player_win++;
                    ai_win = 0;
                }
                else if(coordCheck(x-i, y+i) == ai_symbol){
                    ai_win++;
                    player_win = 0;
                }

                if(coordCheck(x-i, y+i) == 0){
                    player_win = 0;
                    ai_win = 0;
                }

                if(player_win >= num2win)
                    return 1;
                else if(ai_win >= num2win)
                    return -1;
            }
        }

    return 0;
}
