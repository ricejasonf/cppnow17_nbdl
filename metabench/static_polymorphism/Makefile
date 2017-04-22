.PHONY: image build

image:
	docker build -t benchmark_static_polymorphism .
#	docker pull ricejasonf/metabench && docker build -t benchmark_static_polymorphism .

build: 
	docker run --rm -p 8081:8081 -v ${shell pwd}:/opt/src:ro benchmark_static_polymorphism
