#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

// Function to check if there is a winner
bool checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (const auto& row : board) {
        if (row[0] != ' ' && row[0] == row[1] && row[1] == row[2]) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';

    while (true) {
        // Print the current state of the board
        printBoard(board);

        // Get player move
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0, 1, or 2): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter column (0, 1, or 2): ";
        cin >> col;

        // Check if the selected cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
        } else {
            cout << "Cell already taken. Try again." << endl;
            continue;
        }

        // Check for a winner or a draw
        if (checkWinner(board)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
