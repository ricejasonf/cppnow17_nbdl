nbdl::optional<person_t> store = person_t{"John", "Smith"};

nbdl::match(
  store
, "name_first"_s
, [](auto const& x)
  {
    if constexpr(hana::is_a<std::string, decltype(x)>)
      print(x);
    else
      print("nothing");
  }
);

// John
