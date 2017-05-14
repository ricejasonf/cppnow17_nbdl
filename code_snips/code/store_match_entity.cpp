auto store = person_t{"John", "Smith"};

nbdl::match(
  store
, "name_first"_s
, [](std::string const& x) { print(x); }
);

// John
