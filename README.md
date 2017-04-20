# Nbdl Presentation for CppNow2017

> Below is an outline sort of correlating to slides
> Provide code samples in slides to show purpose


## Purpose of Talk

  - Metaprogramming with Boost.Hana (with a focus on Nbdl)
  - Library Structure
  - Demonstrate that C++ can do better than other languages including its former self
    - `C++ >`

## Purpose of Nbdl

  - Manage state
  - Communicate changes in state
  - Provide implementations for common use cases 

## Concepts

  - Producer
    - `send_upstream_message`
  - Consumer
    - `send_downstream_message`
  - Store
    - Holds state for immediate access
    - `match`
    - `apply_action`
  - Entity
    - Implements reflection on struct members as a sequence
  - BindableSequence
    - `bind_sequence`
  - BindableMap
    - `bind_map`
    - Keys must be convertible to `char const*` 
  - BindableVariant
    - `bind_variant`
    - Allows for serialization of variant types

## Boost.Hana's Facilities for Abstraction
  
  - `hana::tag_of`
  - Template specialization
    - `store_impl<hana::map_tag>`
    - `store_impl<nbdl::map_tag>`
  - Concept Implementation
    - `hana::default_` with `nbdl::match_impl`
    - `nbdl::Store`
  - Hana Concepts
    - Foldable
      - `unpack_impl<nbdl::entity_tag>`
    - Iterable
      - `at_impl<nbdl::entity_tag>`

## Store

  - `match`
    - key
    - identity
  - `match_path`

## Promises

  - `run_async`
  - `detail::promise_join`
  - `run_sync`
  - `path_promise`

## Rendering
  - Html Dom
    - Components
    - Sample of Immutable TextNode
  - Metaprogrammatically Generate UIViews (hopefully)
  - Generic Document Structure

## Conclusion
  - ??
