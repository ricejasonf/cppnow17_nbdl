std::string result;

account_t account{
  std::string{"@JasonRice_"}
, person_t{hana::make_tuple(name_first{"Jason"}, name_last{"Rice"})}
};

nbdl::match_path(
  account
, hana::make_tuple(person_s, name_s, hana::type_c<name_last>)
, [&](name_last const& x) { result = x.value; }
, [](auto&&) { }
);

CHECK(result == std::string{"Rice"});

