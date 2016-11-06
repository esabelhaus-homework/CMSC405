UNAME := $(shell uname -s)
ifeq ($(UNAME),Darwin)
	BUILD_PARAMS=-lGLUT -lglut
endif
ifeq ($(UNAME),Linux)
	BUILD_PARAMS=-lGL -lGLU -lglut
endif

all: clean build

build:
	g++ GuiApp.cpp -o GuiApp ${BUILD_PARAMS}
clean:
	rm -f GuiApp
