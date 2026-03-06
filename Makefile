# Компилятор
CXX = g++
CXXFLAGS = -g -Wall

# Флаги для AddressSanitizer
ASAN_FLAGS = -fsanitize=address -g -fno-omit-frame-pointer

#  Директории — ОБЯЗАТЕЛЬНО ПЕРВЫМИ!
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

# Исполняемый файл
TARGET = $(BUILD_DIR)/debug.out

# Объектные файлы
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/rect.o $(BUILD_DIR)/barrel.o $(BUILD_DIR)/matrix.o $(BUILD_DIR)/mystring.o

# Заголовочные файлы 
HEADERS = $(SRC_DIR)/rect.hpp $(SRC_DIR)/barrel.hpp $(SRC_DIR)/matrix.hpp $(SRC_DIR)/mystring.hpp

# Цель по умолчанию
all: $(TARGET)

# Создание директории build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Линковка
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция отдельных .cpp в .o
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -I$(SRC_DIR) -o $(BUILD_DIR)/main.o $(SRC_DIR)/main.cpp

$(BUILD_DIR)/rect.o: $(SRC_DIR)/rect.cpp $(SRC_DIR)/rect.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -I$(SRC_DIR) -o $(BUILD_DIR)/rect.o $(SRC_DIR)/rect.cpp

$(BUILD_DIR)/barrel.o: $(SRC_DIR)/barrel.cpp $(SRC_DIR)/barrel.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -I$(SRC_DIR) -o $(BUILD_DIR)/barrel.o $(SRC_DIR)/barrel.cpp

$(BUILD_DIR)/matrix.o: $(SRC_DIR)/matrix.cpp $(SRC_DIR)/matrix.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -I$(SRC_DIR) -o $(BUILD_DIR)/matrix.o $(SRC_DIR)/matrix.cpp

$(BUILD_DIR)/mystring.o: $(SRC_DIR)/mystring.cpp $(SRC_DIR)/mystring.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -I$(SRC_DIR) -o $(BUILD_DIR)/mystring.o $(SRC_DIR)/mystring.cpp

# Отладчик
debug: $(TARGET)
	lldb $(TARGET)

# AddressSanitizer: проверка утечек
asan: clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) $(ASAN_FLAGS)" all
	@echo "=== Running with AddressSanitizer ==="
	./$(TARGET)

# Очистка
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean debug asan



# === Цели для тестов ===

# Простое правило для всех тестов Rect
$(BUILD_DIR)/test_%.out: $(TEST_DIR)/test_%.cpp $(BUILD_DIR)/rect.o | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(BUILD_DIR)/rect.o

test_basic: $(BUILD_DIR)/test_rect_basic_methods.out
	@./$(BUILD_DIR)/test_rect_basic_methods.out && echo "✓ Passed" || exit 1

test_properties: $(BUILD_DIR)/test_rect_properties.out
	@./$(BUILD_DIR)/test_rect_properties.out && echo "✓ Passed" || exit 1

test_operations: $(BUILD_DIR)/test_rect_operations.out
	@./$(BUILD_DIR)/test_rect_operations.out && echo "✓ Passed" || exit 1

test_bounding: $(BUILD_DIR)/test_bounding_rect.out
	@./$(BUILD_DIR)/test_bounding_rect.out && echo "✓ Passed" || exit 1

test: test_basic test_properties test_operations test_bounding
	@echo "🎉 All tests completed!"




# === Цели для запуска тестов ===

.PHONY: test test_basic test_properties test_operations test_bounding

test_basic: $(BUILD_DIR)/test_rect_basic_methods.out
	@echo "▶ Running test_rect_basic_methods..."
	@./$(BUILD_DIR)/test_rect_basic_methods.out && echo "✓ Passed" || echo "✗ Failed"

test_properties: $(BUILD_DIR)/test_rect_properties.out
	@echo "▶ Running test_rect_properties..."
	@./$(BUILD_DIR)/test_rect_properties.out && echo "✓ Passed" || echo "✗ Failed"

test_operations: $(BUILD_DIR)/test_rect_operations.out
	@echo "▶ Running test_rect_operations..."
	@./$(BUILD_DIR)/test_rect_operations.out && echo "✓ Passed" || echo "✗ Failed"

test_bounding: $(BUILD_DIR)/test_bounding_rect.out
	@echo "▶ Running test_bounding_rect..."
	@./$(BUILD_DIR)/test_bounding_rect.out && echo "✓ Passed" || echo "✗ Failed"

# === Общая цель: запустить все тесты ===
test: test_basic test_properties test_operations test_bounding
	@echo ""
	@echo "🎉 All tests completed!"