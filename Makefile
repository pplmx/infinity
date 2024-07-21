.PHONY: init build run dev clean

# Initialize the build environment
init:
	@mkdir -p build
	@cmake -S . -B build

# Build the project
build: init
	@cmake --build build

# Run the project
run: build
	@./build/infinity.exe

# Build and run the Docker container
dev:
	@docker image build . -t infinity
	@docker container run --rm infinity

# Clean the build artifacts and Docker images
clean:
	@rm -rf build
	@docker image rm infinity -f

# Additional convenience targets
rebuild: clean build

# For full re-initialization and build
full-build: clean init build

# Clean all Docker images and containers (use with caution)
clean-docker:
	@docker container prune -f
	@docker image prune -a -f
