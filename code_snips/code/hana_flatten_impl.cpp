/*
 * @copyright Louis Dionne 2013-2017
 * Distributed under the Boost Software License, Version 1.0.
 */

template <typename M, bool condition>
struct flatten_impl<M, when<condition>> : default_ {
    template <typename Xs>
    static constexpr auto apply(Xs&& xs)
    { return hana::chain(static_cast<Xs&&>(xs), hana::id); }
};
