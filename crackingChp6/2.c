/*
 *  There is an 8x8 chess board in which two diagonally opposite corners have been cut off. 
 *  You are given 31 dominos, and a single domino can cover exactly two squares. 
 *  Can you use the 31 dominos to cover the entire board? 
 *  Prove your answer (by providing an example, or showing why it’s impossible).
 */

/*
 *  impossible because the shoert sides are uneven (odd) that makes the long sides to be uneven (takes out one cell)
 *  We cannot compensate the unevenness from both sides as they are shifted by 1.
 */

/*
 *  You have a five quart jug and a three quart jug, and an unlimited supply of water (but no measuring cups). 
 *  How would you come up with exactly four quarts of water?
 *  NOTE: The jugs are oddly shaped, such that filling up exactly ‘half’ of the jug would be impossible.
 *
 *  1. take 3 full and pour into 5.
 *  2. take another 3 and pour into 5 until the 5 is full.
 *  3. empty the 5 and pour into it the rest of the 3 - 1.
 *  4. take 3 full and add to 5 - 4;
 */


/*
 *  A bunch of men are on an island. A genie comes down and gathers everyone together and places a magical hat 
 *  on some people’s heads (i.e., at least one person has a hat). The hat is magical: it can be seen by other people, 
 *  but not by the wearer of the hat himself. 
 *  To remove the hat, those (and only those who have a hat) must dunk themselves underwater at exactly midnight. 
 *  If there are n people and c hats, how long does it take the men to remove the hats? 
 *  The men cannot tell each other (in any way) that they have a hat.
 *  FOLLOW UP
 *  Prove that your solution is correct.
 *  What if the men who don't have a hat will see the hat(s) and think they have the hats as well and come swimming?
 */

/*
 *  There is a building of 100 floors. If an egg drops from the Nth floor or above it will break. 
 *  If it’s dropped from any floor below, it will not break. You’re given 2 eggs. 
 *  Find N, while minimizing the number of drops for the worst case.
 *
 *  1.Drop 1 egg from the 1st floor.
 *  2.If it does not break dropt it fromt the 2 * (i-1) floor.a
 *  3. if it breaks start dropping the second egg floor by floor starting from the last undreaking floor.
 */

/*
 *  There are one hundred closed lockers in a hallway. 
 *  A man begins by opening all one hundred lockers. 
 *  Next, he closes every second locker. 
 *  Then he goes to every third locker and closes it if it is open or opens it if it is closed 
 *  (e.g., he toggles every third locker). 
 *  After his one hundredth pass in the hallway, in which he toggles only locker number one hundred, how many lockers are open?
 */
