# Targets here are just a convenience for using
# docker to manage the development environment.

image_develop:
	docker build -f ./docker/Dockerfile-develop -t cppnow17_nbdl:develop .

image_develop_no_cache:
	docker pull ricejasonf/emscripten \
	&& docker build --no-cache=true -f ./docker/Dockerfile-develop -t cppnow17_nbdl:develop .

develop: 
	docker run --rm -it -p 8080:8080 -v ${shell pwd}:/opt/src:ro cppnow17_nbdl:develop

image_web_develop:
	docker pull ricejasonf/emscripten \
	&& docker build --no-cache=true -f ./docker/Dockerfile-web_develop -t nbdl:web_develop .

web_develop:
	docker run --rm -it -p 8080:8080 -v ${shell pwd}:/opt/src:ro nbdl:web_develop
