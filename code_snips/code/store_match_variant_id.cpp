nbdl::optional<std::string> store = std::string("Hello, maybe!");

nbdl::match(
  store
, [](auto const& x)
  {
    if constexpr(hana::is_a<std::string, decltype(x)>)
      print(x);
    else
      print("nothing");
  }
);

// Hello, maybe!
