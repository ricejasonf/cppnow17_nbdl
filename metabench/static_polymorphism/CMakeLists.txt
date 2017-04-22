metabench_add_dataset(crtp main.cpp "(0..200).step(25)"
  NAME crtp
  ENV "{ use_crtp: true }"
)

metabench_add_dataset(template_spec main.cpp "(0..200).step(25)"
  NAME template_spec
  ENV "{ use_crtp: false }"
)

metabench_add_chart(metabench.static_polymorphism
  DATASETS
  crtp
  template_spec
)
