#include <algorithm>
#include <vector>

auto operator|(std::vector<int> const& x, std::vector<int> const& y)
{
  std::size_t target_length = x.size() + y.size();
  std::vector<int> target{};
  target.reserve(target_length);

  // weird backwards nesting
  std::copy(y.begin(), y.end(),
  std::copy(x.begin(), x.end(),
  target.begin()
  ));

  return target;
};

int main()
{
#if defined (METABENCH)
  std::vector<int> result =
  <%= (0..n).map { |i| "std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9} " }.join("\n| ") %>
  ;
#endif
}
