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
struct s_table {
    void *data, *finally;
    int size;
    int num_line;
    bool erro;
};

struct s_line {
    void *data;
    int size;
};

struct s_generic {
    int i1, i2;
    float f1, f2;
    long long int l1, l2;
    double d1, d2;
};

//STRUCTURE SIZES
const unsigned char t_generic = sizeof(struct s_generic);

//INSERT LINE
int insert_line(char *file, void *line, int size){
    //OPEN FILE
    int table_fd = open(file, O_APPEND|O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);

    //WRITE LINE
    ssize_t num_bytes = write(table_fd, line, size);

    //CLOSED FILE
    close(table_fd);

    //RETURN STATUS OF WRITE
    return num_bytes;
};

    //MAIN
    int main(){
        struct s_generic gen = { 0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};
        insert_line("table_generic", &gen, t_generic);
        return 0;
    };