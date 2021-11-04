// My game copyright

#include "Science/ScienceFuncLib.h"

DEFINE_LOG_CATEGORY_STATIC(LogScience, All, All);

int32 UScienceFuncLib::Fibonacci(int32 Value)
{
    // check negative value on input
    if (Value < 0)
    {
        UE_LOG(LogScience, Error, TEXT("Invalid input for Fibonacci: %i"), Value)
    }
    // recursion calculate
    return Value <= 1 ? Value : Fibonacci(Value - 1) + Fibonacci(Value - 2);
}