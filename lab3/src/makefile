# Компилятор и флаги
CC = gcc
CFLAGS = -I.

# Основная цель - собирает ВСЕ программы
all: sequential_min_max parallel_min_max exec_launcher

# Сборка последовательной версии поиска min/max
sequential_min_max: utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o sequential_min_max sequential_min_max.c find_min_max.o utils.o $(CFLAGS)

# Сборка параллельной версии поиска min/max
parallel_min_max: utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max parallel_min_max.c find_min_max.o utils.o $(CFLAGS)

# Сборка программы с системным вызовом exec
exec_launcher: sequential_min_max
	$(CC) -o exec_launcher exec_launcher.c $(CFLAGS)

# Компиляция утилит (генерация массива)
utils.o: utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

# Компиляция библиотеки поиска min/max
find_min_max.o: utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

# Очистка всех скомпилированных файлов
clean:
	rm -f utils.o find_min_max.o sequential_min_max parallel_min_max exec_launcher

# Тестирование программ
test: all
	@echo "=== Testing sequential version ==="
	./sequential_min_max 42 10
	@echo "=== Testing exec launcher ==="
	./exec_launcher 42 10

# Показать справку
help:
	@echo "Available targets:"
	@echo "  all       - Build all programs (default)"
	@echo "  clean     - Remove all compiled files"
	@echo "  test      - Run basic tests"
	@echo "  help      - Show this help"

.PHONY: all clean test help
