auto name_first = hana::type_c<name_first_t>;

auto store = hana::make_tuple(name_first_t{"John"}, name_last_t{"Smith"});

nbdl::match(
  store
, name_first
, [](name_first_t const& x) { print(x.value); }
);

// John
