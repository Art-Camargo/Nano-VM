# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Fontes
SRCS = dir_options.c drop_down_menu.c launch.c loader.cpp main.c

# Executável final
TARGET = vm_launcher

# Regra principal
all: $(TARGET)

# Regra para compilar o executável se qualquer fonte for modificada
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Limpa o executável
clean:
	rm -f $(TARGET)

.PHONY: all clean
