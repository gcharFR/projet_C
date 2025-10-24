# the compiler:
CC = gcc

# compiler flags:
#-W options turn on most, but not all, compiler warnings
# -lcrypto : libcrypto du projet OpenSSL
CFLAGS = -O3 -Wall -Wextra -lcrypto

# the build target executable:
TARGET = precomputed_hash_table

all: $(TARGET)

$(TARGET): $(TARGET).o generate_mode.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o generate_mode.o
	mv $(TARGET) ../

$(TARGET).o: $(TARGET).c generate_mode.h
	$(CC) $(CFLAGS) -c $(TARGET).c

generate_mode.o: generate_mode.c generate_mode.h
	$(CC) $(CFLAGS) -c generate_mode.c

clean:
	rm -f *.o

clean-all: clean
	rm -f ../$(TARGET)