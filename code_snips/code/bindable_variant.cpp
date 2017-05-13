using my_var = nbdl::variant<
  hana::size_t<0> 
, hana::size_t<1>
, int
, std::string
>;

nbdl::binder::jsoncpp::to_string(
  hana::make_tuple(
    my_var{std::string("hello")}
  , my_var{hana::size_c<0>}
  , my_var{hana::size_c<1>}
  , my_var{42}
  )
);
