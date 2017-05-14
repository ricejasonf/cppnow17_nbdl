...
    void right_arrow()
    {
      constexpr auto path = hana::transform(slide_action, hana::typeid_);

      ctx.push(
        ctx
        .message_api()
        .make_upstream_create_message(path, slide_action_next)
      );
    }
...
