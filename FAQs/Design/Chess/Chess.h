#include <iostrea>

using namespace std;

class ChessPiece {
private:
    enum class Type{ROOK, BISHOP, KNIGHT, KING, PAWN, QUEEN};
    string type;
    string color;
    vector<int> position;
};

class Chess {
    public:
    private:
        ChessBoard cb; //Model of the board
        vector<Player> players; // Model of players
        vector<ChessPiece> pieces; // Model of pieces
        ChessBoardView cbv; // View of ChessBoard
};