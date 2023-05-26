char** _getenv(char *envp) {

    char** env_array;
    int i = 0;
    int count = 0;
    char** env = envp;


    // Count the number of environment variables
    while (*env != NULL) {
        count++;
        env++;
    }

    // Allocate memory for the array of environment variables
    env_array = (char**)malloc((count + 1) * sizeof(char*));
    if (env_array == NULL) {
        perror("Memory allocation failed");
    }

    // Copy environment variables to the array
    env = envp;

    while (*env != NULL) {
        int length = strlen(*env);
        env_array[i] = (char*)malloc((length + 1) * sizeof(char));
        if (env_array[i] == NULL) {
            perror("Memory allocation failed. ");
        }

        strncpy(env_array[i], *env, length);
        env_array[i][length] = '\0';
        env++;
        i++;
    }
    env_array[count] = NULL;

    return env_array;
}
