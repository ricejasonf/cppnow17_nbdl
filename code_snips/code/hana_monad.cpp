/*
 * @copyright Louis Dionne 2013-2017
 * Distributed under the Boost Software License, Version 1.0.
 */
template <typename M>
struct Monad
    : hana::integral_constant<bool,
        !is_default<flatten_impl<typename tag_of<M>::type>>::value ||
        !is_default<chain_impl<typename tag_of<M>::type>>::value
    >
{ };
