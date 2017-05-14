asio::io_service io;

nbdl::run_async(nbdl::pipe(
  example::accept(io, example::port({1234}))
, nbdl::tap(   [](auto&&...)  { std::cout << "Client connection accepted"; })
, nbdl::catch_([](auto&&)     { std::cout << "SERVER ERROR"; })
));

nbdl::run_async(nbdl::pipe(
  example::connect(io, example::port{1234})
, nbdl::tap(   [](auto&&)            { std::cout << "Connected to server"; })
, nbdl::catch_([](example::attempts) { std::cout << "failed with too many attempts"; })
, nbdl::catch_([](auto&&)            { std::cout << "CLIENT ERROR"; })
));

io.run();
