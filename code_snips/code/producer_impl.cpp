struct echo_producer { };

template <typename ContextHandle>
struct echo_producer_impl
{
  using hana_tag = echo_producer;

  ContextHandle ctx;
};
