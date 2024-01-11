MAIN = main
SUB1 = sub1
SUB2 = ClockCounter

CC = g++
EDITOR = vim
EPARAM = -p
SRCS = ./src
INCS = ./include
BINS = ./bin
BUILD = ./build
LIBS = -lm
CFLAGS = -I$(INCS)
PARAM = -O0
FILE = text

PROGRAM = hoge
OBJS = $(BINS)/$(MAIN).o $(BINS)/$(SUB1).o $(BINS)/$(SUB2).o
CODES = $(SRCS)/$(MAIN).cpp $(SRCS)/$(SUB1).cpp $(SUB2)/$(SUB2).cpp

.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^ $(LIBS) $(PARAM)

chmod : $(PROGRAM)
	sudo chmod +x $(BUILD)/$(PROGRAM)

execute: all chmod
	$(BUILD)/$(PROGRAM) $(FILE)
	cat $(FILE)

all: clean mkdir $(PROGRAM)

clean:
	rm -rf $(BUILD) $(BINS)

mkdir:
	mkdir $(BUILD) $(BINS)

edit:
	$(EDITOR) $(EPARAM) $(SUB2)/* $(INCS)/* $(SRCS)/*

$(BINS)/$(MAIN).o: $(SRCS)/$(MAIN).cpp $(INCS)/$(MAIN).hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(BINS)/$(SUB1).o: $(SRCS)/$(SUB1).cpp $(INCS)/$(SUB1).hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(BINS)/$(SUB2).o: $(SUB2)/$(SUB2).cpp $(SUB2)/$(SUB2).hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

