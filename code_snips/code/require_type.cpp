template <typename T>
auto require_type = nbdl::promise([](auto& resolver, auto const& value)
{
  if constexpr(decltype(hana::typeid_(value) == hana::type_c<T>){})
    resolver.resolve(value);
  else
    resolver.reject(value);
});
