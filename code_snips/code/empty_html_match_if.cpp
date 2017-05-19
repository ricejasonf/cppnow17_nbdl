auto slide_container = [](auto index, auto child)
{
  constexpr std::size_t i = hana::value(index);

  return div(
    attr_class(concat(
      "slide "_s
    , match_if(get(current_slide)
      , cond(equal(current_slide_c<i>)    , "current"_s)
      , cond(equal(current_slide_c<i + 1>), "prev"_s)
      , cond(equal(current_slide_c<i - 1>), "next"_s)
      , otherwise(""_s)
      )
    ))
  , child
  );
};
