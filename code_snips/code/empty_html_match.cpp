auto my_store = hana::make_map(
  hana::make_pair("key_1"_s, std::string("UPDATE ME"))
, hana::make_pair("key_2"_s, std::string(" More dynamic text."))
, hana::make_pair("key_3"_s, nbdl::optional<std::string>{})
);

constexpr auto spec =
  div(attr_class("foo"_s)
  , div(attr_class("bar"_s)
    , text_node("I'm some static text content."_s)
    , text_node(get("key_1"_s))
    , text_node(get("key_2"_s))
    , text_node(" More static text."_s)
    , match(
        get("key_3"_s)
      , when<std::string>(text_node(get("key_3"_s)))
      , when<>(text_node("nothing"_s))
      )
    )
  );
