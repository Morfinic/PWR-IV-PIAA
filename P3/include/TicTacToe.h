#ifndef PWR_IV_PIAA_TICTACTOE_H
#define PWR_IV_PIAA_TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe {
public:
    TicTacToe(int size, int num2win);
    void print() const;
    bool isPlayerTurn() const { return player_turn; };
    void set(int x, int y);
    void reset();
    bool switchTo(std::string who);
    char coordCheck(int x, int y) const;
    bool isOccupied(int x, int y) const;
    bool isFull() const;
    int gameState() const;
    char getPlayerSymbol() const { return player_symbol; };
    char getAiSymbol() const { return ai_symbol; };
    int getSize() const { return size; };
private:
    int size;
    int num2win;
    char player_symbol, ai_symbol;
    bool player_turn;
    std::vector<std::vector<char>> coords;
};

#endif //PWR_IV_PIAA_TICTACTOE_H
