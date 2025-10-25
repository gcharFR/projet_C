# the compiler:
CC = gcc

# compiler flags:
# -O : as we use space to leverage the space-time tradeoff we should probably
#    optimize speed
#-W options: turn on most, but not all, compiler warnings
# -DDEBUG: activates the display of additional runtime information, if set
# -DMAXPASSWORDLENGTH=<value>: this value should be >= the maximum length of
#    passwords that may be encountered in the dictionary files
CFLAGS = -O3 -Wall -Wextra -DDEBUG -DMAXPASSWORDLENGTH=100

# library linker flags:
# -lcrypto : libcrypto library from the OpenSSL project
LDLIBS = -lcrypto

all: precomputed_hash_table

precomputed_hash_table: precomputed_hash_table.o generate_mode.o compute_hash_value.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
	ln -f precomputed_hash_table ../

precomputed_hash_table.o: precomputed_hash_table.c generate_mode.h
	$(CC) $(CFLAGS) -c precomputed_hash_table.c

generate_mode.o: generate_mode.c generate_mode.h compute_hash_value.h
	$(CC) $(CFLAGS) -c generate_mode.c

compute_hash_value.o: compute_hash_value.c compute_hash_value.h
	$(CC) $(CFLAGS) -c compute_hash_value.c

# Remove all the files not necessary once the build is complete:
build-clean:
	rm -f *.o

# Remove every temporary, backup or generated file:
dist-clean: build-clean
	rm -f *~ ../*~
	rm -f precomputed_hash_table ../precomputed_hash_table