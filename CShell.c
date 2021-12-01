int EXIT_SUCCESS = 0

int main(int argc, char **argv){
    //Load config files, if any.

    //Run command loop.
    lsh_loop();

    //Perform any shutdown /cleanup.

    return EXIT_SUCCESS;
}

void lsh_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf("> ");
        line = lsh_readline();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    }  while (status);
}