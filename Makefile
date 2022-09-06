FLAGS = -Wall -Wextra

build_all: clean build_test build_debug build_profile build_release build_speed_test

build_test:
	g++ $(FLAGS) -g -pthread ./src/AES.cpp ./tests/tests.cpp /usr/lib/libgtest.a -o bin/test

build_debug:
	g++ $(FLAGS) -g ./src/AES.cpp ./dev/main.cpp -o bin/debug

build_profile:
	g++ $(FLAGS) -pg ./src/AES.cpp ./dev/main.cpp -o bin/profile

build_speed_test:
	g++ $(FLAGS) -O2 ./src/AES.cpp ./speedtest/main.cpp -o bin/speedtest

build_release:
	g++ $(FLAGS) -O2 ./src/AES.cpp ./dev/main.cpp -o bin/release



test:
	bin/test

debug:
	bin/debug

profile:
	bin/profile

release:
	bin/release

speed_test:
	bin/speedtest

style_fix:
	bash -c "clang-format -i src/*.cpp src/*.h tests/*.cpp"

clean:
	rm -rf bin/*


workflow_build_test:
	g++ $(FLAGS) -g -pthread ./src/AES.cpp ./tests/tests.cpp /usr/lib/libgtest.a -o bin/test

workflow_build_speed_test:
	g++ $(FLAGS) -O2 ./src/AES.cpp ./speedtest/main.cpp -o bin/speedtest	

