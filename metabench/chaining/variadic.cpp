#include <algorithm>
#include <vector>

struct concat_helper_fn
{
  std::vector<int>::iterator itr;

  auto operator()(std::vector<int> const& source)
  {
    std::copy(source.begin(), source.end(), itr);
  }
};

template <typename ...Xs>
auto concat(Xs&& ...xs)
{
  std::size_t target_length = (xs.size() + ... + 0);
  std::vector<int> target{};
  target.reserve(target_length);
  concat_helper_fn concat_helper{target.begin()};
  (concat_helper(std::forward<Xs>(xs)), ...);
  
  return target;
};

int main()
{
#if defined (METABENCH)
  std::vector<int> result = concat(
  <% (0..n).map { |i| "std::vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" }.join(", ") %>
  );
#endif
}
