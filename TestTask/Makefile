# Компилятор и его флаги
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Исходные файлы и цели сборки
SRCDIR = .
SRCFILES = main.cpp runner.cpp qam_modulator.cpp qam_demodulator.cpp blur.cpp 
OBJS = $(SRCFILES:.cpp=.o)
EXECUTABLE = test_task

# Правило для сборки исполняемого файла
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для компиляции .cpp файлов
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJS) $(EXECUTABLE)

# Указание фраз, которые не являются файлами
.PHONY: clean