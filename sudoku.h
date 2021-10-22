void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);

// QUESTION 1

bool is_complete(const char board[9][9]); 

// QUESTION 2

bool make_move(const char position[2], const char digit, char board[9][9]);

bool check_position_range(const char position[2]);

bool check_digit_range(const char digit);

void convert_position_characters_into_indices(const char position[2], int &row, int &col); 

bool check_position_is_empty(const int row, const int col, const char board[9][9]);

bool absent_from_row(const int row, const char digit, const char board[9][9]); 

bool absent_from_column(const int col, const char digit, const char board[9][9]); 

bool absent_from_box(const int row, const int col, const char digit, const char board[9][9]); 

void update_board (const int row, const int col, const char digit, char board[9][9]); 

// QUESTION 3 

bool save_board(char* filename, const char board[9][9]); 

// QUESTION 4

bool solve_board(char board[9][9]);

bool find_empty_position(char position[2], char board[9][9]);

void convert_position_indices_into_characters (const int row_to_update, const int col_to_update, char position[2]); 
