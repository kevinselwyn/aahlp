NAME    := aahlp
BUILD   := build
TEST    := test
EXEC    := $(BUILD)/$(NAME)
BIN_DIR := /usr/local/bin

all: build

build: $(NAME).c
	mkdir -p $(BUILD)
	gcc -Wall -Wextra -o $(EXEC) $<

test: build
	./$(EXEC) $(TEST)/romeo.txt

install: build
	install -m 0755 $(EXEC) $(BIN_DIR)

uninstall:
	rm -f $(BIN_DIR)/$(NAME)

clean:
	rm -r $(BUILD) $(TEST)/*.ttx
