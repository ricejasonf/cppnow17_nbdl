...
    void right_arrow()
    {
      EM_ASM("console.log('right_arrow')");
      constexpr auto key = hana::transform(slide_action, hana::typeid_);

      ctx.push(
        ctx
        .message_api()
        .make_upstream_create_message(key, slide_action_next)
      );
    }
...
