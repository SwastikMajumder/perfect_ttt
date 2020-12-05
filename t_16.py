'''
********************** ================================= ***********************
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
'''

import random

# CONSTANTS

USER = 0 #Position of the bit board of user in board array is 0
COMPUTER =  1 #Position of the bit board of computer in board array is 1

TOTAL_DATABASE_MOVES = 85 #Total number of moves in database

FIRST_ROW  = 7 #000000111
SECOND_ROW = 56 #000111000
THIRD_ROW = 448 #111000000
FIRST_COLUMN = 73 #001001001
SECOND_COLUMN = 146 #010010010
THIRD_COLUMN = 292 #100100100
FIRST_DIAGONAL = 273 #100010001
SECOND_DIAGONAL = 84 #001010100

BUILD = 116 #Build number

#In the whole project line meant row/column/diagonal
#In the whole project computer meant AI (for non-native code it meant arduino)

board = [0, 0]
attackMoves = [0, 0]
doubleAttackMoves = [0, 0]

def match(playerBoard):

    '''
    Tells whether a line is completed or not
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
    ''' 

    notBoard = ~playerBoard #Forms a local not board
    return not(bool(notBoard & FIRST_ROW) and \
               bool(notBoard & SECOND_ROW) and \
               bool(notBoard & THIRD_ROW) and \
               bool(notBoard & FIRST_COLUMN) and \
               bool(notBoard & SECOND_COLUMN) and \
               bool(notBoard & THIRD_COLUMN) and \
               bool(notBoard & FIRST_DIAGONAL) and \
               bool(notBoard & SECOND_DIAGONAL))

def database():
    '''
    DATABASE:

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
    '''

    power = 1
    boardValue = 0
    data_cases = [ \
    243, 3, 27, 2187, \
    9, 1, 729, 6561,  \
    81, \
    405, 165, 189, 2349, \
    171, 163, 891, 6723, \
    99, 83, 1539, 13203, \
    1215, 6567, 63, 4375, \
    2673, 249, 57, 4401, \
    487, 735, 6615, 4383, \
    489, 33, 2241, 4617, \
    7047, 15, 55, 5103, \
    495, 7, 783, 10935, \
    261, 5, 1485, 15309, \
    21, 29, 3645, 13365, \
    2205, 245, 1461, 13149, \
    45, 2189, 1701, 13125, \
    6579, 11, 1459, 13851, \
    19, 731, 8019, 13131, \
    747, 6563, 1467, 13123, \
    13374, 22, 758, 10206, \
    13368, 48, 2216, 3888, \
    13366, 750, 6590, 3654]
    # Possible plays to board situation
    data_moves = \
    [1, 64, 256, 4, \
     16, 16, 16, 16, \
     4, \
     64, 256, 4, 1, \
     4, 1, 64, 256, \
     4, 1, 64, 256, \
     1, 64, 256, 4, \
     1, 64, 256, 4, \
     64, 256, 4, 1, \
     64, 256, 4, 1, \
     256, 4, 1, 64, \
     256, 4, 1, 64, \
     16, 16, 16, 16, \
     16, 16, 16, 16, \
     16, 16, 16, 16, \
     16, 16, 16, 16, \
     256, 4, 1, 64, \
     4, 1, 64, 256, \
     1, 64, 256, 4, \
     2, 8, 128, 32, \
     4, 1, 64, 256, \
     16, 16, 16, 16]
    
    for i in range(8, -1, -1): #See the board in reverse order
        tmp = 0
        if (bool(board[COMPUTER] & (1 << i))):
            tmp = 2
        else:
            tmp = (board[USER]>>i) & 1
        boardValue += tmp * power
        #Convert the bit board to ternary format and then to decimal
        power *= 3 #Increase base size as it goes to higher place value

    for i in range(TOTAL_DATABASE_MOVES-1, -1, -1): #Search the database
        if (data_cases[i] == boardValue): #If the board matches the database
            return data_moves[i]; #Return the best move
  
    return 0 #Else return 0

def attack(player):
    '''
    This function is meant to prevent a completion or do it of a line
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
    '''
    notBoard = ~board[player]
    notBoard_2 = ~board[not(bool(player))]
    index=0

    # Not boards and variables
    lines = [FIRST_ROW, SECOND_ROW, THIRD_ROW, \
             FIRST_COLUMN, SECOND_COLUMN, THIRD_COLUMN, \
             FIRST_DIAGONAL, SECOND_DIAGONAL]
    attackMoves[0] = attackMoves[1] = 0; #Clear array

    for i in range(7, -1, -1):
        attackMove = notBoard & lines[i]; #Calculate attack move
        if (((attackMove & notBoard_2) & (~attackMove+1)) == attackMove):
            #If legal and an attack
            attackMoves[index] = attackMove; #Add to array
            index += 1

ivar = [256, 128, 64, 32, 16, 8, 4, 2, 1]

def doubleAttack(player):
    '''
    This function is meant to prevent or do a double attack
    X|-|O
    -|-|X
    -|-|O
    If user is 'X' and input to the player variable is 0 it will return 4
    If computer is 'O' and input to the player variable is 1 it will return 7
    '''
    index = 0
    doubleAttackMoves[0] = doubleAttackMoves[1] = 0; #Clear array
    twinBoard = ~(board[USER] | board[COMPUTER]);
    #Create a twin board where legal moves are stored
    for i in ivar: #Try all moves
        if (bool(i & twinBoard) == True): #If legal
            board[player] |= i #Try the move
            attack(player) #Check for attacks
            if (bool(attackMoves[0]) and bool(attackMoves[1])): #If there are 2 attacks
                doubleAttackMoves[index] = i #Add in the array
                index += 1
            board[player] &= ~i #Undo the move

def doubleAttack_forcePrevent():
    '''
    This function is meant to force prevent a double attack
    X|-|-
    -|O|-
    -|X|-
    If computer is 'X' it will return 4
    '''
    twinBoard = ~(board[USER] | board[COMPUTER]);
    #Create a twin board where legal moves are stored
    doubleAttack(USER); 
    #Check if the user is going to do a double attack
    if (bool(doubleAttackMoves[0])): #If can
        for i in ivar: #Check all moves
            if (bool(i & twinBoard) == True): #If legal
                board[COMPUTER] |= i #Try the move
                attack(COMPUTER) #Checks if computer forced the user to play something
                '''
                Definitions of which moves to skip -
                *  !attackMoves[0] - If by playing a move computer can't do an attack
                *  doubleAttackMoves[0] == attackMoves[0] -
                    If the reply by the user makes enables the user do a double attack too
                *  doubleAttackMoves[1] && doubleAttackMoves[1]
                                      == attackMoves[0] - Checks if
                there are two possible double attacks by the user and if it is there
                check that if the reply of the attack of the user makes the other
                double attack of the user possible
                '''
                if (not(attackMoves[0]) or \
                    (doubleAttackMoves[0] == attackMoves[0]) or \
                    (doubleAttackMoves[1] and (doubleAttackMoves[1] \
                        == attackMoves[0]))):
                    board[COMPUTER] &= ~i; #Undo the move
                    continue #Go for another move
                board[COMPUTER] &= ~i; #Undo the move
                return i #Return the move, if success to prevent the double attack
    return 0 #return 0 if this function has no use

def playComputer(movesPlayed): #Make the computer choose a move
    attackMoves[0] = 0
    attackMoves[1] = 0
    doubleAttackMoves[0] = 0
    doubleAttackMoves[1] = 0
    bestMove = 0 #Temporary variable for storing the moves
    #Prevents them to call functions again and again
    if (movesPlayed == 0): #If no moves are played
        #To escape the checking of database
        #To escape complex random move playing
        board[COMPUTER] |= 1 << (random.randint(0, 8)); #Play a random move
        return
    if (movesPlayed < 4): #If less than 4 moves are played
        bestMove = database() #Check the database
        if (bool(bestMove)): #If a moves matches the database
            board[COMPUTER] |= bestMove #Do that
            return
    if (movesPlayed > 2): #If more than 2 moves are played
        attack(COMPUTER) #Try if computer could do a line
        if (bool(attackMoves[0])): #If can
            board[COMPUTER] |= attackMoves[0] #Play that
            return
        attack(USER) #If user could do a line
        if (bool(attackMoves[0])): #If can
            board[COMPUTER] |= attackMoves[0] #Block that
            return
    if (movesPlayed > 3): #If more than 3 moves are played
        doubleAttack(COMPUTER) #If could a double attack
        if (bool(doubleAttackMoves[0])): #If can
            board[COMPUTER] |= doubleAttackMoves[0] #Play a double attack
            return
    if (movesPlayed > 2): #If more than 2 moves are played
        bestMove = doubleAttack_forcePrevent()
        #If user can do a double attack
        if (bool(bestMove)): #If can
            board[COMPUTER] |= bestMove #Prevent it
            return

    index = 0
    #Play a random move
    i = 0
    emptyBoard_locations = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    twinBoard = ~(board[USER] | board[COMPUTER])
    #Create a twin board where legal moves are stored  
    for i in ivar: #Search the whole board
        if (bool(twinBoard & i) == True): #If the place is empty
            emptyBoard_locations[index] = i; #Add in the record
            index += 1
    board[COMPUTER] |= emptyBoard_locations[random.randint(0, index-1)];
    #Play random move

def isGameOver(player): #Check if game is over or not
    if (match(board[COMPUTER])): #If computer won
        if (player == 3): #If multi player
            print("User-2 has won!!!\n")
        else:
            print("Computer has won!!!\n")
        return True
    elif (match(board[USER])): #If the board of user own
        if (player == 3): #If multi player
            print("User-1 has won!!!\n")
        else:
            print("User has won!!!\n")
        return True
    else:
        if ((board[USER] | board[COMPUTER]) != 511):
            #If there zero anywhere in or of both bit boards
            return False; #It is not draw
        print("The game is a draw\n")
        return True
    return True

def playUser(player):
    user_input = 0
    twinBoard = ~(board[USER] | board[COMPUTER])
    #Create a twin board where legal moves are stored
    var = 1
    while(var == 1): #Infinite loop
        user_input = int(input()) #Take input using getchar()
        if ((user_input < 1) or (user_input > 9)): #Check if a move in bounds
            continue
        user_input -= 1 #Convert move in 1-9 notation to 0-8 notation
        #If no player had played the move
        if (bool(twinBoard & (1 << user_input))):
            board[player] |= 1 << user_input #Play the move as user
            break

def print_board(): #Print the board
    for i in range(3):
        for j in range(3): #Print each of the piece
            if (bool(board[USER] & 1<<(i*3+j))):
                print("X|", end='')
            elif (bool(board[COMPUTER] & 1<<(i*3+j))):
                print("O|", end='')
            else:
                print("-|", end='')
        '''
        If user played some move return 'X' to printf()
        Else if computer played some move return 'O' to printf()
        Else return '-' to printf()
        '''
        print()
    print();

def gameHandler(player):
    print_board()
    plys = 0
    while (isGameOver(player) == False):
        if (player == 3):
            playUser(plys & 1)
            print_board()
        elif (bool((player + plys) & 1)):
            playUser(0)
            print_board()
        else:
            playComputer(plys)
            print_board()

        plys += 1

print("Tic Tac Toe - AI by Swastik Mozumder, Build - " + str(BUILD) + "%d\n\n")
print("To enter moves, type number from 1 to 9\n\n")
print(" 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 \n\n")
print("Play (with computer) (1)st, (2)nd or play (3)Multiplayer?: ")
var2 = 1
print("================================================\n")
while(var2 == 1): #Infinite loop
    chance = int(input())
    if (chance > 0 and chance < 4): #If valid input
        break
gameHandler(chance) #Run the game
print("Press any key to continue . . . ")
input()


