#Primer Makefile armado por Gemini 

# --- 1. Configuración del Compilador ---
CC = gcc
# Flags: 
# -Iinclude: Busca archivos .h en la carpeta include
# -Wall -Wextra: Muestra todas las advertencias (buenas prácticas)
# -g: Agrega información para debug (útil si usas GDB o Valgrind)
CFLAGS = -Wall -Wextra -g -Iinclude
# LDFLAGS: Librerías extra (ej. -lm para math.h)
LDFLAGS = -lm

# --- 2. Rutas de Carpetas ---
SRC_LIB_DIR = src/lib
SRC_APPS_DIR = src/apps
BIN_DIR = bin

# --- 3. Detección Automática de Archivos ---
# Busca todos los .c dentro de src/lib/ (tus Pilas, Colas, Listas)
SRCS_LIB = $(wildcard $(SRC_LIB_DIR)/*.c)
# Crea una lista de objetos .o correspondientes
OBJS_LIB = $(SRCS_LIB:.c=.o)

# Busca todos los .c dentro de src/apps/ (tus ejercicios resueltos)
SRCS_APPS = $(wildcard $(SRC_APPS_DIR)/*.c)
# Define los nombres de los ejecutables finales en bin/
EXES = $(patsubst $(SRC_APPS_DIR)/%.c,$(BIN_DIR)/%,$(SRCS_APPS))

# --- 4. Reglas de Compilación ---

# Regla por defecto: compila todo
all: $(EXES)

# Regla Mágica: Cómo construir un ejecutable en bin/
# Depende de: el código de la app Y todos los objetos de la librería
$(BIN_DIR)/%: $(SRC_APPS_DIR)/%.c $(OBJS_LIB)
	@mkdir -p $(BIN_DIR)
	@echo "🔨 Compilando aplicación: $@"
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Regla para compilar la librería (convertir .c a .o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar (borrar ejecutables y objetos viejos)
clean:
	@echo "🧹 Limpiando archivos temporales..."
	rm -f $(SRC_LIB_DIR)/*.o
	rm -f $(BIN_DIR)/*

# Evita conflictos si tienes archivos llamados 'all' o 'clean'
.PHONY: all clean