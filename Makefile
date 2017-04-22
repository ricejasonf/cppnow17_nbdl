# Targets here are just a convenience for using
# docker to manage the development environment.

image_develop:
	docker pull ricejasonf/emscripten \
	&& docker build --no-cache=true -f ./docker/Dockerfile-develop -t cppnow17_nbdl:develop .

develop: 
	docker run --rm -it -p 8080:8080 -v ${shell pwd}:/opt/src:ro cppnow17_nbdl:develop
