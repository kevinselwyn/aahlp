NAME  := aahlp
BUILD := build
TEST  := test
EXEC  := $(BUILD)/$(NAME)

all: build

build: $(NAME).c
	mkdir -p $(BUILD)
	gcc -Wall -Wextra -o $(EXEC) $<

test: build
	./$(EXEC) $(TEST)/romeo.txt

clean:
	rm -r $(BUILD) $(TEST)/*.ttx