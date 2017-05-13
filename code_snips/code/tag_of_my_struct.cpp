struct my_struct { };

static_assert(std::is_same<

  hana::tag_of_t<my_struct>,

  my_struct

>::value);
