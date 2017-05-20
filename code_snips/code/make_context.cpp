Context(
  Producers(
    Producer(
      Name("producer"_s)
    , Type(ProducerTag{})
    , AccessPoint(
        Name("current_slide"_s)
      , Store<cppnow17::current_slide_store>
      , Entity<current_slide_t>
      , PathKey<current_slide_tag>
      )
    , AccessPoint(
        Name("slide_action"_s)
      , Actions(Create())
      , Entity<slide_action_t>
      , PathKey<slide_action_tag>
      )
    )
  )
, Consumers(
    Consumer(
      Name("consumer"_s)
    , Type(ConsumerTag{})
    )
  , MoreConsumerDefs{}...
  )
);
