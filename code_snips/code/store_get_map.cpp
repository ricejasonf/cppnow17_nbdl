template<typename Tag>
struct get_impl<Tag, hana::when<hana::Searchable<Tag>::value>>
{
  template <typename Store, typename Key>
  static constexpr decltype(auto) apply(Store&& s, Key&& k)
  {
    if constexpr(hana::Sequence<Store>::value)
    {
      using Pred = decltype(hana::compose(hana::equal.to(hana::typeid_(k)), hana::typeid_));
      using Index = decltype(hana::index_if(s, Pred{}).value());
      return hana::at(std::forward<Store>(s), Index{});
    }
    else
    {
      return hana::at_key(std::forward<Store>(s), std::forward<Key>(k));
    }
  }
};
