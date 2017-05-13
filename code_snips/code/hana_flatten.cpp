/*
 * @copyright Louis Dionne 2013-2017
 * Distributed under the Boost Software License, Version 1.0.
 */

template <typename Xs>
constexpr auto flatten_t::operator()(Xs&& xs) const {
    using M = typename hana::tag_of<Xs>::type;
    using Flatten = BOOST_HANA_DISPATCH_IF(flatten_impl<M>,
        hana::Monad<M>::value
    );

    static_assert(hana::Monad<M>::value,
    "hana::flatten(xs) requires 'xs' to be a Monad");

    return Flatten::apply(static_cast<Xs&&>(xs));
}
