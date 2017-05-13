static_assert(std::is_same<

  hana::tag_of_t<hana::tuple<int, char, double>>,

  hana::tuple_tag

>::value);
