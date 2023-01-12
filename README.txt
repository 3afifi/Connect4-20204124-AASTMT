This is the connect 4 project :
it is written in C language
and was compiled and run using visual studio.
the sounds are not there in the GIF file.

the grid has 6 ROWS and 8 COLUMNS
the background color is default black
the grid's color is red
player 1 has the color blue
player 2 has the color green
this is how the grid looks:

+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
  1   2   3   4   5   6   7   8

---------------------------------------------------------------------------------------------------------------------------

there is a character 2D array acts as the actual game working in the background,
and the grid that is printed on the screen is a mirror to the background array.
a structure is made for the players that has(their {name} and their {LETTER})
that LETTER is made to replace empty places in the background 2D array according to
column that the player desires.

there is 8 columns, the players are forced to choose from 1 to 8 only.
if they choose bigger than 8 or less than 1 the game will refuse the input
and will ask for a new input.

the column that the player chooses is equal to the (choice - 1) according to the 2D array so,
if the player chooses column (3) the 2D array takes that input as (3 - 1) = column (index 2)

If it is the first player's turn the space will be replaced by an 'X'
X = blue token (0)
if it is the second player's turn the space will be replaced by an 'O'
O = green token (0)
if either of them chooses a full column the game will refuse to take the input 
and will ask to enter a new column.

after they choose the column for every turn the game checks for a win,
which has four conditions, one of the players only needs to have four of their 
tokens right next to each other in only one of these conditions:
1-diagonally

+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
| 0 |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   | 0 |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   | 0 |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | 0 |   |   |   |   |
+---+---+---+---+---+---+---+---+
  1   2   3   4   5   6   7   8

2-reverse diagonally

+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   | 0 |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   | 0 |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   | 0 |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   | 0 |   |   |   |
+---+---+---+---+---+---+---+---+
  1   2   3   4   5   6   7   8

3-Horizontal

+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 0 |   |   |   |   |
+---+---+---+---+---+---+---+---+
  1   2   3   4   5   6   7   8

4-vertical

+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | 0 |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | 0 |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | 0 |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | 0 |   |   |   |   |
+---+---+---+---+---+---+---+---+
  1   2   3   4   5   6   7   8


after the game is done and the Winner had been declared; the game asks the player kindly to 
enter any character to get back to the main menu which the player has only two options either
enter a new game or quit game.


---------------------------------------------------------------------------------------------------------------------------

unfortunately,the PlaySound() function doesn't support playing 2 sounds at the same time so,
i could not have a background music to the game

