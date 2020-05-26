#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <cmath>

//Test initialization of Vec2
TEST_CASE("vector_initialization", "[vec2]") {
  Vec2 a;
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  Vec2 b{5.1f, -9.3f};
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
} 

//Test Vec2 methods and functions
TEST_CASE("vector_operations", "[vec2]") {
  Vec2 a;
  Vec2 b{1, 1};
  Vec2 c{-1, -1};
  Vec2 d{-9.9, 3.2};
  Vec2 e{8.3, -1.75};
  // Test operator+
  REQUIRE(Approx(1.0f) == (a+b).x);
  REQUIRE(Approx(1.0f) == (a+b).y);
  REQUIRE(Approx(0.0f) == (b+c).x);
  REQUIRE(Approx(0.0f) == (b+c).y);
  REQUIRE(Approx(-10.9f) == (c+d).x);
  REQUIRE(Approx(2.2f) == (c+d).y);
  REQUIRE(Approx(-1.6f) == (d+e).x);
  REQUIRE(Approx(1.45f) == (d+e).y);
  // Test operator-
  REQUIRE(Approx(-1.0f) == (a-b).x);
  REQUIRE(Approx(-1.0f) == (a-b).y);
  REQUIRE(Approx(2.0f) == (b-c).x);
  REQUIRE(Approx(2.0f) == (b-c).y);
  REQUIRE(Approx(8.9f) == (c-d).x);
  REQUIRE(Approx(-4.2f) == (c-d).y);
  REQUIRE(Approx(-18.2f) == (d-e).x);
  REQUIRE(Approx(4.95f) == (d-e).y);
  // Test operator*
  float s1 = 0.0f, s2 = 1.0f, s3 = -1.0f, s4 = 14.32f;
  // Scaling from the right side
  REQUIRE(Approx(0.0f) == (a*s1).x);    // Scaling Vec2 a
  REQUIRE(Approx(0.0f) == (a*s1).y);
  REQUIRE(Approx(0.0f) == (a*s2).x);
  REQUIRE(Approx(0.0f) == (a*s2).y);
  REQUIRE(Approx(0.0f) == (a*s3).x);
  REQUIRE(Approx(0.0f) == (a*s3).y);
  REQUIRE(Approx(0.0f) == (a*s4).x);
  REQUIRE(Approx(0.0f) == (a*s4).y);
  REQUIRE(Approx(0.0f) == (b*s1).x);    // Scaling Vec2 b
  REQUIRE(Approx(0.0f) == (b*s1).y);
  REQUIRE(Approx(1.0f) == (b*s2).x);
  REQUIRE(Approx(1.0f) == (b*s2).y);
  REQUIRE(Approx(-1.0f) == (b*s3).x);
  REQUIRE(Approx(-1.0f) == (b*s3).y);
  REQUIRE(Approx(14.32f) == (b*s4).x);
  REQUIRE(Approx(14.32f) == (b*s4).y);  
  REQUIRE(Approx(0.0f) == (c*s1).x);  // Scaling Vec2 c
  REQUIRE(Approx(0.0f) == (c*s1).y);   
  REQUIRE(Approx(-1.0f) == (c*s2).x);
  REQUIRE(Approx(-1.0f) == (c*s2).y);
  REQUIRE(Approx(1.0f) == (c*s3).x);
  REQUIRE(Approx(1.0f) == (c*s3).y);
  REQUIRE(Approx(-14.32f) == (c*s4).x);
  REQUIRE(Approx(-14.32f) == (c*s4).y);   
  REQUIRE(Approx(0.0f) == (d*s1).x);  // Scaling Vec2 d
  REQUIRE(Approx(0.0f) == (d*s1).y);   
  REQUIRE(Approx(-9.9f) == (d*s2).x);
  REQUIRE(Approx(3.2f) == (d*s2).y);
  REQUIRE(Approx(9.9f) == (d*s3).x);
  REQUIRE(Approx(-3.2f) == (d*s3).y);
  REQUIRE(Approx(-141.768f) == (d*s4).x);
  REQUIRE(Approx(45.824f) == (d*s4).y); 
  REQUIRE(Approx(0.0f) == (e*s1).x);  // Scaling Vec2 e
  REQUIRE(Approx(0.0f) == (e*s1).y);   
  REQUIRE(Approx(8.3f) == (e*s2).x);
  REQUIRE(Approx(-1.75f) == (e*s2).y);
  REQUIRE(Approx(-8.3f) == (e*s3).x);
  REQUIRE(Approx(1.75f) == (e*s3).y);
  REQUIRE(Approx(118.856f) == (e*s4).x);
  REQUIRE(Approx(-25.06f) == (e*s4).y); 
  // Scaling from the left side
  REQUIRE(Approx(0.0f) == (s1*a).x);    // Scaling Vec2 a
  REQUIRE(Approx(0.0f) == (s1*a).y);
  REQUIRE(Approx(0.0f) == (s2*a).x);
  REQUIRE(Approx(0.0f) == (s2*a).y);
  REQUIRE(Approx(0.0f) == (s3*a).x);
  REQUIRE(Approx(0.0f) == (s3*a).y);
  REQUIRE(Approx(0.0f) == (s4*a).x);
  REQUIRE(Approx(0.0f) == (s4*a).y);
  REQUIRE(Approx(0.0f) == (s1*b).x);    // Scaling Vec2 b
  REQUIRE(Approx(0.0f) == (s1*b).y);
  REQUIRE(Approx(1.0f) == (s2*b).x);
  REQUIRE(Approx(1.0f) == (s2*b).y);
  REQUIRE(Approx(-1.0f) == (s3*b).x);
  REQUIRE(Approx(-1.0f) == (s3*b).y);
  REQUIRE(Approx(14.32f) == (s4*b).x);
  REQUIRE(Approx(14.32f) == (s4*b).y);  
  REQUIRE(Approx(0.0f) == (s1*c).x);  // Scaling Vec2 c
  REQUIRE(Approx(0.0f) == (s1*c).y);   
  REQUIRE(Approx(-1.0f) == (s2*c).x);
  REQUIRE(Approx(-1.0f) == (s2*c).y);
  REQUIRE(Approx(1.0f) == (s3*c).x);
  REQUIRE(Approx(1.0f) == (s3*c).y);
  REQUIRE(Approx(-14.32f) == (s4*c).x);
  REQUIRE(Approx(-14.32f) == (s4*c).y);   
  REQUIRE(Approx(0.0f) == (s1*d).x);  // Scaling Vec2 d
  REQUIRE(Approx(0.0f) == (s1*d).y);   
  REQUIRE(Approx(-9.9f) == (s2*d).x);
  REQUIRE(Approx(3.2f) == (s2*d).y);
  REQUIRE(Approx(9.9f) == (s3*d).x);
  REQUIRE(Approx(-3.2f) == (s3*d).y);
  REQUIRE(Approx(-141.768f) == (s4*d).x);
  REQUIRE(Approx(45.824f) == (s4*d).y); 
  REQUIRE(Approx(0.0f) == (s1*e).x);  // Scaling Vec2 e
  REQUIRE(Approx(0.0f) == (s1*e).y);   
  REQUIRE(Approx(8.3f) == (s2*e).x);
  REQUIRE(Approx(-1.75f) == (s2*e).y);
  REQUIRE(Approx(-8.3f) == (s3*e).x);
  REQUIRE(Approx(1.75f) == (s3*e).y);
  REQUIRE(Approx(118.856f) == (s4*e).x);
  REQUIRE(Approx(-25.06f) == (s4*e).y); 
  // Testing operator/
  REQUIRE(Approx(0.0f) == (a/s1).x);    // Vec2 a
  REQUIRE(Approx(0.0f) == (a/s1).y);
  REQUIRE(Approx(0.0f) == (a/s2).x);
  REQUIRE(Approx(0.0f) == (a/s2).y);
  REQUIRE(Approx(0.0f) == (a/s2).x);
  REQUIRE(Approx(0.0f) == (a/s3).y);
  REQUIRE(Approx(0.0f) == (a/s3).x);
  REQUIRE(Approx(0.0f) == (a/s4).y);
  REQUIRE(Approx(1.0f) == (b/s1).x);    //  Vec2 b
  REQUIRE(Approx(1.0f) == (b/s1).y);
  REQUIRE(Approx(1.0f) == (b/s2).x);
  REQUIRE(Approx(1.0f) == (b/s2).y);
  REQUIRE(Approx(-1.0f) == (b/s3).x);
  REQUIRE(Approx(-1.0f) == (b/s3).y);
  REQUIRE(Approx(0.06983f) == (b/s4).x);
  REQUIRE(Approx(0.06983f) == (b/s4).y);  
  REQUIRE(Approx(-1.0f) == (c/s1).x);  // Scaling Vec2 c
  REQUIRE(Approx(-1.0f) == (c/s1).y);   
  REQUIRE(Approx(-1.0f) == (c/s2).x);
  REQUIRE(Approx(-1.0f) == (c/s2).y);
  REQUIRE(Approx(1.0f) == (c/s3).x);
  REQUIRE(Approx(1.0f) == (c/s3).y);
  REQUIRE(Approx(-0.06983f) == (c/s4).x);
  REQUIRE(Approx(-0.06983f) == (c/s4).y);   
  REQUIRE(Approx(-9.9f) == (d/s1).x);  // Scaling Vec2 d
  REQUIRE(Approx(3.2f) == (d/s1).y);   
  REQUIRE(Approx(-9.9f) == (d/s2).x);
  REQUIRE(Approx(3.2f) == (d/s2).y);
  REQUIRE(Approx(9.9f) == (d/s3).x);
  REQUIRE(Approx(-3.2f) == (d/s3).y);
  REQUIRE(Approx(-0.69134f) == (d/s4).x);
  REQUIRE(Approx(0.22346f) == (d/s4).y); 
  REQUIRE(Approx(8.3f) == (e/s1).x);  // Scaling Vec2 e
  REQUIRE(Approx(-1.75f) == (e/s1).y);   
  REQUIRE(Approx(8.3f) == (e/s2).x);
  REQUIRE(Approx(-1.75f) == (e/s2).y);
  REQUIRE(Approx(-8.3f) == (e/s3).x);
  REQUIRE(Approx(1.75f) == (e/s3).y);
  REQUIRE(Approx(0.57961f) == (e/s4).x);
  REQUIRE(Approx(-0.12221f) == (e/s4).y); 
  // Testing operator+=
  a += b;  
  b += c;
  c += d;
  d += e;
  REQUIRE(Approx(1.0f) == a.x);
  REQUIRE(Approx(1.0f) == a.y);
  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y);
  REQUIRE(Approx(-10.9f) == c.x);
  REQUIRE(Approx(2.2f) == c.y);
  REQUIRE(Approx(-1.6f) == d.x);
  REQUIRE(Approx(1.45f) == d.y);
  // Testing operator -=
  // This restores the original values
  d -= e;
  c -= d;
  b -= c;
  a -= b;    
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(1.0f) == b.x);
  REQUIRE(Approx(1.0f) == b.y);
  REQUIRE(Approx(-1.0f) == c.x);
  REQUIRE(Approx(-1.0f) == c.y);
  REQUIRE(Approx(-9.9f) == d.x);
  REQUIRE(Approx(3.2f) == d.y);
 // Testing operator*=
 // with s2 = 1
  a *= s2;  
  b *= s2;
  c *= s2;
  d *= s2;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(1.0f) == b.x);
  REQUIRE(Approx(1.0f) == b.y);
  REQUIRE(Approx(-1.0f) == c.x);
  REQUIRE(Approx(-1.0f) == c.y);
  REQUIRE(Approx(-9.9f) == d.x);
  REQUIRE(Approx(3.2f) == d.y);
  // Testing operator /=
  // with s2 = 1
  d /= s2;
  c /= s2;
  b /= s2;
  a /= s2;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(1.0f) == b.x);
  REQUIRE(Approx(1.0f) == b.y);
  REQUIRE(Approx(-1.0f) == c.x);
  REQUIRE(Approx(-1.0f) == c.y);
  REQUIRE(Approx(-9.9f) == d.x);
  REQUIRE(Approx(3.2f) == d.y);
  // Testing operator*=
  // with s = -1
  a *= s3;  
  b *= s3;
  c *= s3;
  d *= s3;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(-1.0f) == b.x);
  REQUIRE(Approx(-1.0f) == b.y);
  REQUIRE(Approx(1.0f) == c.x);
  REQUIRE(Approx(1.0f) == c.y);
  REQUIRE(Approx(9.9f) == d.x);
  REQUIRE(Approx(-3.2f) == d.y);
  // Testing operator/=
  // with s3 = -1
  d /= s3;
  c /= s3;
  b /= s3;
  a /= s3;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(1.0f) == b.x);
  REQUIRE(Approx(1.0f) == b.y);
  REQUIRE(Approx(-1.0f) == c.x);
  REQUIRE(Approx(-1.0f) == c.y);
  REQUIRE(Approx(-9.9f) == d.x);
  REQUIRE(Approx(3.2f) == d.y);
  // Testing operator*=
  // with s4 = 14.32
  a *= s4;  
  b *= s4;
  c *= s4;
  d *= s4;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(14.32f) == b.x);
  REQUIRE(Approx(14.32f) == b.y);
  REQUIRE(Approx(-14.32f) == c.x);
  REQUIRE(Approx(-14.32f) == c.y);
  REQUIRE(Approx(-141.768f) == d.x);
  REQUIRE(Approx(45.824f) == d.y); 
  // Testing operator/=
  // with s4 = 14.32
  d /= s4;
  c /= s4;
  b /= s4;
  a /= s4;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(1.0f) == b.x);
  REQUIRE(Approx(1.0f) == b.y);
  REQUIRE(Approx(-1.0f) == c.x);
  REQUIRE(Approx(-1.0f) == c.y);
  REQUIRE(Approx(-9.9f) == d.x);
  REQUIRE(Approx(3.2f) == d.y);
  // Testing operator *=
  // with s1 = 0
  a *= s1;  
  b *= s1;
  c *= s1;
  d *= s1;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y);
  REQUIRE(Approx(0.0f) == c.x);
  REQUIRE(Approx(0.0f) == c.y);
  REQUIRE(Approx(0.0f) == d.x);
  REQUIRE(Approx(0.0f) == d.y); 
  // Testing operator /=
  // with s1 = 0
  // It is expected to return the original value of a, b, c and d, which is now (0, 0)
  d /= s1;
  c /= s1;
  b /= s1;
  a /= s1;
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y);
  REQUIRE(Approx(0.0f) == c.x);
  REQUIRE(Approx(0.0f) == c.y);
  REQUIRE(Approx(0.0f) == d.x);
  REQUIRE(Approx(0.0f) == d.y); 
} 

// Test the methods and functions of Mat2
TEST_CASE("mat2 functionality", "[mat2]") {
  Mat2 I; // identity
  Mat2 zero{0.0, 0.0, 0.0, 0.0};
  Mat2 neg{-1.0, 0.0, 0.0, -1.0}; // negative identity
  Mat2 random{3.0, 6.0, 7.0, 2.0};
  // test operator *=
  random *= I;
  zero *= random;
  neg *= I;
  REQUIRE(Approx(3.0) == random.e_00);
  REQUIRE(Approx(6.0) == random.e_10);
  REQUIRE(Approx(7.0) == random.e_01);
  REQUIRE(Approx(2.0) == random.e_11);
  REQUIRE(Approx(0.0) == zero.e_00);
  REQUIRE(Approx(0.0) == zero.e_10);
  REQUIRE(Approx(0.0) == zero.e_01);
  REQUIRE(Approx(0.0) == zero.e_11);
  REQUIRE(Approx(-1.0) == neg.e_00);
  REQUIRE(Approx(0.0) == neg.e_10);
  REQUIRE(Approx(0.0) == neg.e_01);
  REQUIRE(Approx(-1.0) == neg.e_11);
  //test operator* for matrices
  random = random*I;
  zero = zero*random;
  neg = neg*I;
  REQUIRE(Approx(3.0) == random.e_00);
  REQUIRE(Approx(6.0) == random.e_10);
  REQUIRE(Approx(7.0) == random.e_01);
  REQUIRE(Approx(2.0) == random.e_11);
  REQUIRE(Approx(0.0) == zero.e_00);
  REQUIRE(Approx(0.0) == zero.e_10);
  REQUIRE(Approx(0.0) == zero.e_01);
  REQUIRE(Approx(0.0) == zero.e_11);
  REQUIRE(Approx(-1.0) == neg.e_00);
  REQUIRE(Approx(0.0) == neg.e_10);
  REQUIRE(Approx(0.0) == neg.e_01);
  REQUIRE(Approx(-1.0) == neg.e_11);
  // test operator* for a matrix and a vector
  Vec2 o;
  Vec2 a{1.0, 0.0};
  Vec2 b{0.0, 1.0};
  Vec2 c{-1.0, 0.0};
  Vec2 d{0.0, -1.0};
  o = I*o;
  a = I*a;
  b = I*b;
  c = I*c;
  d = I*d;
  REQUIRE(Approx(0.0) == o.x);
  REQUIRE(Approx(0.0) == o.y);
  REQUIRE(Approx(1.0) == a.x);
  REQUIRE(Approx(0.0) == a.y);
  REQUIRE(Approx(0.0) == b.x);
  REQUIRE(Approx(1.0) == b.y);
  REQUIRE(Approx(-1.0) == c.x);
  REQUIRE(Approx(0.0) == c.y);
  REQUIRE(Approx(0.0) == d.x);
  REQUIRE(Approx(-1.0) == d.y);
  o = neg*o;
  a = neg*a;
  b = neg*b;
  c = neg*c;
  d = neg*d;
  REQUIRE(Approx(0.0) == o.x);
  REQUIRE(Approx(0.0) == o.y);
  REQUIRE(Approx(-1.0) == a.x);
  REQUIRE(Approx(0.0) == a.y);
  REQUIRE(Approx(0.0) == b.x);
  REQUIRE(Approx(-1.0) == b.y);
  REQUIRE(Approx(1.0) == c.x);
  REQUIRE(Approx(0.0) == c.y);
  REQUIRE(Approx(0.0) == d.x);
  REQUIRE(Approx(1.0) == d.y);
  // restore the values by multiplying again
  o = neg*o;
  a = neg*a;
  b = neg*b;
  c = neg*c;
  d = neg*d;
  // test determinant
  REQUIRE(Approx(1.0) == I.det());
  REQUIRE(Approx(0.0) == zero.det());
  REQUIRE(Approx(1.0) == neg.det());
  REQUIRE(Approx(-36.0) == random.det());
  // test inverse
  Mat2 I_inv = inverse(I);
  Mat2 zero_inv = inverse(zero);
  Mat2 neg_inv = inverse(neg);
  Mat2 random_inv = inverse(random);
  REQUIRE(Approx(1.0) == I_inv.e_00);
  REQUIRE(Approx(0.0) == I_inv.e_10);
  REQUIRE(Approx(0.0) == I_inv.e_01);
  REQUIRE(Approx(1.0) == I_inv.e_11);
  REQUIRE(Approx(-0.05555f) == random_inv.e_00);
  REQUIRE(Approx(0.166666f) == random_inv.e_10);
  REQUIRE(Approx(0.194444f) == random_inv.e_01);
  REQUIRE(Approx(-0.083333f) == random_inv.e_11);
  REQUIRE(Approx(1.0) == zero_inv.e_00);
  REQUIRE(Approx(0.0) == zero_inv.e_10);
  REQUIRE(Approx(0.0) == zero_inv.e_01);
  REQUIRE(Approx(1.0) == zero_inv.e_11);
  REQUIRE(Approx(-1.0) == neg_inv.e_00);
  REQUIRE(Approx(0.0) == neg_inv.e_10);
  REQUIRE(Approx(0.0) == neg_inv.e_01);
  REQUIRE(Approx(-1.0) == neg_inv.e_11);
  //test transpose
  Mat2 I_transpose = transpose(I);
  Mat2 zero_transpose = transpose(zero);
  Mat2 neg_transpose = transpose(neg);
  Mat2 random_transpose = transpose(random);
  REQUIRE(Approx(1.0) == I_transpose.e_00);
  REQUIRE(Approx(0.0) == I_transpose.e_10);
  REQUIRE(Approx(0.0) == I_transpose.e_01);
  REQUIRE(Approx(1.0) == I_transpose.e_11);
  REQUIRE(Approx(3.0) == random_transpose.e_00);
  REQUIRE(Approx(7.0) == random_transpose.e_10);
  REQUIRE(Approx(6.0) == random_transpose.e_01);
  REQUIRE(Approx(2.0) == random_transpose.e_11);
  REQUIRE(Approx(0.0) == zero_transpose.e_00);
  REQUIRE(Approx(0.0) == zero_transpose.e_10);
  REQUIRE(Approx(0.0) == zero_transpose.e_01);
  REQUIRE(Approx(0.0) == zero_transpose.e_11);
  REQUIRE(Approx(-1.0) == neg_transpose.e_00);
  REQUIRE(Approx(0.0) == neg_transpose.e_10);
  REQUIRE(Approx(0.0) == neg_transpose.e_01);
  REQUIRE(Approx(-1.0) == neg_transpose.e_11);
  // test rotation matrix
  Mat2 rotate_90 = make_rotation_mat2(M_PI/2);
  a = rotate_90*a;
  b = rotate_90*b;
  c = rotate_90*c;
  d = rotate_90*d;
  REQUIRE(Approx(0.0) == a.x);
  REQUIRE(Approx(1.0) == a.y);
  REQUIRE(Approx(-1.0) == b.x);
  REQUIRE(Approx(0.0) == b.y);
  REQUIRE(Approx(0.0) == c.x);
  REQUIRE(Approx(-1.0) == c.y);
  REQUIRE(Approx(1.0) == d.x);
  REQUIRE(Approx(0.0) == d.y);
}
// test color.hpp
TEST_CASE("color", "[color]") {
  Color clr;
  Color red{1.0, 0.0, 0.0};
  Color blue{0.0, 1.0, 0.0};
  Color green{0.0, 0.0, 1.0};
  REQUIRE(Approx(0.5) == clr.r);
  REQUIRE(Approx(0.5) == clr.b);
  REQUIRE(Approx(0.5) == clr.g);
  REQUIRE(Approx(1.0) == red.r);
  REQUIRE(Approx(0.0) == red.g);
  REQUIRE(Approx(0.0) == red.b);
  REQUIRE(Approx(0.0) == blue.r);
  REQUIRE(Approx(1.0) == blue.b);
  REQUIRE(Approx(0.0) == blue.g);
  REQUIRE(Approx(0.0) == green.r);
  REQUIRE(Approx(0.0) == green.b);
  REQUIRE(Approx(1.0) == green.g);
  }

// test the method circumfrence for class Circle
TEST_CASE("circle circumfrence", "[circle]") {
  Circle c{100.0, {0, 0}, {}};
  Circle c2{-100.0, {0, 0}, {}};
  Circle c3{345.0, {0, 0}, {}};
  Circle c4{0.0, {0, 0}, {}};
  REQUIRE(Approx(2*M_PI*100.0) == c.circumfrence());
  REQUIRE(Approx(2*M_PI*-100.0) == c2.circumfrence());
  REQUIRE(Approx(2*M_PI*345.0) == c3.circumfrence());
  REQUIRE(Approx(2*M_PI*0.0) == c4.circumfrence());
}

// test the method circumfrence for class Rectangle
TEST_CASE("rectangle circumfrence", "[rectangle]") {
  Rectangle rec;
  Rectangle rec2{{234.0, 174.0}, {315.0, 834.0}, {}};
  Rectangle rec3{{-234.0, -174.0}, {-315.0, -834.0}, {}};
  Rectangle rec4{{40.0, -17.0}, {50.0, 20.0}, {}};
  Rectangle rec5{{-40.0, 17.0}, {50.0, 20.0}, {}};
  REQUIRE(Approx(400.0) == rec.circumfrence());
  REQUIRE(Approx(1482.0) == rec2.circumfrence());
  REQUIRE(Approx(1482.0) == rec3.circumfrence());
  REQUIRE(Approx(94.0) == rec4.circumfrence());
  REQUIRE(Approx(186.0) == rec5.circumfrence());
}

// Test the method is_inside for class Circle
TEST_CASE("is_inside circle", "[circle]") {
  Circle c1{100.0, {0, 0}, {}};
  Vec2 p1{};
  Vec2 p2{101.0, 0.0};
  REQUIRE(c1.is_inside(p1));
  REQUIRE(c1.is_inside(p2) == false);
}

// Test the method is_inside for class Rectangle
TEST_CASE("is_inside rectangle", "[rectangle]") {
  Rectangle r1{{0, 0}, {100.0, 100.0}, {}};
  Vec2 p1{50.0, 50.0};
  Vec2 p2{101.0, 0.0};
  Vec2 p3{0.0, 101.0};
  Vec2 p4;
  REQUIRE(r1.is_inside(p1));
  REQUIRE(r1.is_inside(p2) == false);
  REQUIRE(r1.is_inside(p3) == false);
  REQUIRE(r1.is_inside(p4) == false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
