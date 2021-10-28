#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============\n\n";

  cout << "Calling load_board():\n";
  load_board("easy.dat", board);

  cout << '\n';
	cout << "Displaying Sudoku board with display_board():\n";
  display_board(board);
  cout << "Done!\n\n";

  cout << "=================== Question 1 ===================\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";


  cout << "=================== Question 2 ===================\n\n";

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // write more tests

  // TEST MORE CASES FOR DIGIT
  cout << endl << "TESTING MORE CASES FOR DIGIT: \n \n"; 

  // Load board afresh
  load_board("easy.dat", board);  

  // Test 1: Case: 9 (valid move and max digit)
  cout << endl << "Test 1: Putting '9' into C5 is ";
  if (!make_move("C5", '9', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 2: Case: 0 (not valid input)
  cout << endl << "Test 2: Putting '0' into I8 is ";
  if (!make_move("I8", '0', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // TEST MORE CASES FOR POSITION
  cout << endl << "TESTING MORE CASES FOR POSITION: \n"; 
  
  // Test 3: Case: A1 (valid move and edge position)
  cout << endl << "Test 3: Putting '5' into A1 is ";
  if (!make_move("A1", '5', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 4: Case: A9 (valid move and edge position)
  cout << endl << "Test 4: Putting '9' into A9 is ";
  if (!make_move("A9", '9', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 5: Case: I1 (valid move and edge position)
  cout << endl << "Test 5: Putting '6' into I1 is ";
  if (!make_move("I1", '6', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 6: Case: I9 (valid move and edge position)
  cout << endl << "Test 6: Putting '8' into I9 is ";
  if (!make_move("I9", '8', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 7: Case: J1 (not valid row letter)
  cout << endl << "Test 7: Putting '1' into J1 is ";
  if (!make_move("J1", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 8: Case: I0 (not valid column number)
  cout << endl << "Test 8: Putting '1' into I0 is ";
  if (!make_move("I0", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 9: Case A4 (space is not empty)
  cout << endl << "Test 9: Putting '1' into A4 is ";
  if (!make_move("A4", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // TEST MORE CASES FOR LOGICAL ERRORS
  cout << endl << "TESTING MORE CASES FOR LOGIC: \n"; 

  // Test 10: Case 3 in F6 (not a valid move, presence in row)
  cout << endl << "Test 10: Putting '3' into F6 is ";
  if (!make_move("F6", '3', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 11: Case 2 in D1 (not a valid move, presence in column)
  cout << endl << "Test 11: Putting '2' into D1 is ";
  if (!make_move("D1", '2', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test 12: Case 7 in H6 (not a valid move, presence in box)
  cout << endl << "Test 12: Putting '7' into H6 is ";
  if (!make_move("H6", '7', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  
  cout << "=================== Question 3 ===================\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board)) {
    cout << "Save board to 'easy-copy.dat' successful.\n";
  } else {
    cout << "Save board failed.\n";
  }
  cout << '\n';


  cout << "=================== Question 4 ===================\n\n";
 
  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  // write more tests
  cout << "CONDUCTING ADDITIONAL TESTS \n"; 
  cout << "Tests commented out in main.cpp due to additional .dat files being required to run them. \n \n";
  
  /* 
  // Testing empty (should have a solution)
  cout << "Test 1: Testing an empty board \n"; 
  load_board("empty-board.dat", board);
  if (solve_board(board)) {
    cout << "The empty board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  // Testing faulty (should not have a solution)
  cout << "Test 2: Testing a faulty board \n"; 
  load_board("faulty-board.dat", board);
  if (solve_board(board)) {
    cout << "The faulty board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';
  */


  cout << "=================== Question 5 ===================\n\n";
  
  // write more tests

  // Q5.1 TESTING FOR WHICH BOARD IS IMPOSSIBLE

  cout << "TESTING FOR WHICH BOARD IS IMPOSSIBLE \n \n"; 
  
  // Test if mystery board 1 is impossible
  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery 1' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found. The 'mystery 1' board is the impossible one. \n";
  }
  cout << '\n';

  // Test if mystery board 2 is impossible
  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery 2' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found. The 'mystery 2' board is the impossible one. \n";
  }
  cout << '\n';

  // Test if mystery board 3 is impossible
  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery 3' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found. The 'mystery 3' board is the impossible one. \n";
  }
  cout << '\n';  

  // Q5.2 TESTING FOR WHICH BOARD IS EXTREMELY HARD 

  cout << "TESTING FOR WHICH BOARD IS EXTREMELY HARD \n \n";
  cout << "Tests commented out in main.cpp due to instructions needing to be followed to run tests (detailed in main.cpp and findings.txt). This program assumes that of the 2 remaining mystery boards, the one with the highest number of recursions is the 'extremely hard' one. \n \n"; 
  
  // Comment out Question 4 and Question 5.1. Activate static count in solve_board function in sudoku.cpp, and activate code relating to mystery board 1 recursions count below. 
  /*
  // Count number of recursions to solve mystery board 1 
  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << " is the number of recursions to solve mystery board 1. \n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';
  */

  // Comment out code relating to mystery board 1 recursions count above. Activate code relating to mystery board 3 recursions count below. 
  /*
  // Count number of recursions to solve mystery board 3
  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << " is the number of recursions to solve mystery board 3. \n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';
  */

  return 0;
}


