metabench_add_dataset(metabench.chaining.chaining chaining.cpp "(25..200).step(25)"
  NAME chaining
)

metabench_add_dataset(metabench.chaining.variadic variadic.cpp "(25..200).step(25)"
  NAME variadic
)

metabench_add_chart(metabench.chaining
  DATASETS
  metabench.chaining.chaining
  metabench.chaining.variadic
)
