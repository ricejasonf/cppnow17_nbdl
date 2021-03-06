# Nbdl Presentation for CppNow2017

> Below is an outline sort of correlating to slides
> Provide code samples in slides to show purpose

## Build the Web App

```
make image_web_develop && make web_develop
```
... then in the docker container
```
root@f2b146e7bad9:/opt/build# make code_snips && make hot_dev
```

This will run a local http server on port 8080 with the built web app.
(It takes about a minute to compile right now)

The bundled html file is in `/bundle.html`


Thanks for checking it out!


## Purpose of Talk

  - Metaprogramming with Boost.Hana (with a focus on Nbdl)
  - Topics
    - Empty Interface
    - Purpose of Nbdl
    - Concepts
    - Abstraction
    - Store
    - Promises
    - Rendering
    - Deployment

## Purpose of Nbdl

  - Manage state
  - Communicate changes in state
    - UI Components
    - Server
    - Other Clients
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
    - `store_impl<nbdl::variant_tag>`
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

## Deployment
  - Building with Docker
  - Deploying with Docker

## Conclusion
  - ??
