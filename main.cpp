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
    while (onMainMenuFreshStart || (option != 'A' && option && 'B' && option != 'a' && option != 'b')) {
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

    return 0;
}
