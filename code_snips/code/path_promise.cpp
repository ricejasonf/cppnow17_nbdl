account_t account{
  username_t{"@JasonRice_"}
, person_t{hana::make_tuple(name_first_t{"Skippy"}, name_last_t{"McGee"})}
};

nbdl::run_sync(
  hana::make_tuple(
    nbdl::path_promise(get("person"_s, "name"_s, hana::type_c<name_last_t>))
  , require_type<name_last_t>
  , value_of, to_upper
  , nbdl::tap([](std::string const& str) { print(str); })
  , nbdl::catch_([](auto&&) { print("something else"); })
  )
, account
);

// MCGEE
