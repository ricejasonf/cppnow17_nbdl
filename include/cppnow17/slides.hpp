//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_SLIDES_HPP
#define CPPNOW17_SLIDES_HPP

#include <boost/hana.hpp>
#include <cppnow17/slide_spec.hpp>
#include <mpdef/list.hpp>

namespace cppnow17
{
  constexpr auto make_slides()
  {
    namespace hana = boost::hana;
    using namespace boost::hana::literals;
    using namespace cppnow17::slide_spec;

    return mpdef::make_list(
      title(
        header("Nbdl"_s)
      , description("A library that uses metaprogramming... A lot"_s)
      )
    , bulleted(
        header("Overview"_s)
      , bullets(
          "What is Nbdl?"_s
        , "Abstraction"_s
        , "Concepts"_s
        , "Store"_s
        , "Promises"_s
        , "Empty Interface"_s
        , "Using Docker"_s
        )
      )
    , syntax(
        header("Readable code?"_s)
      , name("empty_html_match_2.cpp"_s)
      )
    , bulleted(
        header("What is Nbdl?"_s)
      , bullets(
          "Manages State"_s
        , "Communicates Changes in State"_s
        , "Provides implementations for common use cases"_s
        )
      )
    , overview_diagram()
    , syntax(
        header(""_s)
      , name("make_context.cpp"_s)
      )
    , title(
        header("Abstraction"_s)
      , description("Boost.Hana Style"_s)
      )
    , syntax(
        header("hana::Monad"_s)
      , name("hana_monad.cpp"_s)
      )
    , syntax(
        header("hana::flatten_impl"_s)
      , name("hana_flatten_impl.cpp"_s)
      )
    , syntax(
        header("hana::flatten"_s)
      , name("hana_flatten.cpp"_s)
      )
    , syntax(
        header("hana::tag_of"_s)
      , name("tag_of_tuple.cpp"_s)
      )
    , syntax(
        header("hana::tag_of"_s)
      , name("tag_of_my_struct.cpp"_s)
      )
    , syntax(
        header(""_s)
      , name("tag_of_my_list.cpp"_s)
      )
    , title(
        header("Concepts"_s)
      , description(""_s)
      )
    , bulleted(
        header("Producer"_s)
      , bullets(
          "make_producer"_s
        , "send_upstream_message"_s
        )
      )
    , syntax(
        header("Echo Producer"_s)
      , name("producer_impl.cpp"_s)
      )
    , syntax(
        header("make_producer"_s)
      , name("producer_make.cpp"_s)
      )
    , syntax(
        header(""_s)
      , name("producer_send.cpp"_s)
      )
    , bulleted(
        header("Consumer"_s)
      , bullets(
          "make_consumer"_s
        , "send_downstream_message"_s
        , "notify_state_change"_s
        )
      )
    , syntax(
        header("Pushing Messages"_s)
      , name("consumer_key_event.cpp"_s)
      )
    , syntax(
        header(""_s)
      , name("consumer_notify.cpp"_s)
      )
    , bulleted(
        header("Entity"_s)
      , bullets(
          "NBDL_ENTITY"_s
        )
      )
    , syntax(
        header(""_s)
      , name("entity_define.cpp"_s)
      )
    , bulleted(
        header("BindableSequence BindableMap"_s)
      , bullets(
          "bind_sequence"_s
        , "bind_map"_s
        )
      )
    , syntax(
        header(""_s)
      , name("bind_stuff.cpp"_s)
      )
    , syntax(
        header(""_s)
      , name("bind_stuff_output.cpp"_s)
      )
    , bulleted(
        header("BindableVariant"_s)
      , bullets(
          "bind_variant"_s
        )
      )
    , syntax(
        header(""_s)
      , name("bindable_variant.cpp"_s)
      )
    , syntax(
        header(""_s)
      , name("bindable_variant_output.cpp"_s)
      )
    , bulleted(
        header("Store"_s)
      , bullets(
          "match"_s
        , "apply_action"_s
        )
      )
    , syntax(
        header("hana::map as a Store"_s)
      , name("store_match_hana_map.cpp"_s)
      )
    , syntax(
        header("Entity as a Store"_s)
      , name("store_match_entity.cpp"_s)
      )
    , syntax(
        header("hana::Sequence as a Store"_s)
      , name("store_match_tuple.cpp"_s)
      )
    , syntax(
        header("A variant as a Store"_s)
      , name("store_match_variant.cpp"_s)
      )
    , syntax(
        header("variant identity"_s)
      , name("store_match_variant_id.cpp"_s)
      )
    , bulleted(
        header(""_s)
      , bullets(
          "match_path"_s
        )
      )
    , syntax(
        header("match_path"_s)
      , name("store_match_path.cpp"_s)
      )
    , syntax(
        header("match_path"_s)
      , name("store_match_path_nothing.cpp"_s)
      )
    , title(
        header("Promises"_s)
      , description(""_s)
      )
    , bulleted(
        header(""_s)
      , bullets(
          "run_sync"_s
        )
      )
    , syntax(
        header("path_promise"_s)
      , name("path_promise.cpp"_s)
      )
    , syntax(
        header("path_promise... rejected"_s)
      , name("path_promise_reject.cpp"_s)
      )
    , syntax(
        header(""_s)
      , name("require_type.cpp"_s)
      )
    , syntax(
        header("Eager 'index_if'"_s)
      , name("find_index.cpp"_s)
      )
    , bulleted(
        header(""_s)
      , bullets(
          "run_async"_s
        )
      )
    , syntax(
        header("Simple Server/Client"_s)
      , name("run_async.cpp"_s)
      )
    , syntax(
        header("No std::shared_ptr!"_s)
      , name("run_async_connect.cpp"_s)
      )
    , syntax(
        header("Unhandled Rejection!"_s)
      , name("unhandled_rejection.cpp"_s)
      )
    , title(
        header("Empty UI"_s)
      , description(""_s)
      )
    , syntax(
        header("Empty... Stateless... Perfect"_s)
      , name("empty_struct.cpp"_s)
      )
    , syntax(
        header("Html"_s)
      , name("empty_html.cpp"_s)
      )
    , syntax(
        header("Matching values in stores"_s)
      , name("empty_html_match.cpp"_s)
      )
    , syntax(
        header("Using Predicates"_s)
      , name("empty_html_match_if.cpp"_s)
      )
    , title(
        header("Docker"_s)
      , description(""_s)
      )
    , syntax(
        header("Dependencies"_s)
      , name("docker_deps"_s)
      )
    , bulleted(
        header("Special Thanks"_s)
      , bullets(
          "Louis Dionne"_s
        )
      )
    );
  }

  constexpr auto slides = make_slides();
}

#endif
