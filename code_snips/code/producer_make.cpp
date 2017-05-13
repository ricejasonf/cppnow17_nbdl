template <>
struct make_producer_impl<echo_producer>
{
  template <typename ContextHandle>
  static constexpr auto apply(ContextHandle&& h)
  {
    return echo_producer_impl<ContextHandle>{std::forward<ContextHandle>(h)};
  }
};
