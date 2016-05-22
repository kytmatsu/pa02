/* intList.h
Header file for intList.c
 kytmatsu
 Kyle Matsumoto
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * The precondition(s) are they all take in an IntList as their arg.
 * The postcondition for intFirst is that it returns an int.
 * The postcondittion for intRest is that is returns an IntList.
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
 * The precondition(s) is that it takes in an IntList as its arg as well as an int.
 * The post condition for intCons is that it returns an IntList.
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif
