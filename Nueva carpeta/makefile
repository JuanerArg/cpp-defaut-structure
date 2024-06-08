# Encuentra todos los archivos .cpp en el directorio src
CPP_FILES := $(wildcard src/*.cpp)
# Encuentra todos los archivos .rc en el directorio res
RC_FILES := $(wildcard res/*.rc)
# Genera una lista de archivos .o correspondientes a los archivos .cpp y .rc
O_FILES := $(CPP_FILES:%.cpp=%.o) $(RC_FILES:%.rc=%.o)

# Flags para la compilación que ayudan a identificar errores y optimizar el código
COMPILED_FLAGS := -pedantic -W -Wall -O3  
# Flags para la etapa de enlazado
LINKED_FLAGS := -s
# Directorios de inclusión de archivos de cabecera
INCLUDE_DIRECTORIES := -Iinclude\SDL2
# Directorios de las bibliotecas
LIB_DIRECTORIES := -Llib
# Archivos de las bibliotecas
LIB_FILES := -lSDL2main -lSDL2

# Regla principal para generar el ejecutable "app"
app: $(O_FILES)
	g++ $(O_FILES) -o $@ $(LIB_DIRECTORIES) $(LIB_FILES) $(LINKED_FLAGS)

# Regla para compilar archivos .cpp a archivos .o
src/%.o: src/%.cpp
	g++ -c $< -o $@ $(INCLUDE_DIRECTORIES) $(COMPILED_FLAGS)

# Regla para compilar archivos .rc a archivos .o usando windres
res/%.o: res/%.rc
	windres $< -o $@ $(INCLUDE_DIRECTORIES)

# Regla para limpiar los archivos generados
clean:
	rm -f src/*.o res/*.o app.exe

