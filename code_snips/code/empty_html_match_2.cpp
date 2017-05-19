auto slide_container = [](auto index, auto child)
{
  constexpr std::size_t i = hana::value(index);

  // Don't do this!
  return div(
    attr_class(concat(
      "slide "_s
    , match(get(current_slide)
      , when<hana::size_t<i>>("current"_s)
      , when<hana::size_t<i + 1>>("prev"_s)
      , when<hana::size_t<i - 1>>("next"_s)
      , when<>(""_s)
      )
    ))
  , child
  );
};
