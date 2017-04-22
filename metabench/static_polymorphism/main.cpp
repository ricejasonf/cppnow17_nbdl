template <int i>
struct int_ { };

<% if env[:use_crtp] %>
template <typename Impl>
struct sum_base
{
  auto sum()
  {
    return (*static_cast<Impl*>(this))
      .unpack([](auto ...xs) { return (xs + ... + 0); });
  }
};

template <typename ...Ts>
struct pair : sum_base<pair<Ts...>>
{
  int x;
  int y;

  pair(int x, int y)
    : x(x)
    , y(y)
  { }

  template <typename Fn>
  auto unpack(Fn fn)
  {
    return fn(x, y);
  }
};

template <typename Value>
auto sum(Value value)
{
  return value.sum();
}

<% else %>

template <typename ...Ts>
struct pair
{
  int x;
  int y;
};

template <typename T>
struct unpack_impl;

template <typename ...Ts>
struct unpack_impl<pair<Ts...>>
{
  template <typename Value, typename Fn>
  static auto apply(Value const& v, Fn fn)
  {
    return fn(v.x, v.y);
  }
};

template <typename Value>
auto sum(Value value)
{
  return unpack_impl<Value>::apply(value, [](auto... xs) { return (xs + ... + 0 ); });
}
<% end %>



int main() {
#if defined(METABENCH)
  <% (0..n).map { |i| %>
    int x<%= i %> = sum(pair<
      <%= (0..i).map { |j| "int_<#{j}>" }.join(', ') %>
    >{4, 2});
  <% } %>
#endif
}
