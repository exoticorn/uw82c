C_FILES := $(wildcard *.c)

uw8-cart: $(C_FILES) $(wildcard *.h)
	gcc -O2 -lm -lSDL2 -o uw8-cart $(C_FILES)
