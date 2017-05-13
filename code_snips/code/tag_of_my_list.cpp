struct my_list_tag { };

template <typename ...T>
struct my_list { };

namespace boost::hana
{
  template<typename ...T>
  struct tag_of<my_list<T...>>
  {
    using type = my_list_tag;
  };
}

static_assert(std::is_same<

  hana::tag_of_t<my_list<int, char, double>>,

  my_list_tag

>::value);
