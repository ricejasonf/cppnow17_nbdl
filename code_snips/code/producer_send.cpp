template <>
struct send_upstream_message_impl<echo_producer>
{
  template <typename Producer, typename Message>
  static constexpr void apply(Producer const& p, Message const& m)
  {
    if constexpr(message::is_create<Message>)
    {
      p.ctx.push(p.ctx.message_api().to_downstream_from_root(
        m,
        echo_producer_detail::make_unique_key(m)
      ));
    }
    else
    {
      p.ctx.push(p.ctx.to_downstream_from_root(m));
    }
  }
};
