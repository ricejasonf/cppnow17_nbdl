template <typename Resolve, typename ...Args>
void connect_fn::operator()(Resolve& resolver, Args&& ...) {
  socket.async_connect(endpoint, [&](asio::error_code error) {
    if (!error) {
      resolver.resolve(socket); 
    }
    else if (attempts_failed++ >= attempts_.value) {
      resolver.reject(attempts_);
    }
    else {
      std::cout << "Connection failed! trying again...";
      operator()(resolver);
    }
  });
}
