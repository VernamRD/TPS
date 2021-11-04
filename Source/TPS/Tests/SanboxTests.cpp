// My game copyright

#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "Tests/SanboxTests.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxInt, "TPSGame.Math.MaxInt",
                                 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
                                     EAutomationTestFlags::HighPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSqrt, "TPSGame.Math.Sqrt",
                                 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
                                     EAutomationTestFlags::HighPriority);

bool FMathMaxInt::RunTest(const FString& Parameters)
{
    AddInfo("Max [int] func testing");
    TestTrue("2 different positive numbers", FMath::Max(13, 25) == 25);
    TestTrue("2 equal positive", FMath::Max(25, 25) == 25);
    TestTrue("zero and positive", FMath::Max(0, 123) == 123);
    TestTrue("2 zeros", FMath::Max(0, 0) == 0);
    TestTrue("zero and negative", FMath::Max(-2351, 0) == 0);
    TestTrue("2 different negative numbers", FMath::Max(-25, -74) == -25);
    TestTrue("2 equal negative numbers", FMath::Max(-9, -9) == -9);
    TestTrue("negative and positive numbers", FMath::Max(9, -9) == 9);

    return true;
}

bool FMathSqrt::RunTest(const FString& Parameters)
{
    // sqrt(3) = 1.73205

    AddInfo("Sqrt function testing");

    TestEqual("Sqrt (4) [0]", FMath::Sqrt(4.0f), 2.0f);
    // TestEqual("Sqrt (3) [1]", FMath::Sqrt(3.0f), 1.7f);
    TestEqual("Sqrt (3) [2]", FMath::Sqrt(3.0f), 1.7f, 0.1f);
    TestEqual("Sqrt (3) [3]", FMath::Sqrt(3.0f), 1.73f, 0.01f);
    TestEqual("Sqrt (3) [4]", FMath::Sqrt(3.0f), 1.73205f, 1.e-5f);
    return true;
}

#endif