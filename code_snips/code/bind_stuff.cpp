auto messages = hana::make_tuple(
  person_t{"John", "Smith"}
, user_t{"@JasonRice_", person_t{"Jason", "Rice"}}
, hana::make_tuple(
    "This"s , "is a tuple with"s , 6, "elements"s
  , "I'm a compile time string!"_s
  , "Last"s
  )
, hana::make_map(
    hana::make_pair("key_1"_s, "value1"s)
  , hana::make_pair("key_2"_s, "value2"s)
  , hana::make_pair("key_3"_s, hana::just(5))
  , hana::make_pair("key_4"_s, hana::nothing)
  , hana::make_pair("key_5"_s, hana::make_tuple(1, 2, 3, 4, "tuple"s))
  )
, terminate{}
);

std::cout << nbdl::binder::jsoncpp::to_string(messages);
