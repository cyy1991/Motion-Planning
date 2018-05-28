

#include <iostream>
#include <vector>
using namespace std;


class Player {
  public:
    int id;

};


class Location {
  public:
    int row;
    int col;
};

// Square NxN board, win with N consecutive.
class TicTacToe {
  public:
    TicTacToe(int Nsize);
  ///
  /// \brief MakeMove Interface for the game playing system to add a new move to
  /// the game.
  /// \param player   Player making this move.
  /// \param location The selected location on the board.
  /// \return Result of the move, including the new game status such as Win, Invalid, etc.
  ///
  //Result MakeMove(Player player, Location location);
    string MakeMove(Player player, Location location);
    // int board[5][5];
    void showBoard();

  private:
  /// Create a representation of the game state and any internal structures to help
  /// determine win conditions. The implementation should easily extend to different
  /// board sizes and run time should scale linearly (or better) with N.
    int N;
    vector< vector<int> > board; //(N, vector<int>(N, 0));

    string checkWin(Player player, Location location);
};

TicTacToe::TicTacToe(int Nsize){
  N = Nsize;
  board.resize(N, vector<int>(N, 0));
}

string TicTacToe::MakeMove(Player player, Location location){
  // check if the location is occupied.
  bool withinBound = location.row < N && location.row >= 0 && location.col < N && location.col >= 0;

  if (withinBound && board[location.row][location.col] == 0) {
    board[location.row][location.col] = player.id;
    return checkWin(player, location);
  }
  else {
    return "InValid";
  }

}

string TicTacToe::checkWin(Player player, Location location){
  string ans = "Win";
  // check row
  for(int i = 0; i < N; ++i) {
    if (board[location.row][i] != player.id){
      ans = "Valid";
      break;
    }
  }
  if(ans == "Win"){
    return ans;
  }

  // check column
  for (int i = 0; i < N; ++i) {
    if (board[i][location.col] != player.id){
      ans = "Valid";
      break;
    }
  }

  if(ans == "Win"){
    return ans;
  }

  // check diagonal
  if(location.row == location.col){
    for(int i = 0; i < N; ++i){
      if (board[i][i] != player.id){
      ans = "Valid";
      break;
      }
    }
  }
  cout << ans;
  return ans;

}


void TicTacToe::showBoard(){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      cout << board[i][j] << " ";

    }cout <<endl;
  }
}


int main(int argc, char** argv) {
  std::cout << "Starting test!" << std::endl;

 // Add some useful test cases.
  // result = game.MakeMove(Player, Location)
  // Check result is correct.
  int N = 5;
  TicTacToe game(N);
  Player p1;
  Player p2;
  p1.id = 1;
  p2.id = 2;

  Location loc;
  int numOfMoves=1; //initialize the numOfMoves

  string status;
  while(status != "Win" && numOfMoves < N*N) {
    if(numOfMoves%2 != 0){
      cout << "Player 1 is playing" << endl;

      cout << "Please input the location: row and col, e.g 3 4" << endl;
      cin >> loc.row;
      cin >> loc.col;

      status = game.MakeMove(p1, loc);

    }
    else{
      cout << "Player 2 is playing" << endl;
      cout << "Please input the location: row and col, e.g 3 4" << endl;

      cin >> loc.row;
      cin >> loc.col;
      status = game.MakeMove(p2, loc);

    }

    cout << "Status is " << status << endl << endl;

    game.showBoard();
    if(status != "InValid"){
        numOfMoves += 1;

    }


  }



 return 0;
}
