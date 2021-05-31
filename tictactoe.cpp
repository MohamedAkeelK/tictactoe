// create gloal board array to represent board 3 by 3 and store values 1 - 9 to represent slot
// create global char current_marker and int current_player
// in game function ask user to choose X or O and store in char var.
// set current player to 1 and current marker to the marker var that user chose.
// call the draw board function which outputs the values of the board array .
 //  create for loop in game function that loops 9 times because there can only be max 9 turns
 //     outout current_player
 //     ask user to pick a slot and store in a int variable called slot.
 //           check to see if slot is a valid number, if it is not then say it is invalid num and decrease
 //           i by 1 and continue the loop.
 //      check if the slot is already occupied by a x or o, if so then print slot is occupied
 //      then decrease i by 1 and continue the loop
 //      call drawoard function
 //      set player_won var to the return value of winner function which is either 1 or 2 for the the player_won
 //      output the winning player
 //      call the swap_player_and_marker function type void which swaps the current marker and current player
  // check if player_won is 0 and output its a tie.

#include <iostream>
using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char current_marker;
int current_player;

void ClearScreen() {
  int n;
  for (n = 0; n < 10; n++)
    printf( "\n\n\n\n\n\n\n" );
};

void drawBoard() {
ClearScreen();
cout << endl;
  for(int i = 0; i < 3; i++){
    cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
    if(i != 2)
      cout << "---------" << endl;
  }
  cout << endl << endl;
};

bool placeMarker(int slot) {
    int row = slot / 3;
    int col;
    if(slot % 3 == 0) {
      row = row - 1;
      col = 2;
    }
    else {
      col = slot % 3 - 1;
    }

    if(board[row][col] != 'X' && board[row][col] != 'O') {
      board[row][col] = current_marker;
      return true;
    }
    else {
      return false;
    }
};

int winner(){
  for(int i = 0; i < 3; i++){
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
      if((board[i][0] != ' ') && (board[i][1] != ' ') && (board[i][2] != ' '))
        return current_player;
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
      if((board[0][i] != ' ') && (board[1][i] != ' ') && (board[2][i] != ' '))
        return current_player;
  }

  if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    if((board[0][0] != ' ') && (board[1][1] != ' ') && (board[2][2] != ' '))
      return current_player;
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    if((board[0][2] != ' ') && (board[1][1] != ' ') && (board[2][0] != ' '))
      return current_player;

  return 0;
};

void swap_player_and_marker() {
    if(current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if(current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
};

void game() {

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Player 1 Enter 'X' or 'O' to choose your marker: ";
    char p1_marker;
    cin  >> p1_marker;

    current_player = 1;
    current_marker = p1_marker;
    drawBoard();
    int winning_player;

    for(int i = 0; i < 9; i++) {
      cout << " ++++++ SLOT NUMBERS ++++++ " << endl << endl;
      cout << "1" << " | " << "2" << " | " << "3"<< endl;
      cout << " --------- " << endl;
      cout << "4" << " | " << "5" << " | " << "6"<< endl;
      cout << " --------- " << endl;
      cout << "7" << " | " << "8" << " | " << "9"<< endl << endl;

      cout << "Player " << current_player << "'s turn: PICK A SLOT: ";
      int slot;
      cin >> slot;

      if(slot < 1 || slot > 9) {
        cout << "invalid slot, please try again" << endl;
        i--;
        continue;
      }

      if(!placeMarker(slot)) {
        cout << "That slot is occupied, please choose another slot" << endl;
        i--;
        continue;
      }

      drawBoard();
      winning_player = winner();

      if(winning_player == 1) {
          cout << "=========================================" << endl;
          cout << "PLAYER 1 IS THE WINNER. Congratulations!" << endl;
          cout << "=========================================" << endl; break;
      }

      if(winning_player == 2) {
        cout << "=========================================" << endl;
        cout << "PLAYER 1 IS THE WINNER. Congratulations!" << endl;
        cout << "=========================================" << endl; break;
      }

      swap_player_and_marker();
    }

    if(winning_player == 0) {
      cout << "Its a Tie!" << endl;
    }
};

int main(){
  game();
}
