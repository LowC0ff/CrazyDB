//BASE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//TYPES
#include <stdbool.h>
#include <sys/types.h>
#include <stdint.h>

//FILES
#include <fcntl.h>
#include <sys/stat.h>

//STRUCTURE
struct s_generic {
    int i1, i2;
    float f1, f2;
    long long int l1, l2;
    double d1, d2;
};

//STRUCTURE SIZES
const unsigned char t_generic = sizeof(struct s_generic);

//INSERT LINE
int insere_linha(char *file, void *line, int size){
    //OPEN FILE
    int table_fd = open(file, O_APPEND|O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);

    //WRITE LINE
    ssize_t num_bytes = write(table_fd, line, size);

    //CLOSED FILE
    close(table_fd);

    //RETURN STATUS OF WRITE
};