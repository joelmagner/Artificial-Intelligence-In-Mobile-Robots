//=============================================================================
//fuzzy.h
//=============================================================================
#ifndef fuzzy_h_DEFINED
#define fuzzy_h_DEFINED
//=============================================================================


//=============================================================================
//Includes
//=============================================================================
#include <stdio.h>
//=============================================================================


//=============================================================================
//Defines
//=============================================================================
#define DEFBEHAVIOUR(x) void x (void)
#define F_SET_SIZE 4

#define RULESET
#define RULEEND

// Predicates
#define LEFT  0
#define AHEAD 1
#define RIGHT 2

#define BACK 0
#define NONE 1
#define SLOW 2
#define FAST 3

//Macros
#define MIN(x,y)      (((x) > (y)) ? (y) : (x))
#define MAX(x,y)      (((x) < (y)) ? (y) : (x))
//=============================================================================


//=============================================================================
//Structures
//=============================================================================
//Fuzzy types
typedef double FPred;
typedef void (*FBehaviour) (void);
typedef double FSet[F_SET_SIZE];
//=============================================================================


//=============================================================================
// Global variables
//=============================================================================
//Fuzzy predicate
extern FPred ante;

//Control values
extern double f_vlin;
extern double f_vrot;

//Fuzzy sets
extern FSet f_set_vlin;
extern FSet f_set_vrot;
//=============================================================================


//=============================================================================
//Function prototypes
//=============================================================================


//=============================================================================
//Ramp functions
//=============================================================================
FPred RampUp(double Value, double RampStart, double RampEnd);
FPred RampDown(double Value, double RampStart, double RampEnd);
//=============================================================================


//=============================================================================
// Possibilistic logical functions
//=============================================================================
FPred AND (FPred a, FPred b);
FPred OR  (FPred a, FPred b);
FPred NOT (FPred a);
void IF(FPred a);
//=============================================================================


//=============================================================================
//Control values
//=============================================================================
void ROT (int rot);
void VEL (int vel);
//=============================================================================


//=============================================================================
//Behaviour functions
//=============================================================================
void RunBehaviour(FBehaviour behaviour);
void SetFSet(FSet fset);
void ClearFSet(FSet fset);
void DeFuzzify(FSet fset, int size, double* result);
//=============================================================================


//=============================================================================
#endif //#ifndef fuzzy_h_DEFINED
//=============================================================================
