PWD=$(shell pwd)

VPATH = $(PWD)
# the obj dir
OBJDIR = obj


SRC_C = $(foreach dir,$(subst :, ,$(VPATH)),$(wildcard $(dir)/*.c))
OBJ_C = $(addsuffix .o,$(basename $(SRC_C)))


CC     = clang
ARM_CC = arm-linux-gnueabihf-gcc

LIBS +=



TARGET:= t_main


all: $(TARGET)

$(TARGET):$(OBJ_C)
	$(CC) -o $@ $^

$(OBJ_C): $(SRC_C)
	$(CC) -c $(SRC_C)


arm_all: $(TARGET)

$(TARGET):$(OBJ_C)
	$(ARM_CC) -o $@ $^ -lpthread -lrt

$(OBJ_C): $(SRC_C)
	$(ARM_CC) -c $(SRC_C)




dbg:
	@echo $(SRC_C)
	@echo $(OBJ_C)

clean:
	rm -rf $(OBJ_C) $(TARGET)
