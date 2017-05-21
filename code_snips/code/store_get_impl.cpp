template<typename Tag>
struct match_impl<Tag, hana::when<!hana::is_default<nbdl::get_impl<Tag>>::value>>
{
  template <typename Store, typename Key, typename Fn>
  static constexpr void apply(Store&& s, Key&& k, Fn&& fn)
  {
    std::forward<Fn>(fn)(
      nbdl::get(std::forward<Store>(s), std::forward<Key>(k))
    );
  }
};
