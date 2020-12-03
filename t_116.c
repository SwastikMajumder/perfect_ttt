/********************* ================================= ***********************
**********************   TIC TAC TOE - ROBOTICS PROJECT  ***********************
********************** ================================= ***********************
--------------------------------------------------------------------------------
CODE BY SWASTIK MOZUMDER - CLASS 8A, MGM CP School, Trivandrum
--------------------------------------------------------------------------------
================================================================================
PROJECT SPECIFICATIONS
================================================================================
--------------------------------------------------------------------------------
COMPONENTS
--------------------------------------------------------------------------------
LEDs - 12
Arduino UNO R3 (CLONE) - 1
General Purpose Printed Circuit Board - 1
Lithium battery 8v - 1
Resistors (150 ohms) - 12
Button - 1
--------------------------------------------------------------------------------
Each LED is connected to a resistor of 150 ohms (except D9 and D12)
The input LEDs are connected from digital pin 2-10
The red LED is connected to 11th digital pin
The white LED is connected to 12th digital pin
The green LED is connected to 13th digital pin
The button's one end is connected to ground and other end to analog 0
Ground is common
--------------------------------------------------------------------------------
HOW TO OPERATE
--------------------------------------------------------------------------------
* Normally press buttons to switch between LEDs (moves/options)
* Long press for enter
* Two mode exist multi player and single player with computer
* For playing with the computer long press on 1st (play first) or 2nd (make
  the computer play first) LED or else long press on 3rd for multi player
* Computer moves, LED will blink and for user played moves LED will remain
  still
* In multi player the player playing first will have his LED still and the
  LED of the other player will be blinking
* Switch between moves by normal pressing and for entering move do a long press
* If the game is draw white LED glows or else red (user can't win) during single
  player but during multi player, if the one playing first wins the green LED
  will glow else red LED will glow if the other player wins and also if a draw
  happens white LED will glow
--------------------------------------------------------------------------------
HARDWARE
--------------------------------------------------------------------------------
ARDUINO -
Micro-controller: ATmega328P
Operating voltage: 5V
Input voltage: 7V - 12V (8V provided)
Digital I/O pins: 14
Analog pins: 6
Flash memory (where code is uploaded): 32 KB (ATmega328P) of which 0.5 KB used
by boot-loader
SRAM: 2KB
EEPROM (not used): 1KB
Clock: 16 MHz
Lithium battery -
Voltage - 8V
Capacity - 8000mAh
===============================================================================
DEVELOPMENT HISTORY
===============================================================================
-------------------------------------------------------------------------------
Initial developments (Till build 47)
-------------------------------------------------------------------------------
* Build an interface to make user input something
* AI plays random move
* Added feature of letting the user choose for playing first or last
* Fixed bugs like overwriting of moves and skipping of moves
* Check if the game has ended by representing each square as a prime number,
  if the product of any three squares were matched by the database number
  (I had mentioned) then match() return a number
* Used simple loops for match() (game checking)
* Stopped making the AI foolish move, at least AI would not lose until a
  double attack
* Fixed bugs in it
* Added a small database to play center whenever possible
* Added a feature to make the user choose if he wants to include the
  database or not
* Added feature to play double attacks (not to defend)
* Added a feature so if user is doing last and computer will always play a
  corner and a function to make the user lose if user does not play in center
* Added moves to the database which the function cannot catch (in the corner)
* Extended the database for center
* Extended the database for side
* Made the database a bit more bigger so that AI never loses
* Fixed some final bugs
-------------------------------------------------------------------------------
Medial developments (Till build 74)
-------------------------------------------------------------------------------
* Used returns instead of goto(s) to come of the function
* Made the chance variable local
* Re-written the whole code in loops and used arrays
* Removed many global variables and used address arithmetic instead
* Removed the function of corner and converted the whole in database
* Re-written the board rotating function according to some arithmetic as it was
  following some pattern
* Make the user prevent to do double attacks
* Made all functions return an address (in declaration) instead of integer
  because program was crashing and it was illegal in c++
* Changed the order of functions so also valid in c++
* Removed useless moves from the database
* Improved the random move playing function and fixed one critical bug in it
* Re-written the names of the function
* Made a non-used variable declaration removed
* Changed the main computer move playing function (which called other functions)
  to return a void, I returned 0 to exit a function so it was declared to return
  an integer, instead I made it return a void for the sake of exiting from the
  function
-------------------------------------------------------------------------------
Final developments (Till build 116)
-------------------------------------------------------------------------------
* Removed address arithmetic due to crashes
* Made isGameOver() better
* Added gameHandler()
* Added macro functions
* Added preprocessing so that native code and controller code can be switched
* Removed bugs in doubleAttack_forcePrevent()
* Used digitalRead() instead of analogRead() to read analog pins
* Made the program faster by involving functions only when certain moves are
  played
* Removed a bug in database()
* Changed the code according to the new input system
* Moved once called functions to caller functions
* Made one line repeated code a function macro for readability
* Defined USER, COMPUTER, EMPTY, START, HIGHER, ATTACK and DOUBLE_ATTACK for
  readability
* Moved EMPTY, START and HIGHER, as they are not required when native code
  is to be compiled
* Fixed input bug
* Made the code non-repeating in userInput()
* Fixed the order of function so also valid in c++
* Removed macro call from playUser() so valid in all compilers
* Used +3.3V instead of +5V for input
* Used ground instead of +3.3V for input
* Removed the warning returned by clang, added parentheses around
  doubleAttackMoves[1] && doubleAttackMoves[1] == attackMoves[0]
* Turn off the LED after user chose when he/she would be playing
* Did pre-incrementation instead of post-incrementation wherever possible
* Removed isEmpty() and improved database() to make it faster
* Introduced a better database system
* Added trickier moves to the database
* Made the database faster by making it know how many moves are played
* Removed function/macro returnCorner()
* Updated critical move 2, 7; 3; 9: 9 -> 5 in database
* Added critical move 2; 5; 1 in database
* Added move 1; 5; 9 in database
* Added bit boards
* Fixed match()
* Made match() faster by introducing a local not board
* Made macro isLegal faster
* Made macro isIllegal faster
* Made macros playMove and undoMove faster
* Made attack() independent of match()
* Made attack() faster by using bitwise techniques
* Fixed attack() bug by changing the checking of power of 2 from decrementing
  technique to incrementing technique as it can handle 0 too
* Made attack() more fast by introducing a second not board
* Introduced local not boards everywhere for speed
* Rather than incrementing, the numbers shifted and so changed the system
  of communication to playComputer() for speed
* Removed isLegal, isIllegal, isOdd, playMove and undoMove macros
* Made playComputer() more fast by using bitwise techniques
* Made draw checking faster by using or between the two bit boards and check
  if the value is 511 or not
* Fixed critical bug, changed all for(i=1; i<256; i<<=1) to
  for (i=1; i<512; i<<=1) as earlier one does not check the last node
* Added move 5; 1; 9
* Made database communication with playComputer() advanced
* Featured loops in attack() for line values, gains speed in -O3 and made the
  code less repeating but lost speed in other levels of optimizations
* Removed global variables and used address arithmetic instead but bit speed
  loss for lower optimizations (except for database() where instead speed was
  gained) and speed gain for higher optimizations
* Fixed address arithmetic for micro-controller
* Prevent the database to know how many moves are played
* Fixed critical move replies in database
* Reversed normal loops
* Reversed bit shifting loops
* Fixed critical bug in database introduced due to reversing of loops
* Added multi player
* Removed critical bugs in multi player
* Made the blinking pattern changeable
* Code simplification
==============================================================================
COMPILERs AND IDEs used
==============================================================================
Initial developments - DEV C++ 5.11, TDM-1 GCC 4.9.2
Medial developments - Code::Blocks 16.01, TDM-1 GCC 4.9.2 (-std=c99)
Final developments - Code::Blocks 16.01, GCC 6.3.0-1 (-std=c99 -O3)

Current program valid in all compilers including (tested for native code) -
* TDM-1 GCC 4.9.2
* GCC 6.3.0-1
* TCC 0.9.24
* Microsoft Visual C++ 2010
* Clang 5.0.0 (6.0.0)

Compiles with 0 errors and 0 warnings
Works with (-std=c99) if applied
The version of arduino also compiles well without warnings
------------------------------------------------------------------------------
REFER AUTHOR NOTES FOR MORE INFORMATION
------------------------------------------------------------------------------
*******************************************************************************/

#define NATIVE_CODE _defined_
/* The above line should not be present if to be compiled for arduino
   If it is to compile the native code NATIVE_CODE has to be defined
*/
/* Bit boards for both players, 0th position is for USER and
   1st is for COMPUTER
   The board has its operations in reversed position i.e.
   010000100, 000010000 means
   -|-|X
   -|O|-
   -|X|-
*/
#define USER 0 //Position of the bit board of user in board array is 0
#define COMPUTER 1 //Position of the bit board of computer in board array is 1

#define TOTAL_DATABASE_MOVES 85 //Total number of moves in database

#define FIRST_ROW 7 //000000111
#define SECOND_ROW 56 //000111000
#define THIRD_ROW 448 //111000000
#define FIRST_COLUMN 73 //001001001
#define SECOND_COLUMN 146 //010010010
#define THIRD_COLUMN 292 //100100100
#define FIRST_DIAGONAL 273 //100010001
#define SECOND_DIAGONAL 84 //001010100

#ifdef NATIVE_CODE
  #include <stdio.h> //Called printf() and getchar(); defined NULL
	#include <stdlib.h> //Called rand()
	#include <time.h> //Called time()
	#define PAUSE_AT_END _defined_
	#define BUILD 116 //Build number
#else
  /* arduino.h is automatically included by arduino's IDE
     HIGH is defined as 0x1 == 1
     LOW is defined as 0x0 == 0
     true is defined as 1
     false is defined as 0
     Move LEDs are connected from pin 2-10 so for converting array move
     notation, 0-8, +2 is done wherever necessary to convert to pin format
  */
	#define rand() random(1000) //Arduino seldom supports rand()
	#define LOSE_PIN 11 //The red LED is joined to 11
	#define DRAW_PIN 12 //The white LED is joined to 12
	#define WIN_PIN 13 //The green LED is joined to 13
	#define HALT_TIME 5 //Halt time for repeated checking
	#define BLINK_TIME 100 //Blinking (state switch) time of LEDs
	#define LONG_PRESS_TIME 1300 //Time when button considered long press
	#define EMPTY -1 //EMPTY is smaller than 0
  #define HIGHER 2 //HIGHER == 2 is value for long press bigger than HIGH == 2
  #define BLINK_PATTERN 1 //The pattern of blinking
  #define START 0
  /* START == 0 as,
  * Time counting starts from 0
  * 0 is considered as 1st move in array notations
    (we will use the same in userInput())
  */
#endif /* NATIVE_CODE */

//In the whole project line meant row/column/diagonal
//In the whole project computer meant AI (for non-native code it meant arduino)

int match(int playerBoard){
/* Tells whether a line is completed or not
   At first it applies not logic to the board of the player
   then it does apply and logic with each of the values of lines,
   if any of them return a value of 0 then row is competed (returns 1)
   else if all of them passes then returns 0 as no row is completed
   Example -
   000111000
   ~000111000 = 111000111
   When it deals with 000111000 (56)
   111000111 & 000111000 = 0 so the function return 1
   (A line is completed)
*/
  int notBoard = ~playerBoard; //Forms a local not board
  return !((notBoard & FIRST_ROW) &&
      (notBoard & SECOND_ROW) &&
      (notBoard & THIRD_ROW) &&
      (notBoard & FIRST_COLUMN) &&
      (notBoard & SECOND_COLUMN) &&
      (notBoard & THIRD_COLUMN) &&
      (notBoard & FIRST_DIAGONAL) &&
      (notBoard & SECOND_DIAGONAL));
}

int database (int* board){
/* DATABASE:

  USER COMPUTER MOVE DESCRIPTION
  ------------------------------
   2       -     3       PL
   1       -     5       PL
   5       -     3       PL
   2       5     1       FW
   1       5     9       UC
   5       1     8       UC
   9       2     3       FW
   6       2     3       FW
   7       2     1       FW
   4       2     1       FW
   3       2     7       PL
   1       2     7       PL
   2       1     5       FW
   4       1     5       FW
   6       1     5       FW
   8       1     5       FW
   3       1     7       FW
   7       1     9       FW
   9       1     3       FW
   2, 1    3     6       FW
   2, 4    3     9       FW
   2, 7    3     5       PL
  ------------------------------

  The column USER defines the moves which user plays
  The column COMPUTER defines the moves which computer plays
  The column MOVE defines the respond moves
  The column DESCRIPTION defines why the move is played -
  There; PL, FW, and UC mean -
  PL - Prevent losing
  FW - Force win
  UC - Uncritical move
  If a move is defined as a PL move means if computer had played a random it
  may lose, there may be other good moves but this one may lead to the user
  lose as after playing this move there might be only few places where user
  cannot lose.
  If a move is defined as a FW move means if computer had played that move,
  user would lose that game anyway.
  If a move is defined as a UC move means if computer had played that move,
  there might be only few places where user cannot lose, nevertheless even
  if computer had played a random move and if a perfect game is played by
  the user would have lead to a draw.

  Example (the last row in database) (computer is 'O') -
  -|X|O    -|X|O
  -|-|- -> -|O|-
  X|-|-    X|-|-
  Prevents a lose as 1, 4 and 6 may lead to a lose, where 6 is undetectable
  by other functions i.e. attack(), doubleAttack() and
  doubleAttack_forcePrevent()

  The database works in following steps -
  * Initialize variables, data_cases[] and data_moves[]
  * Convert current (binary) board to ternary format then to decimal format
  * Set the variables for how many and which moves to search according to
    the number of moves played
  * Search the database, if any the decimal value of the board matches with a
    value in database, return data_moves[position]; as the position of reply
    moves and position of boards in data_cases[] are same

  The values in data_cases[] are generated with the same algorithm which is
  used by database() to convert the boards to decimals format

  Converting boards to decimal format -
  A board in this program is 1 dimensional similar to this -
  int board[2] = {0, 0};
  where the 0th position is of USER and the 1st position is of COMPUTER.
  The first step is to convert the binary board to ternary, which done like this;
  we know a fact that the bit boards of USER and COMPUTER never intersects, so each
  position is interpreted as; if computer played a move it is interpreted as - 2,
  if user played a move it is interpreted as - 1 or else if no move is played we
  call it as 0. Example -
  {0b010000110, 0b001010001} =
  {0, 1, 2, 0, 2, 0, 1, 1, 2}
  Then it is converted to decimal (here ^ means to the power not xor)-
  (As ternary has base 3, every number has to be multiplied by powers of 3)
  0 x 3^8 + 1 x 3^7 + 2 x 3^6 + 0 x 3^5 + 2 x 3^4 + 0 x 3^3 + 1 x 3^2 + 1 x 3^1
  + 2 x 3^0
  (Power of 3 increases as place value increases)
  = 3821
  If the board will be rotated the values will become -
  15013 -> 16221 -> 7013 -> 3821

  Here rotation is defined as (computer is 'O')(anti-clockwise) -
  3821     15013    16221    7013
  -|X|O    O|-|O    O|X|X    X|-|-
  -|O|- -> X|O|X -> -|O|- -> X|O|X
  X|X|O    -|-|X    O|X|-    O|-|O
*/
  int power=1, boardValue=0, i;
  int data_cases[TOTAL_DATABASE_MOVES] =
  //Possible boards
  {
      243, 3, 27, 2187, //2; -; 3
      9, 1, 729, 6561, //1; -; 5
      81, //5; -; 3
      405, 165, 189, 2349, //2; 5; 1
      171, 163, 891, 6723, //1; 5; 9
      99, 83, 1539, 13203, //5; 1; 9
      1215, 6567, 63, 4375, //9; 2; 3
      2673, 249, 57, 4401, //6; 2; 3
      487, 735, 6615, 4383, //7; 2; 1
      489, 33, 2241, 4617, //4; 2; 1
      7047, 15, 55, 5103, //3; 2; 7
      495, 7, 783, 10935, //1; 2; 7
      261, 5, 1485, 15309, //2; 1; 5
      21, 29, 3645, 13365, //4; 1; 5
      2205, 245, 1461, 13149, //6; 1; 5
      45, 2189, 1701, 13125, //8; 1; 5
      6579, 11, 1459, 13851, //3; 1; 9
      19, 731, 8019, 13131, //7; 1; 9
      747, 6563, 1467, 13123, //9; 1; 3
      13374, 22, 758, 10206, //2, 1; 3; 6
      13368, 48, 2216, 3888, //2, 4; 3; 9
      13366, 750, 6590, 3654 //2, 7; 3; 5
  };
  int data_moves[TOTAL_DATABASE_MOVES] =
  //Possible plays to board situations
  {
      1, 64, 256, 4, //3
      16, 16, 16, 16, //5
      4, //3
      64, 256, 4, 1, //1
      4, 1, 64, 256, //9
      4, 1, 64, 256, //9
      1, 64, 256, 4, //3
      1, 64, 256, 4, //3
      64, 256, 4, 1, //1
      64, 256, 4, 1, //1
      256, 4, 1, 64, //7
      256, 4, 1, 64, //7
      16, 16, 16, 16, //5
      16, 16, 16, 16, //5
      16, 16, 16, 16, //5
      16, 16, 16, 16, //5
      256, 4, 1, 64, //7
      4, 1, 64, 256, //9
      1, 64, 256, 4, //3
      2, 8, 128, 32, //6
      4, 1, 64, 256, //9
      16, 16, 16, 16 //5
  };
  for (i=8; i>=0; --i){ //See the board in reverse order
    boardValue += power * (board[COMPUTER] & 1<<i ? 2 : board[USER]>>i & 1);
    //Convert the bit board to ternary format and then to decimal
    power *= 3; //Increase base size as it goes to higher place value
  }
  for (i=TOTAL_DATABASE_MOVES-1; i>=0; --i) //Search the database
    if (data_cases[i] == boardValue) //If the board matches the database
      return data_moves[i]; //Return the best move
  return 0; //Else return 0
}

void attack(int* board, int* attackMoves, int player){
/* This function is meant to prevent a completion or do it of a line
  X|X|-
  O|O|-
  -|-|-
  If user is 'X' and input to the player variable is 0 it will return 3
  If computer is 'O' and input to the player variable is 1 it will return 6
  Used bitwise techniques for speed,
  Calculated nots of both bit boards at startup.
  attackMove is a power of 2 if the bit board of the required player is
  having one move to complete a line in its board.
  Then it checks legality with the not board of the other player, if legal
  the resultant value is equal to attackMove only else it will be 0.
  Then not of attackMove is taken and 1 is added to it and it is checked
  with the resultant value of the legality check and an and logic is done
  on it, if the resultant is equal to attackMove then it is added to
  attackMoves[] array.
  The trick for checking if a number is power of 2 or not is described -
  (x & (~x+1)) == x, if the move will be legal result would be 1 else 0
  a faster version is available !(x & (x-1)) but it can handle 0 at no
  side.
*/
  int notBoard = ~board[player], notBoard_2 = ~board[!player], index=0, i;
  //Not boards and variables
  int lines[8] = {FIRST_ROW, SECOND_ROW, THIRD_ROW,
                  FIRST_COLUMN, SECOND_COLUMN, THIRD_COLUMN,
                  FIRST_DIAGONAL, SECOND_DIAGONAL}; //Lines
  attackMoves[0] = attackMoves[1] = 0; //Clear array
  for (i=7; i>=0; --i){ //Check all lines
    int attackMove = notBoard & lines[i]; //Calculate attack move
    if (((attackMove & notBoard_2) & (~attackMove+1)) == attackMove)
    //If legal and an attack
      attackMoves[index++] = attackMove; //Add to array
  }
}

void doubleAttack(int* board, int* attackMoves, int* doubleAttackMoves, int player){
/* This function is meant to prevent or do a double attack
  X|-|O
  -|-|X
  -|-|O
  If user is 'X' and input to the player variable is 0 it will return 4
  If computer is 'O' and input to the player variable is 1 it will return 7
*/
  int i, index=0;
  doubleAttackMoves[0] = doubleAttackMoves[1] = 0; //Clear array
  int twinBoard = ~(board[USER] | board[COMPUTER]);
  //Create a twin board where legal moves are stored
  for (i=256; i>0; i>>=1) //Try all moves
    if (i & twinBoard){ //If legal
      board[player] |= i; //Try the move
      attack(board, attackMoves, player); //Check for attacks
      if (attackMoves[0] && attackMoves[1]) //If there are 2 attacks
        doubleAttackMoves[index++] = i; //Add in the array
      board[player] &= ~i; //Undo the move
    }
}

int doubleAttack_forcePrevent(int* board, int* attackMoves, int* doubleAttackMoves){
/*This function is meant to force prevent a double attack
  X|-|-
  -|O|-
  -|X|-
  If computer is 'X' it will return 4
*/
  int i;
  int twinBoard = ~(board[USER] | board[COMPUTER]);
  //Create a twin board where legal moves are stored
	doubleAttack(board, attackMoves, doubleAttackMoves, USER); //Check if the user is going to do a double attack
	if (doubleAttackMoves[0]) //If can
    for (i=256; i>0; i>>=1) //Check all moves
      if (i & twinBoard){ //If legal
        board[COMPUTER] |= i; //Try the move
        attack(board, attackMoves, COMPUTER); //Checks if computer forced the user to play something
        /* Definitions of which moves to skip -
           *  !attackMoves[0] - If by playing a move computer can't do an attack
           *  doubleAttackMoves[0] == attackMoves[0] -
               If the reply by the user makes enables the user do a double attack too
           *  doubleAttackMoves[1] && doubleAttackMoves[1]
                                      == attackMoves[0] - Checks if
              there are two possible double attacks by the user and if it is there
              check that if the reply of the attack of the user makes the other
              double attack of the user possible
        */
        if (!attackMoves[0] ||
            doubleAttackMoves[0] == attackMoves[0] ||
            (doubleAttackMoves[1] && doubleAttackMoves[1]
                                     == attackMoves[0])){
          board[COMPUTER] &= ~i; //Undo the move
          continue; //Go for another move
        }
        board[COMPUTER] &= ~i; //Undo the move
        return i; //Return the move, if success to prevent the double attack
      }
  return 0; //return 0 if this function has no use
}

void playComputer(int* board, int movesPlayed){ //Make the computer choose a move
  int bestMove; //Temporary variable for storing the moves
  int attackMoves[2]={0}; //Stores moves returned by attack()
  int doubleAttackMoves[2]={0}; //Stores moves returned by doubleAttack()
  //Prevents them to call functions again and again
  if (!movesPlayed){ //If no moves are played
    //To escape the checking of database
    //To escape complex random move playing
    board[COMPUTER] |= 1 << (rand()%9); //Play a random move
    return;
  }
  if (movesPlayed < 4){ //If less than 4 moves are played
    bestMove = database(board); //Check the database
    if (bestMove){ //If a moves matches the database
      board[COMPUTER] |= bestMove; //Do that
      return;
    }
  }
	if (movesPlayed > 2){ //If more than 2 moves are played
    attack(board, attackMoves, COMPUTER); //Try if computer could do a line
    if (attackMoves[0]){ //If can
        board[COMPUTER] |= attackMoves[0]; //Play that
        return;
    }
    attack(board, attackMoves, USER); //If user could do a line
    if (attackMoves[0]){ //If can
        board[COMPUTER] |= attackMoves[0]; //Block that
        return;
    }
	}
	if (movesPlayed > 3){ //If more than 3 moves are played
    doubleAttack(board, attackMoves, doubleAttackMoves, COMPUTER); //If could a double attack
    if (doubleAttackMoves[0]){ //If can
      board[COMPUTER] |= doubleAttackMoves[0]; //Play a double attack
      return;
    }
  }
  if (movesPlayed > 2){ // If more than 2 moves are played
    bestMove = doubleAttack_forcePrevent(board, attackMoves, doubleAttackMoves);
    //If user can do a double attack
    if (bestMove){ //If can
      board[COMPUTER] |= bestMove; //Prevent it
      return;
    }
  }
#define index bestMove
  /* Prevent the need of redeclaring a new variable.
     No need to make the index 0 as bestMove would already be zero
     due to the functions doubleAttack_forcePrevent() and database(),
     any two of them fails and make the bestMove variable 0 and so,
     a call is reaching here. */
  //Play a random move
  int i, emptyBoard_locations[9];
  int twinBoard = ~(board[USER] | board[COMPUTER]);
  //Create a twin board where legal moves are stored
  for (i=256; i>0; i>>=1) //Search the whole board
    if (twinBoard & i) //If the place is empty
      emptyBoard_locations[index++] = i; //Add in the record
  board[COMPUTER] |= emptyBoard_locations[rand()%index];
  //Play random move
#undef index
}

int isGameOver(int* board, int player){ //Check if game is over or not
	if (match(board[COMPUTER])){ //If computer won
#ifdef NATIVE_CODE
    if (player == 3){ //If multi player
      printf("User-2 has won!!!\n");
    } else { //Else
      printf("Computer has won!!!\n");
    }
#else
    digitalWrite(LOSE_PIN, HIGH); //Turn on red LED
#endif /* NATIVE_CODE */
    return 1;
  }
  else if (match(board[USER])){ //If the board of user own
#ifdef NATIVE_CODE
    if (player == 3){ //If multi player
      printf("User-1 has won!!!\n");
    } else { //Else
      printf("User has won!!!\n");
    }
#else
    digitalWrite(WIN_PIN, HIGH); //Turn on green LED
#endif /* NATIVE_CODE */
    return 1;
  }
  if ((board[USER] | board[COMPUTER]) != 511)
  //If there zero anywhere in or of both bit boards
    return 0; //It is not draw
#ifdef NATIVE_CODE
	printf("The game is a draw\n");
#else
	digitalWrite(DRAW_PIN, HIGH); //Its draw
#endif /* NATIVE_CODE */
	return 1;
}

#ifdef NATIVE_CODE
void playUser(int* board, int player){
	int user_input, twinBoard = ~(board[USER] | board[COMPUTER]);
	//Create a twin board where legal moves are stored
	for(;;){ //Infinite loop
		user_input = getchar() - '0'; //Take input using getchar()
		if (user_input < 1 || user_input > 9) //Check if a move in bounds
			continue;
		--user_input; //Convert move in 1-9 notation to 0-8 notation
		//If no player had played the move
		if (twinBoard & 1 << user_input){
      board[player] |= 1 << user_input; //Play the move as user
			break;
		}
	}
}

void print_board(int* board){ //Print the board
  int i, j;
  for(i=0; i<3; ++i, printf("\n")) //Print a line break after 3
    for(j=0; j<3; ++j){ //Print each of the piece
      printf("%c|",board[USER] & 1<<(i*3+j) ? 'X' :
                   board[COMPUTER] & 1<<(i*3+j) ? 'O' : '-');
      /* If user played some move return 'X' to printf()
         Else if computer played some move return 'O' to printf()
         Else return '-' to printf()
      */
    }
  printf("\n");
}
#else
int userInput(int* board, int limit, int blinkStyle, int blinkBoard){
  int userSelection, state, input, timeCount, button_timeCount, i;
  timeCount = button_timeCount = START; //Set timer to START
  for (userSelection=EMPTY, state=false;;delay(HALT_TIME)){ //Infinite loop
    //Clear variables at first and delay every HALT_TIME milliseconds
    if (button_timeCount > LONG_PRESS_TIME){ //If exceeds time
      button_timeCount = START; //Reset timer
      input = HIGHER; //Input was a long press
    }
    else if (analogRead(0)){ //If button released
    /* Analog 0 is connected to ground
    * Ground has no voltage or 0 volts
    * So analogRead(0) returns 0 on the button being pressed
    * When not pressed returns floating values which is > 0
    */
      if (!button_timeCount){ //If counting not started
        input = LOW;
      } else { //If started
        button_timeCount = START; //Reset timer
        input = HIGH; //Input was a normal press
      }
    } else { //Else if button not released yet
      button_timeCount += HALT_TIME; //Count time
      input = LOW;
    }
    switch(input){ //Analyze input
      case LOW: //No input
      //Then blink LEDs
        if (timeCount > BLINK_TIME){ //If blinking time reached
          timeCount = START; //Reset timer
          state = !state; //Change state
          if (blinkBoard){
            for (i=8; i>=0; --i) //For whole board
              if (board[COMPUTER] & 1<<i) //If 2nd board has a move
                digitalWrite(i+2, state); //Blink it
          } else {
            for (i=8; i>=0; --i) //For whole board
              if (board[USER] & 1<<i) //If 1st board has a move
                digitalWrite(i+2, state); //Blink it
          }
          if (!blinkStyle)
            if (userSelection >= 0) //If a move is selected
              digitalWrite(userSelection+2, state); //Blink it
        }
        timeCount += HALT_TIME; //Count time
        break; //For speed reasons
      case HIGH: //Normal press
      //Then make the selection switch to next
        if (userSelection >= 0){ //If a move is selected
          digitalWrite(userSelection+2, LOW);
          //Turn off LED of last selection
          if (++userSelection == limit){ //If move crossed the limit
          //We are checking and incrementing (for next condition)
            userSelection = EMPTY; //Reset
            break; //EMPTY is always legal
          }
        } else { //If no move selected
          userSelection = START; //Start counting moves
        }
        if (~(board[USER] | board[COMPUTER]) & 1 << userSelection) {
        //If the next move is legal
          digitalWrite(userSelection+2, HIGH);
          break; //Go with it
        } else { //Else if next move is illegal move
          while ((board[USER] | board[COMPUTER]) & 1 << userSelection)
          //Continue until a legal move
            if (++userSelection >= limit){
            //Go to next move
              userSelection = EMPTY;
              //Reset to EMPTY if limit reached
              break; //EMPTY is always legal
            }
        }
        digitalWrite(userSelection+2, HIGH);
        break; //For speed reasons
      case HIGHER: //Long press
      //Return the move
        if (userSelection >= 0){ //If user selected a move
          if (limit == 3) //If user is choosing the chance
            digitalWrite(userSelection+2, LOW);
            //Turn off the LED after user choose when to play
          return userSelection+1; //Return that
        }
    }
  }
}

void print_board(int* board, int blinkStyle){
  //Print the board
  int i;
  for (i=8; i>=0; --i){ //Check all moves
    if (board[USER] & 1<<i) //If user did something
      digitalWrite(i+2, blinkStyle); //Show it in the board
    if (board[COMPUTER] & 1<<i) //If computer played a move
      digitalWrite(i+2, !blinkStyle);
      //Set it to LOW for blinking when input is asked
  }
}
#endif /* NATIVE_CODE */

void gameHandler(int* board, int player){
  int plys; //Number of moves played
#ifdef NATIVE_CODE
  print_board(board);
#else
  print_board(board, BLINK_PATTERN); //Print the board
#endif /* NATIVE_CODE */
  for (plys=0; !isGameOver(board, player); ++plys){ //If game has not over
    if (player == 3){ //If multi player
#ifdef NATIVE_CODE
      playUser(board, plys & 1); //Switch board according to plys
      print_board(board);
#else
      board[plys & 1] |=
      1 << (userInput(board, 9, (plys & 1)^BLINK_PATTERN, BLINK_PATTERN)-1);
      //Play move
      print_board(board, BLINK_PATTERN);
#endif /* NATIVE_CODE */
    }
    else if ((player + plys) & 1){ //Calculate whose chance
#ifdef NATIVE_CODE
			playUser(board, 0); //Make the user give an input
			print_board(board);
#else
      board[USER] |= 1 << (userInput(board, 9, BLINK_PATTERN, BLINK_PATTERN)-1);
      print_board(board, BLINK_PATTERN);
#endif /* NATIVE_CODE */
		} else {
			playComputer(board, plys); //Make the computer analyze a move
#ifdef NATIVE_CODE
			print_board(board);
#else
      print_board(board, BLINK_PATTERN);
#endif /* NATIVE_CODE */
		}
	}
}

#ifdef NATIVE_CODE
int main (){
  int chance; //Variable to determine who is playing now
  int board[2] ={0};
	srand(time(NULL)); //Seed a random number in rand() by time()
	printf("Tic Tac Toe - AI by Swastik Mozumder, Build - %d\n\n", BUILD);
	printf("To enter moves, type number from 1 to 9\n\n");
	printf(" 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 \n\n");
	printf("Play (with computer) (1)st, (2)nd or play (3)Multiplayer?: ");
	for(;;){ //Infinite loop
    chance = getchar() - '0'; //Get input from user
    if (chance > 0 && chance < 4) //If valid input
      break; //Go with that
	}
	printf("================================================\n\n");
	gameHandler(board, chance); //Run the game
	getchar();
	printf("Press any key to continue . . . ");
	getchar();
	return 0;
}
#else
void loop_blink(int* board, int blinkStyle){
int i, j;
for (;;)
  for (i=1; i>=0; --i){ //Know state of blinking LEDs
    for (j=8; j>=0; --j) //Check the whole board
      if (board[blinkStyle] & 1<<j) //If user did a move
        digitalWrite(j+2, i); //Blink
      delay(BLINK_TIME); //Delay
  }
}
void setup (){
	// put your setup code here, to run once:
  int i, j, board[2]={0};
  randomSeed(analogRead(1));
  //Seeds random according to analogRead(1), it gives random numbers
	for (i=2; i<14; ++i)
		pinMode(i, OUTPUT); //Sets the pins of LEDs as output
	gameHandler(board, userInput(board, 3, BLINK_PATTERN, BLINK_PATTERN));
	//Run the game and ask the user about the mode of the game
	loop_blink(board, BLINK_PATTERN);
}

void loop() {
  // put your main code here, to run repeatedly:
}
#endif /* NATIVE_CODE */

/********************* ================================= ***********************
**********************           AUTHOR NOTES            ***********************
********************** ================================= ***********************
This whole document/code written by me, Swastik Mozumder but that does not prove
that either I had made this project alone or someone helped me in it. This code
is not copied from anywhere or taken help from someone else, reference and rules
of C language might be taken from ANSI C Third Edition (BOOK). Previously, I was
going to make this document in MS-WORD or similar word editors, but now I had
included the notes with the code. This is the 116th build made starting from
the 1st build and might have more in future. I used no debugger for debugging
the code. The previously used DEV C++ for compiling and writing the code but due
to its instability and bugs I switched to Code::Blocks. For compiling code for
arduino I used its software arduino itself for compiling the code. A third
party software syntax highlighting was used for printing and highlighting the
document. This software does not use advanced algorithms like negamax, minimax,
etc. I did not implanted due to have the viewers a feel that this is a legit
project and also I could not create a stable and a reasonable version of the
same. This one of the big projects I made and me actually coding this thing
from when I started learning to code, an year ago. This made me make 3 sections
in the development history. This is not much of a perfect good code but somehow
it is bit respectful. This program is FAR FASTER than better programs which use
things like alpha-beta or negascout due the better programs are bit less
'artificially intelligent' than this one due to it simply searches all possible
moves in the game. Some programs might use brilliant techniques to avoid
searching of many nodes (like alpha-beta) but still this program is more of an
AI and plays more like humans does. Algorithms like these may search up to
5000+ game possibilities, better ones may reduce them to 1000s or may be less
than that, but this one will search FAR LESSER nodes; maximum 52 nodes, in
normal cases less than 13 and for some good double attacks less than 49 nodes.
It even searches 0 nodes or search the database for initial phase of the game.
I have seen programs searching the whole game tree at 0 moves played too,
because their programs know nothing more than the rules of the game. This one
is a bit experienced one who knows all the traps already. The database which
makes it real good is updated now, for speed and stability but the new
database does not understand symmetry but the old one did. The new one has
already all the symmetry calculated whereas the old one had to do. The
database uses several tricks so that it becomes fast (;) maths helped me). I
made it really much more faster in compared to the older version of the
database, I did not made it more fast as I did not wanted to consume all the
temporary memory, just the sake of making it faster by couple of trillionth
or billionth of a second. Then the greatest improvement which I made is
adding the bit boards. Computers store every number in the form of binaries,
so it can faster understand it rather than seeing different chunks of memory
for the board. We humans can pretty understand well the binaries in the form
of the numbers in base 10 which are the decimals numbers which we use in our
daily lives. But when something is like this; 2 numbers - 16 and 1, in my
software this means that computer played the first corner and user played the
middle and it the chance of the computer now. Still it is not much complex if
16 and 1 are converted to binary and reversed then we can clearly understand
the meaning of the computer; 000010000, 100000000, where user is the first
one (5th bit is one so user played the 5th block) and in the second one the
first bit is on so computer played the first move. But these kind of logic
makes the computation of the resultant moves faster. My primary goal of the
project was to make it faster and the secondary goal was to make it readable
and it should play similar to how humans play. I did pretty much more than I
excepted but still I feel it could be a bit better.

This software plays human-like I can represent how it plays in some simple
steps-
--------------------------------------------------------------------------
(If no moves are played)
* PLAY A RANDOM MOVE

(If less than 4 moves are played)
* SEARCH THE DATABASE FOR MOVES

(If more than 2 moves are played)
* TRY TO WIN IN ONE MOVE, IF POSSIBLE
* SEE IF USER IS WINNING IN ONE MOVE; IF YES, THEN PREVENT IT

(If more than 3 moves are played)
* IF POSSIBLE, PLAY A DOUBLE ATTACK

(If more than 2 moves are played)
* IF USER CAN PLAY A DOUBLE ATTACK, PREVENT IT

* PLAY A RANDOM MOVE
--------------------------------------------------------------------------
Here, 'PLAY A RANDOM MOVE' at the end and at the last looks same but are not.
The first one is much simpler due to the first one knows that there is nothing
played in the board.

Kindly avoid misunderstanding line breaks in middle of the codes mainly in C++
style comments.

THANK YOU :)
HAVE A NICE DAY...
*******************************************************************************/
