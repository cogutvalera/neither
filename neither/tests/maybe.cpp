#include <gtest/gtest.h>
#include <neither/neither.hpp>

using namespace neither;

TEST(neither, maybe_with_value) {
  auto x = maybe<int>(42);
  ASSERT_TRUE(x.get(0) == 42);
}

TEST(neither, maybe_without_value) {
  auto x = maybe<int>();
  ASSERT_TRUE(x.get(0) == 0);
}

TEST(neither, maybe_map_value) {
  auto x = maybe<int>(4);
  ASSERT_TRUE(x.map([](auto x) { return 4 * 10 + 2; }).get(0) == 42);
}

TEST(neither, maybe_flatMap_value) {
  auto x = maybe<int>(0);
  ASSERT_TRUE(x.flatMap([](auto x) { return maybe(42); }).get(0) == 42);
}

TEST(neither, maybe_flatMap_no_value) {
  auto x = maybe<int>(42);
  ASSERT_TRUE(x.flatMap([](auto x) { return maybe<int>(); }).get(1) == 1);
}

TEST(neither, maybe_comparison) {

  auto a = maybe<int>(42);
  auto b = maybe<int>(42);
  auto c = maybe<int>(17);
  auto d = maybe<int>();
  auto e = maybe<int>();

  EXPECT_TRUE(a == a);
  EXPECT_TRUE(a == b);
  EXPECT_TRUE(b == a);

  EXPECT_TRUE(a != c);
  EXPECT_TRUE(b != c);
  EXPECT_TRUE(a != d);
  EXPECT_TRUE(b != d);

  EXPECT_TRUE(d == d);
  EXPECT_TRUE(d == e);
}
