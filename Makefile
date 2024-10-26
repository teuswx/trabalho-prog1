# Definição do compilador C
CC       := gcc
# Flags de compilação para C
CFLAGS   := -Wall -Wextra -Werror
# Flags para linkagem
LDFLAGS  := -lstdc++ -lm
# Diretórios
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/
# Nome do executável final
TARGET   := app
# Diretório de inclusão
INCLUDE  := -Iinclude/
# Arquivos fonte C
SRC      :=  $(wildcard src/*.c)

# Definição dos arquivos objeto
OBJECTS := $(SRC:%.c=$(OBJ_DIR)/%.o)

# Regra principal
all: build $(APP_DIR)/$(TARGET)

# Compilação dos arquivos .c para .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

# Linkagem dos objetos para gerar o executável
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

# Targets adicionais
.PHONY: all build clean debug release run

# Criar diretórios de build
build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

# Modo de compilação debug
debug: CFLAGS += -DDEBUG -g
debug: all

# Modo de compilação release
release: CFLAGS += -O3
release: all

# Limpeza dos arquivos gerados
clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

# Executar o programa
run: all
	./$(BUILD)/$(TARGET)



