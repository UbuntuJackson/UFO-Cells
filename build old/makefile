main : main.o entity.o program.o assets.o colour_utils.o rect.o misc_math.o collision_utils.o
		g++ -g -o main main.o entity.o program.o assets.o colour_utils.o rect.o misc_math.o collision_utils.o \
		-lX11 -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
main.o : ../src/main.cpp ../src/program.h
		g++ -c -g ../src/main.cpp
entity.o : ../src/entity.cpp ../src/entity.h ../src/program.h ../src/colour_utils.h
		g++ -c -g ../src/entity.cpp
program.o : ../src/program.cpp ../src/program.h ../src/olcPixelGameEngine.h ../src/entity.h ../src/assets.h
		g++ -c -g ../src/program.cpp
assets.o : ../src/assets.cpp ../src/assets.h ../src/olcPixelGameEngine.h
		g++ -c -g ../src/assets.cpp
collision_utils.o : ../src/collision_utils.cpp ../src/collision_utils.h ../src/rect.h
		g++ -c -g ../src/collision_utils.cpp

colour_utils.o : ../src/colour_utils.cpp ../src/colour_utils.h ../src/olcPixelGameEngine.h
		g++ -c -g ../src/colour_utils.cpp
rect.o : ../src/rect.cpp ../src/rect.h ../src/olcPixelGameEngine.h
		g++ -c -g ../src/rect.cpp

misc_math.o : ../src/misc_math.cpp ../src/misc_math.h
		g++ -c -g ../src/misc_math.cpp

clean:
		rm main *.o