// My game copyright

#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "Tests/SanboxTests.h"
#include "Tests/TestUtils.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxInt, "TPSGame.Math.MaxInt",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSqrt, "TPSGame.Math.Sqrt",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSin, "TPSGame.Math.Sin",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

using namespace TPS::Test;

bool FMathMaxInt::RunTest(const FString& Parameters)
{

    typedef TArray<TestPayLoad<TInterval<int32>, int32>> MaxIntTestPayLoad;
    // clang-format off
    const MaxIntTestPayLoad TestData 
    {
        {{13, 25}, 25},
        {{25, 25}, 25},
        {{0, 123}, 123},
        {{0, 0}, 0},
        {{-2345, 0}, 0},
        {{-45, -67}, -45},
        {{9, -9}, 9},

    };
    // clang-format on

    for (const auto Data : TestData)
    {
        TestTrueExpr(FMath::Max(Data.TestValue.Min, Data.TestValue.Max) == Data.ExpectedValue);
    }

    return true;
}

bool FMathSqrt::RunTest(const FString& Parameters)
{
    // sqrt(3) = 1.73205

    AddInfo("Sqrt function testing");

    typedef TArray<TestPayLoad<float, float>> SqrtTestPayLoad;

    // clang-format off
    const SqrtTestPayLoad TestData
    {
        {4.0f, 2.0f},
        {3.0f, 1.7f, 0.1f},
        {3.0f, 1.73f, 0.01f},
        {3.0f, 1.73205f, 1.e-5f},
    };
    //clang-format on

    for (const auto Data : TestData)
    {
        const bool IsEqual = FMath::IsNearlyEqual(FMath::Sqrt(Data.TestValue), Data.ExpectedValue, Data.Tolerance);
        TestTrueExpr(IsEqual);
    }

    return true;
}

bool FMathSin::RunTest(const FString& Parameters)
{
    AddInfo("Sin func testing");

    typedef float Degrees;
    typedef TArray<TestPayLoad<Degrees, float>> SinTestPayLoad;

    // clang-format off
    const SinTestPayLoad TestData
    {
        {Degrees{0.00f}, 0.0f},
        {Degrees{30.0f}, 0.5f},
        {Degrees{45.0f}, 0.707f},
        {Degrees{60.0f}, 0.866f},
        {Degrees{90.0f}, 1.0f},
    };
    //clang-format on

    for (const auto Data : TestData)
    {
        const float Rad = FMath::DegreesToRadians(Data.TestValue);
        TestTrueExpr(FMath::IsNearlyEqual(FMath::Sin(Rad), Data.ExpectedValue, 0.001f));
    }

    return true;
}

#endif