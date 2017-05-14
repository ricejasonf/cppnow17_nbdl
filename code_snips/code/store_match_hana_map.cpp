
auto store = hana::make_map(
  hana::make_pair("key_1"_s, std::string("Hello, World!"))
, hana::make_pair("key_2"_s, 42)
);

nbdl::match(
  store
, "key_1"_s
, [](std::string const& x) { print(x); }
);

// Hello, World!
