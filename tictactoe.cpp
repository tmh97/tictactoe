#include <iostream>

using namespace std;

void build_board(struct setup *game);
void print_board(struct setup *game);
void take_turn(struct setup *game);
int board_full(struct setup *game);
int check_winner(struct setup *game);
struct setup {
  char board[3][3];
};

int turn = 1;
int fail = 0;
int winner = 0;

int main() {
  
  setup game;
  setup *ptr; 
  ptr = &game;
  build_board(ptr);
  print_board(ptr);

  while(1) { //play starts here
    
    take_turn(ptr); 

    if (winner == 1) 
      break;   

    if (board_full(ptr) == 1) 
      break;
  }
}

int check_winner(struct setup *game) { 
  int over = 0;
  if ((game->board[0][0] == game->board[0][1]) && (game->board [0][0]  == game->board[0][2]) && (game->board[0][0]!= ' ')) // ---
    over = 1;
  if ((game->board[1][0] == game->board[1][1]) && (game->board[1][0] == game->board[1][2]) && (game->board[1][0]!= ' ')) // ---
    over = 1;
  if ((game->board[2][0] == game->board[2][1]) && (game->board[2][0] == game->board[2][2]) && (game->board[2][0]!= ' ')) // ---
    over = 1;
  if ((game->board[0][0] == game->board[1][0]) && (game->board[0][0] == game->board[2][0]) && (game->board[0][0]!= ' ')) // |
    over = 1;
  if ((game->board[0][1] == game->board[1][1]) && (game->board[0][1] == game->board[2][1]) && (game->board[0][1]!= ' ')) // |
    over = 1;
  if ((game->board[0][2] == game->board[1][2]) && (game->board[0][2] == game->board[2][2]) && (game->board[0][2]!= ' ')) // |
    over = 1;
  if ((game->board[0][0] == game->board[1][1]) && (game->board[0][0] == game->board[2][2]) && (game->board[0][0]!= ' ')) // "\"
    over = 1; 
  if ((game->board[0][2] == game->board[1][1]) && (game->board[0][2] == game->board[2][0]) && (game->board[0][2]!= ' ')) // "/"
    over = 1;

  if (over == 1) {
    winner = 1;
    if (turn == 1) 
      cout << "Player 1 Wins!\n";
    if (turn == 2)
      cout << "Player 2 Wins!\n";
  }
  return winner; 
}



int board_full(struct setup *game){
  int full = 1;
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (game->board[i][j] == ' ')
        full = 0;
    }
  }
  if (full == 1)
    cout << "The board is full, there is no winner, Play Again!\n"; 
 
  return full;
}
void take_turn(struct setup *game){ //oof this function

    int choice[2];
    fail = 0;
    if(turn == 1){
      cout << "Player 1's Turn \n";
      cout << "Where would you like to place your piece?: \n";
      cout << "Row: ";
      cin >> choice[0];
      cout << "Column: "; 
      cin >> choice[1];
      cout << "\n";
      if(game->board[choice[0]][choice[1]] != ' ') {
        cout << "This spot is already taken: Player 1 Go Again \n";
        fail = 1;
      } 
      if (fail == 0) {
        game->board[choice[0]][choice[1]] = 'X';
        check_winner(game);
        turn++;
      }
    }
    else {
      cout << "Player 2's Turn \n";
      cout << "Where would you like to place your piece?: \n";
      cout << "Row: ";
      cin >> choice[0];
      cout << "Column: ";
      cin >> choice[1];
      cout << "\n";
      if(game->board[choice[0]][choice[1]] != ' ') {
        cout << "This spot is already taken: Player 2 Go Again \n";
        fail = 1;
      } 
      if (fail == 0) {
        game->board[choice[0]][choice[1]] = 'O';
        check_winner(game);
        turn--;
      }
    }
    print_board(game);     
}

void build_board(struct setup *game) { // fill the board for test
  int i, j;
  for (i = 0; i < 3; i++) { 
    for (j = 0; j < 3; j++) {
      game->board[i][j] = ' ';
    }
  }
} // end build_board

void print_board(struct setup *game) { // print the board
  int i, j;
  cout << "  0  1  2\n";
  for (i = 0; i < 3; i++) {
    cout << i;
    for (j = 0; j < 3; j++) { 
      cout << "[" << game->board[i][j] << "]";
    }
    cout << "\n";
  }
  cout << "\n";
} // end print_board

// to do
// error checking
// gui
