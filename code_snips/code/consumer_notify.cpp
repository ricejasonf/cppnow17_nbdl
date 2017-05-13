template <>
struct notify_state_change_impl<cppnow17::web::key_control> {
  template <typename Consumer, typename Path>
  static auto apply(Consumer const& c, Path const& path) {
    if constexpr(decltype(
      hana::typeid_(path) == hana::typeid_(cppnow17::current_slide)
    ){}) {
      nbdl::match(c.ctx, cppnow17::current_slide, [](auto value) {
        if constexpr(hana::typeid_(value) == hana::type_c<nbdl::unresolved>) {
          EM_ASM("console.log('current_slide: nbdl::unresolved');");
        }
        else {
          EM_ASM_(
            "console.log('current_slide: hana::size_c<' + $0 + '>');"
          , hana::value(value)
          );
        }
      });
    }
  }
};
