#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("vector_initialization", "[vec]") {
  Vec2 a;
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  Vec2 b{5.1f, -9.3f};
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
  a+=b;
} 

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
