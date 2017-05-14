...
  template <typename ...Args>
  void resolve(Args&&...)
  {
    delete end;
  }

  template <typename Arg1, typename ...Args>
  void reject(Arg1&&, Args&&...)
  {
    static_assert(
      sizeof...(Args) > 9000
    , "Unhandled Rejection!"
    );
  }
...
