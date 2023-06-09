#include <vector>
#include <string>
#include <algorithm>

class TicTacToe {
public:
    TicTacToe(int size, int num2win, int ai_depth);
    void print() const;
    bool isPlayerTurn() const { return player_turn; };
    void set(int x, int y);
    void reset();
    void switchTo(std::string who);
    char coordCheck(int x, int y) const;
    bool isOccupied(int x, int y) const;
    bool isFull() const;
    int gameState() const;
    char getPlayerSymbol() const { return player_symbol; };
    char getAiSymbol() const { return ai_symbol; };
    int getSize() const { return size; };
    int minimax(int depth, bool player_turn);
    void makeBestMove();
private:
    int size;
    int num2win;
    int ai_depth;
    char player_symbol, ai_symbol;
    bool player_turn;
    std::vector<std::vector<char>> coords;
};
