account_t account{
  std::string{"@JasonRice_"}
, nbdl::nothing{}
};

nbdl::match_path(
  account
, hana::make_tuple("person"_s, "name"_s, hana::type_c<name_last>) 
, [](name_last const& x) { print(x.value); }
, [](auto&&)             { print("nothing"); }
);

// nothing
