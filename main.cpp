#include <iostream>

int main()
{
    int clockTimer = 0;

    // Title screen.
    // Animation phase.
    std::cout << "\033[2J";   // Clears the screen.
    std::cout << "\033[?25l"; // Hides the cursor.

    bool isTitleTextOn = false;
    int numTitleBlinkCtr = 0;
    while (true) {
        // Update phase.
        // Set some variables to make the title text turn on or off.
        if (clockTimer % 4000 == 0 && clockTimer != 0) { // Skipping first tick because it's a bug.
            if (isTitleTextOn) {
                // A blink just ended since the title text was previously in an on state (it starts off).
                numTitleBlinkCtr++;
            }
            isTitleTextOn = !isTitleTextOn;
        }

        if (numTitleBlinkCtr > 3) {
            // Terminate animation loop once we have done enough animations.
            break;
        }

        // Render phase.
        std::cout << "\033[1;1H"; // Moves cursor to the top left.

        if (isTitleTextOn) {
            std::cout << " ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ \n"
                      << "|           |           |           |           |    ___    |           |           |    ___    |           |\n"
                      << "|___     ___|___     ___|     ______|___     ___|   |___|   |     ______|___     ___|   |   |   |   ________|\n"
                      << "    |   |    ___|   |___|    |______    |   |   |    ___    |    |______    |   |   |   |   |   |   ____|___ \n"
                      << "    |   |   |           |           |   |   |   |   |   |   |           |   |   |   |   |___|   |           |\n"
                      << "    |___|   |___________|___________|   |___|   |___|   |___|___________|   |___|   |___________|___________|\n";
        } else {
            std::cout << "                                                                                                             \n"
                      << "                                                                                                             \n"
                      << "                                                                                                             \n"
                      << "                                                                                                             \n"
                      << "                                                                                                             \n"
                      << "                                                                                                             \n";
        }

        std::cout << "                                                                                                             \n"
                  << "                                 A game developed by Sean Francis N. Ballais                                 \n"
                  << "                                                                                                             \n";

        clockTimer++;
    }

    // Main menu phase.
    std::cout << "\033[?25h"; // Shows the cursor.

    bool onMainMenuFreshStart = true;
    char option = 'C';
    while (onMainMenuFreshStart || (option != 'A' && option != 'B' && option != 'a' && option != 'b')) {
        std::cout << "\033[1;1H"; // Moves cursor to the top left.
        std::cout << " ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ \n"
                  << "|           |           |           |           |    ___    |           |           |    ___    |           |\n"
                  << "|___     ___|___     ___|     ______|___     ___|   |___|   |     ______|___     ___|   |   |   |   ________|\n"
                  << "    |   |    ___|   |___|    |______    |   |   |    ___    |    |______    |   |   |   |   |   |   ____|___ \n"
                  << "    |   |   |           |           |   |   |   |   |   |   |           |   |   |   |   |___|   |           |\n"
                  << "    |___|   |___________|___________|   |___|   |___|   |___|___________|   |___|   |___________|___________|\n"
                  << "                                                                                                             \n"
                  << "                                 A game developed by Sean Francis N. Ballais                                 \n"
                  << "                                                                                                             \n"
                  << "                                              =================                                              \n"
                  << "                                             |                 |                                             \n"
                  << "                                             |     A. PLAY     |                                             \n"
                  << "                                             |     B. EXIT     |                                             \n"
                  << "                                             |                 |                                             \n"
                  << "                                              =================                                              \n"
                  << "                                                                                                             \n";
        
        if (!onMainMenuFreshStart) {
            // By this point, we know that the player chose an invalid option.
            std::cout << "                                  (You chose an invalid input. A or B only.)                                 \n";
        }

        std::cout << "                                            Select an option:  \033[1D";
        std::cin >> option;

        onMainMenuFreshStart = false;
    }

    // We got a valid option, so let's process that.
    if (option == 'A' || option == 'a') {
        // Symbol selection screen.
        std::cout << "\033[2J"; // Clears the screen.

        bool onPlayerSymbolSelFreshStart = true;
        option = 'C';
        while (onMainMenuFreshStart || (option != 'A' && option != 'B' && option != 'a' && option != 'b')) {
            std::cout << "\033[1;1H"; // Moves cursor to the top left.
            std::cout << "                                                                                                             \n"
                      << "                                           Which one will go first?                                          \n"
                      << "                                                                                                             \n"
                      << "                                                                                                             \n"
                      << "                                                      |                                                      \n"
                      << "                     **       **                      |                      *********                       \n"
                      << "                      ***   ***                       |                   ***         ***                    \n"
                      << "                        ** **                         |                  *               *                   \n"
                      << "                         ***                          |                  *               *                   \n"
                      << "                        ** **                         |                  *               *                   \n"
                      << "                      ***   ***                       |                   ***         ***                    \n"
                      << "                     **       **                      |                      *********                       \n"
                      << "                                                      |                                                      \n"
                      << "                                                                                                             \n"
                      << "                        [ A ]                                                  [ B ]                         \n"
                      << "                                                                                                             \n";
            
            if (!onPlayerSymbolSelFreshStart) {
                // By this point, we know that the player chose an invalid option.
                std::cout << "                                  (You chose an invalid input. A or B only.)                                 \n";
            }
            
            // We do an extra space to clear previous input which we then remove.
            std::cout << "                                            Select an option:  \033[1D";
            std::cin >> option;

            onPlayerSymbolSelFreshStart = false;

            char firstPlayerSymbol = 'x';
            char secondPlayerSymbol = 'x';
            if (option == 'A' || option == 'a') {
                secondPlayerSymbol = 'o';
            } else if (option == 'B' || option == 'b') {
                firstPlayerSymbol = 'o';
            }

            // Play time.
            std::cout << "\033[2J";

            bool isGameRunning = true;
            char cell1 = '1';
            char cell2 = '2';
            char cell3 = '3';
            char cell4 = '4';
            char cell5 = '5';
            char cell6 = '6';
            char cell7 = '7';
            char cell8 = '8';
            char cell9 = '9';
            int activePlayer = 0;
            bool hasInvalidInput = true;
            bool onMoveSelFreshStart = true;
            int selectedCell = 0;
            while (isGameRunning) {
                while (hasInvalidInput) {
                    // Clear screen first.
                    std::cout << "\033[1;1H"; // Moves cursor to the top left.

                    // Clear screen.
                    int clearLinesCtr = 0;
                    while (clearLinesCtr < 25) {
                        std::cout << "                                                                                                             \n";
                    }

                    // Render.
                    std::cout << "\033[1;1H"; // Moves cursor to the top left.
                    std::cout << "                                                                                                             \n"
                              << "                                            Time to make a move!                                             \n"
                              << "                                                                                                             \n"
                              << "                                  _____________ _____________ _____________                                  \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |      " << cell1 << "      |      " << cell2 << "      |      " << cell3 << "      |                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |_____________|_____________|_____________|                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |      " << cell4 << "      |      " << cell5 << "      |      " << cell6 << "      |                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |_____________|_____________|_____________|                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |      " << cell7 << "      |      " << cell8 << "      |      " << cell9 << "      |                                 \n"
                              << "                                 |             |             |             |                                 \n"
                              << "                                 |_____________|_____________|_____________|                                 \n"
                              << "                                                                                                             \n";
                    
                    if (activePlayer == 0) {
                        std::cout << "                                             Player 1's Turn (" << firstPlayerSymbol << ")\n";
                    } else if (activePlayer == 1) {
                        std::cout << "                                             Player 2's Turn (" << secondPlayerSymbol << ")\n";
                    }

                    std::cout << "                                                                                                             \n";

                    if (!onMoveSelFreshStart) {
                        // By this point, we know that the player chose an invalid option.
                        std::cout << "                         (You chose an invalid input. 1-9 and unoccupied cells only.)\n";
                    }

                    std::cout << "                                            Select a cell (1-9):  \033[1D";
                    std::cin >> selectedCell;

                    // Check if input is valid.
                    if ((selectedCell >= 1 && selectedCell <= 9)
                        && (selectedCell == 1 && cell1 == '1'
                            || selectedCell == 2 && cell2 == '2'
                            || selectedCell == 3 && cell3 == '3'
                            || selectedCell == 4 && cell4 == '4'
                            || selectedCell == 5 && cell5 == '5'
                            || selectedCell == 6 && cell6 == '6'
                            || selectedCell == 7 && cell7 == '7'
                            || selectedCell == 8 && cell8 == '8'
                            || selectedCell == 9 && cell9 == '9')) {
                        hasInvalidInput = false;

                        char symbol = '.';
                        if (activePlayer == 0) {
                            symbol = firstPlayerSymbol;
                        } else if (activePlayer == 1) {
                            symbol = secondPlayerSymbol;
                        }

                        if (selectedCell == 1) {
                            cell1 = symbol;
                        } else if (selectedCell == 2) {
                            cell2 = symbol;
                        } else if (selectedCell == 3) {
                            cell3 = symbol;
                        } else if (selectedCell == 4) {
                            cell4 = symbol;
                        } else if (selectedCell == 5) {
                            cell5 = symbol;
                        } else if (selectedCell == 6) {
                            cell6 = symbol;
                        } else if (selectedCell == 7) {
                            cell7 = symbol;
                        } else if (selectedCell == 8) {
                            cell8 = symbol;
                        } else if (selectedCell == 9) {
                            cell9 = symbol;
                        }
                    }

                    onMoveSelFreshStart = false;
                }

                // Check for winning or ending condition.
                if ((cell1 == 'x' && cell2 == 'x' && cell3 == 'x') || (cell1 == 'o' && cell2 == 'o' && cell3 == 'o')
                    || (cell4 == 'x' && cell5 == 'x' && cell6 == 'x') || (cell4 == 'o' && cell5 == 'o' && cell6 == 'o')
                    || (cell7 == 'x' && cell8 == 'x' && cell9 == 'x') || (cell7 == 'o' && cell8 == 'o' && cell9 == 'o')
                    || (cell1 == 'x' && cell4 == 'x' && cell7 == 'x') || (cell1 == 'o' && cell4 == 'o' && cell7 == 'o')
                    || (cell2 == 'x' && cell5 == 'x' && cell8 == 'x') || (cell2 == 'o' && cell5 == 'o' && cell8 == 'o')
                    || (cell3 == 'x' && cell6 == 'x' && cell9 == 'x') || (cell3 == 'o' && cell6 == 'o' && cell9 == 'o')) {

                }
                if (cell1 != '1'
                    || cell2 != '2'
                    || cell3 != '3'
                    || cell4 != '4'
                    || cell5 != '5'
                    || cell6 != '6'
                    || cell7 != '7'
                    || cell8 != '8'
                    || cell9 != '9') {
                    // No further moves allowed.
                }

                // Switch players.
                activePlayer = (activePlayer + 1) % 2;

                // Reset.
                hasInvalidInput = true;
                selectedCell = 0;
                onMoveSelFreshStart = true;
            }
        }
    } else if (option == 'B' || option == 'b') {
        std::cout << "\033[1;1H"; // Moves cursor to the top left.

        // Clear screen.
        int clearLinesCtr = 0;
        while (clearLinesCtr < 50) {
            std::cout << "                                                                                                             \n";
        }

        std::cout << "\033[1;1H"; // Moves cursor to the top left.
    } else {
        std::cout << "ERROR! An invalid option somehow passed through!\n";
    }

    return 0;
}
