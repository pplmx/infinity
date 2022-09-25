.PHONY: dev clean

# create a image "infinity" with tag "latest"
# based on the Dockerfile in the current directory
dev:
	docker image build . -t infinity
	docker container run --rm infinity

clean:
	docker image rm infinity
