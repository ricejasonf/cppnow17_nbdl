account_t account{
  username_t{"@JasonRice_"}
, nbdl::nothing{}
};

nbdl::run_sync(
  nbdl::pipe(
    nbdl::path_promise(get("person"_s, "name"_s, hana::type_c<name_last_t>))
  , require_type<name_last_t>
  , value_of, to_upper
  , nbdl::tap([](std::string const& str) { print(str); })
  , nbdl::catch_([](auto&&) { print("something else"); })
  )
, account
);

// something else
