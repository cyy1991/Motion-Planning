
#include <limits>
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

  ans = "Win";
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
    ans = "Win";
    for(int i = 0; i < N; ++i){
      if (board[i][i] != player.id){
        ans = "Valid";
        break;
      }
    }
  }
  // cout << ans << endl;
  return ans;

}


void TicTacToe::showBoard() {
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cout << board[i][j] << " ";
    }
    cout <<endl;
  }
}


int main(int argc, char** argv) {
  std::cout << "Starting test!" << std::endl;

 // Add some useful test cases.
  // result = game.MakeMove(Player, Location)
  // Check result is correct.
  int n_players; // number of players
  cout << "please choose the number of players:" << endl;
  while(!(cin >> n_players) || n_players > 9 || n_players < 2) {
    cout << "Not a number or out of bounds, please choose another N:" << endl;
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
  }

  int N;

  cout << "Please choose N first:" << endl;

  while(!(cin >> N) || N > 100 || N < 3) {
    cout << "Not a number or out of bounds, please choose another N:" << endl;
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
  }
  TicTacToe game(N);
  vector<Player> players;
  for(int i = 1; i < n_players + 1; ++i) {
    Player player;
    player.id = i;
    players.push_back(player);
  }


  Location loc;
  int numOfMoves=1; //initialize the numOfMoves

  string status;
  while(status != "Win" && numOfMoves < N*N) {
    game.showBoard();

    if(numOfMoves%n_players != 0){
      cout << "Player " << numOfMoves%n_players << " is playing" << endl;
      cout << "Please input the location: row and col, e.g 3 4" << endl;
      // make sure row and col are numbers.
      while(!(cin >> loc.row) || !(cin >> loc.col)) {
        cout << "Not numbers, please input the location: row and col, e.g 3 4" << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
      }
      cout << "You selected " << loc.row << " " << loc.col << endl;
      status = game.MakeMove(players[numOfMoves%n_players - 1], loc);

    }
    else{
      cout << "Player "<< n_players <<" is playing" << endl;
      cout << "Please input the location: row and col, e.g 3 4" << endl;
      // make sure row and col are numbers.

      while(!(cin >> loc.row) || !(cin >> loc.col)) {
        cout << "Not numbers, please input the location: row and col, e.g 3 4" << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
      }
      cout << "You selected " << loc.row << " " << loc.col << endl;
      status = game.MakeMove(players[n_players - 1], loc);

    }

    cout << "Status is " << status << ", press Enter to continue."<< endl;

    cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get();


    if(status != "InValid"){
        numOfMoves += 1;

    }
    // system("read");
    system("clear");
  }
  if(status == "Win") {
    cout << "Congratulations!" << endl;
  }

 return 0;
}
