account_t account{
  std::string{"@JasonRice_"}
, person_t{hana::make_tuple(name_first{"Jason"}, name_last{"Rice"})}
};

nbdl::match_path(
  account
, hana::make_tuple("person"_s, "name"_s, hana::type_c<name_last>) 
, [](name_last const& x) { print(x.value); }
, [](auto&&)             { print("nothing"); }
);

// Rice
