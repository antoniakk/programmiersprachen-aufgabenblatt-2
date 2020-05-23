#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("vector_initialization", "[vec2]") {
  Vec2 a;
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  Vec2 b{5.1f, -9.3f};
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
} 


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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
