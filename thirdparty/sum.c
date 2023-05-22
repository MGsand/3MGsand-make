#include <../../src/lib/circle.h>
#include "ctest.h"
#define pi 3.14159265358979323846
CTEST(circle_test, circle)
{
        double a, b, r=4;
    
    circle( r, &a, &b);

    double expected_p = pi * 2 * r;
    double expected_a = pi * r * r;

    // Then
   
   ASSERT_DBL_NEAR_TOL(expected_a, a, 0.002);
   ASSERT_DBL_NEAR_TOL(expected_p, b, 0.1);
}


/*void ssum(double r, double* area_num, double* perimetr)
{
    int 
    *area_num = pi * r * r;
    *perimetr = 2 * pi * r;

    ASSERT_EQUAL(*perimetr, 20);
    ASSERT_EQUAL(*area_num, 40);
}*/
