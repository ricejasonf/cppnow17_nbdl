# Targets here are just a convenience for using
# docker to manage the development environment.

image_web_develop:
	cppdock build emscripten \
	&& docker build -f ./docker/Dockerfile-web_develop -t cppnow17_nbdl:web_develop .

web_develop:
	docker run --rm -it -p 8080:8080 -v ${shell pwd}:/opt/src:ro cppnow17_nbdl:web_develop
