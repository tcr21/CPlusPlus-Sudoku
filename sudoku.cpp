#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename); 
  if (!in) {
    cout << "Failed!\n";
  }
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3)) {
    cout << "  +===========+===========+===========+\n";
  } else {
    cout << "  +---+---+---+---+---+---+---+---+---+\n";
  }
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|\n";
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) {
    cout << (char) ('1'+r) << "   ";
  }
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */

// For each question, please note functions/ helper functions are numbered below from 1 onwards eg Q2.1 first function definition, Q2.2 second function definition etc

// QUESTION 1

// Q1. Definition of is_complete function: takes a 9x9 array of characters and returns true if all board positions are occupied by digits, and false otherwise
bool is_complete(const char board[9][9])
{
  for (int r = 0; r < 9; r++)
    for (int c = 0; c < 9; c++)
      if (!isdigit(board[r][c]) || (board[r][c] < 49) || (board[r][c] > 57))
        return false; 
  return true; 
}

// QUESTION 2

// Q2.1 Definition of make_move function: attempts to place digit onto board at given position. Returns false if position is invalid. Returns true if it is valid and updates board accordingly
bool make_move(const char position[3], const char digit, char board[9][9])
{  
  // Declare variables for target row and column indices ranging from 0-8
  int row, col; 

  // Check position and digit range are valid
  if (!check_position_range(position) || !check_digit_range(digit))
    {
      cout << "OUT OF RANGE. Please check row is a capital letter ranging from A-I, column is an integer ranging from 1-9, and digit is an integer ranging from 1-9. \n";
      return false; 
    }

  // Convert position row and column characters into indices ranging from 0-8
  convert_position_characters_into_indices(position, row, col);
  if (row == -1)
  {
    return false; 
  }
  
  // Check position is empty
  if (!check_position_is_empty(row, col, board))
  {
    cout << "SPACE IS NOT EMPTY. \n";
    return false; 
  }

  // Check digit is absent from position row, column and box. If it is, say the move is valid and update the board
  if (absent_from_row(row, digit, board) && absent_from_column(col, digit, board) && absent_from_box(row, col, digit, board))
  {
    update_board (row, col, digit, board); 
    return true; 
  }
  return false; 

}

// Q2.2 Definition of check_position_range function: checks that the position at which we wish to insert a digit ranges from A-I for row and 1-9 for column
bool check_position_range(const char position[3])
{
  // Check row range
  if (!isalpha(position[0]) || position[0] < 65 || position[0] > 73)
    return false; 
  // Check column range
  if (!isdigit(position[1]) || position[1] < 49 || position[1] > 57)
    return false; 
  return true; 
}

// Q2.3 Definition of check_digit_range function: checks that the digit we wish to insert ranges from 1-9
bool check_digit_range(const char digit)
{
  if (!isdigit(digit) || digit < 49 || digit > 57)
    return false; 
  return true; 
}

// Q2.4 Definition of convert_position_characters_into_indices function: converts the position's row and column characters into indices ranging from 0-8
void convert_position_characters_into_indices(const char position[3], int &row, int &col)
{
  // Convert row character into row index
  switch (position[0])
  {
    case 'A': 
      row = 0;
      break; 
    case 'B':
      row = 1;
      break;
    case 'C':
      row = 2;
      break;
    case 'D':
      row = 3;
      break;
    case 'E':
      row = 4;
      break; 
    case 'F':
      row = 5; 
      break; 
    case 'G':
      row = 6;
      break; 
    case 'H':
      row = 7;
      break;
    case 'I':
      row = 8;
      break; 
    default: 
      cout << "ROW LETTER NOT CONVERTED INTO INDEX. \n"; // Test
      row = -1; 
  }
  // Convert column character into column index
  col = position[1] - 48 - 1;
}

// Q2.5 Definition of check_position_is_empty function: checks that position at which we wish to insert a digit is empty
bool check_position_is_empty(const int row, const int col, const char board[9][9])
{
  if (board[row][col] == '.')
    return true;
  return false;  
}

// Q2.6 Definition of absent_from_row function: checks that the digit is not already present in the position row
bool absent_from_row(const int row, const char digit, const char board[9][9])
{
  for (int i = 0; i < 9; i++)
    if (board[row][i] == digit)
      return false; 
  return true; 
}

// Q2.7 Definition of absent_from_column function: checks that the digit is not already present in the position column
bool absent_from_column(const int col, const char digit, const char board[9][9])
{
  for (int i = 0; i < 9; i++)
    if (board[i][col] == digit)
      return false; 
  return true; 
}

// Q2.8 Definition of absent_from_box function: checks that the digit is not already present in the position box
bool absent_from_box(const int row, const int col, const char digit, const char board[9][9])
{
  // Determine first position of box
  int box_first_row = row - (row % 3); 
  int box_first_col = col - (col % 3); 

  // Check each position in box
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
       if (board[box_first_row + r][box_first_col + c] == digit)
        return false; 
    }
     
  }
  return true;
}

// Q2.9 Definition of update_board function: updates the board
void update_board (const int row, const int col, const char digit, char board[9][9])
{
  board[row][col] = digit; 
}

// QUESTION 3 

// Q3. Definition of save_board function: outputs two-dimensional character array board to file with name filename. Returns true if file was successfully written, false otherwise
bool save_board(const char* filename, const char board[9][9])
{
  // Declare output stream and open file
  ofstream out_stream;
  out_stream.open(filename);
  if (!out_stream)
  {
    cout << "OUTPUT FILE FAILED. \n"; 
    return false; 
  }

  // Copy each character in the board to the file
  int r = 0, c = 0; 
  for (r = 0; r < 9; r++)
  {
    for (c = 0; c < 9; c++)
    {
      out_stream.put(board[r][c]);
    }
    out_stream << endl;  
  } 

  // Close output stream
  out_stream.close(); 

  // Check all 9 rows and columns have been copied
  if (r == 9 && c == 9)
  {
    return true; 
  }
  return false;
}

// QUESTION 4

// Q4.1 Definition of solve_board function: takes in a sudoku board and solves it recursively
bool solve_board(char board[9][9])
{
  /* Test used for Question 5.2
  static int count;
  count++; 
  */
  
  // Declare variables
  char position[3];
  int row_of_move_to_undo, col_of_move_to_undo; 

  // Identify an empty spot and update position to be filled accordingly. When no more empty positions are found, it means the board is complete
  if (!find_empty_position(position, board))
  {
    /* Test used for Question 5.2
    cout << count;
    */
    return true; 
  }

  // Recursively solve sudoku
  for (char digit = '1'; digit <= '9'; digit++)
  {
    if (make_move (position, digit, board))
    {
      if (solve_board(board))
      {
        return true; 
      }
      convert_position_characters_into_indices(position, row_of_move_to_undo, col_of_move_to_undo); 
      board[row_of_move_to_undo][col_of_move_to_undo] = '.'; 
    }
  }
return false; 
}

// Q4.2 Definition of find_empty_position function: identifies empty spot and updates position accordingly
bool find_empty_position(char position[3], char board[9][9])
{
  int row_to_update, col_to_update;  

  for (row_to_update = 0; row_to_update < 9; row_to_update++)
    for (col_to_update = 0; col_to_update < 9; col_to_update++)
      if (board[row_to_update][col_to_update] == '.')
      {
        convert_position_indices_into_characters (row_to_update, col_to_update, position);
        if (position[0] == 'X')
        {
          return false; 
        }
        return true; 
      }
  return false; 
}

// Q4.3 Definition of convert_position_indices_into_characters function: converts row and column indices into characters
void convert_position_indices_into_characters (const int row_to_update, const int col_to_update, char position[3])
{
  // Convert row index into character
  switch (row_to_update)
  {
    case 0:
      position[0] = 'A'; 
      break; 
    case 1:
      position[0] = 'B'; 
      break; 
    case 2:
      position[0] = 'C'; 
      break; 
    case 3:
      position[0] = 'D'; 
      break; 
    case 4:
      position[0] = 'E'; 
      break; 
    case 5:
      position[0] = 'F'; 
      break; 
    case 6:
      position[0] = 'G'; 
      break; 
    case 7:
      position[0] = 'H'; 
      break; 
    case 8:
      position[0] = 'I'; 
      break; 
    default:
      cout << "ROW INDEX NOT CONVERTED INTO CHARACTER. \n"; // Test
      position[0] = 'X';
  }
  // Convert column index into character
  position[1] = col_to_update + 48 + 1; 
}


