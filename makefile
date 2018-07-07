CC=x86_64-w64-mingw32-gcc
OUT_DIR=bin

all: $(OUT_DIR)/pasterboy.exe

clean:
	rm -rf $(OUT_DIR)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(OUT_DIR)/pasterboy.exe: $(OUT_DIR) src/main.c
	$(CC) src/main.c -o $(OUT_DIR)/pasterboy.exe

