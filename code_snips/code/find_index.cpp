nbdl::run_sync(
  hana::make_tuple(
    hana::transform(hana::to_tuple(preds), predicate_promise)
  , [](auto const& ...args)
    {
      static_assert(
        sizeof...(args) > 9000
      , "nbdl::detail::match_if must have at least one predicate "
        "that returns compile-time Logical that is true."
      );
    }
  , nbdl::catch_([&](auto index) { resolve(index); })
  )
, value
, hana::size_c<0>
);
