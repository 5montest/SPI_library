CROSS   := ~/Program/cross_gcc/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf

ifneq ($(CROSS),)
	CROSS_PREFIX	:= $(CROSS)-
endif

CXX		 = $(CROSS_PREFIX)g++
CXXFLAGS = -Wall -Wextra -O2 -g -MMD -MP
LDFLAGS	 =
LIBS	 = -L/usr/local/lib
INCLUDE	 = -I../include -I/usr/local/include
BIN_DIR  = ../bin/
TARGET 	 = $(BIN_DIR)$(shell basename `readlink -f ..`)
OBJDIR	 = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = .
endif
SOURCES	:= $(wildcard *.cpp)
OBJECTS	 = $(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))
DEPENDS	 = $(OBJECTS:.o=.d)

all: $(BIN_DIR) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o:%.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	$(RM) -r $(OBJECTS) $(DEPENDS) $(TARGET) $(BIN_DIR) `readlink -f $(OBJDIR)`

upload: $(BIN_DIR) $(TARGET)
	#ssh-keygen -R 172.16.12.131
	scp $(TARGET) pi@172.16.14.201:~/
	#scp $(TARGET) root@192.168.10.2:/usr/bin/


-include $(DEPENDS)
