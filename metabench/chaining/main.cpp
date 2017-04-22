<% if env[:use_crtp] %>
template <typename Impl>
struct plus_base
{
  auto plus()
  {
    return static_cast<Impl>(*this).x + static_cast<Impl>(*this).y;
  }
};

struct pair : plus_base<pair>
{
  int x;
  int y;
};

template <typename Value>
auto plus(Value value)
{
  return value.plus();
}

<% else %>

struct pair
{
  int x;
  int y;
};

template <typename T>
struct plus_impl
{
  template <typename Value>
  static auto apply(Value value)
  {
    return value.x + value.y;
  }
};

template <typename Value>
auto plus(Value value)
{
  return plus_impl<Value>::apply(value);
}
<% end %>



int main() {
#if defined(METABENCH)
  <% (0..n).map { |i|
    "int x#{i} = plus(pair{#{i}, #{i}}{});"
     }.join('; ')
  %>
#endif
}
