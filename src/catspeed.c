#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define DATA_DIR "/usr/share/catspeed"

static void trim_newline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

static int is_directory(const char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
        return 0;

    return S_ISDIR(st.st_mode);
}

static void list_directory(const char *path)
{
    DIR *dir = opendir(path);

    if (!dir)
    {
        perror("catspeed");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        char fullpath[1024];

        snprintf(
            fullpath,
            sizeof(fullpath),
            "%s/%s",
            path,
            entry->d_name
        );

        if (is_directory(fullpath))
            printf("[DIR]  %s\n", entry->d_name);
        else
            printf("       %s\n", entry->d_name);
    }

    closedir(dir);
}

static void print_file(const char *path)
{
    FILE *fp = fopen(path, "r");

    if (!fp)
    {
        perror("catspeed");
        return;
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp))
        printf("%s", buffer);

    fclose(fp);
}

static void interactive_mode(void)
{
    char semester[256];
    char subject[256];
    char program[256];

    printf("\n");
    printf("====================================\n");
    printf("          CATSPEED LAB CLI\n");
    printf("====================================\n");

    while (1)
    {
        printf("\nAvailable Semesters:\n\n");

        list_directory(DATA_DIR);

        printf("\nEnter semester or 'q' to quit: ");

        if (!fgets(semester, sizeof(semester), stdin))
            break;

        trim_newline(semester);

        if (strcmp(semester, "q") == 0)
            break;

        char semester_path[1024];

        snprintf(
            semester_path,
            sizeof(semester_path),
            "%s/%s",
            DATA_DIR,
            semester
        );

        if (!is_directory(semester_path))
        {
            printf("Semester not found.\n");
            continue;
        }

        printf("\nSubjects:\n\n");

        list_directory(semester_path);

        printf("\nEnter subject: ");

        fgets(subject, sizeof(subject), stdin);
        trim_newline(subject);

        char subject_path[1024];

        snprintf(
            subject_path,
            sizeof(subject_path),
            "%s/%s",
            semester_path,
            subject
        );

        if (!is_directory(subject_path))
        {
            printf("Subject not found.\n");
            continue;
        }

        printf("\nPrograms:\n\n");

        list_directory(subject_path);

        printf("\nEnter program filename: ");

        fgets(program, sizeof(program), stdin);
        trim_newline(program);

        char program_path[1024];

        snprintf(
            program_path,
            sizeof(program_path),
            "%s/%s",
            subject_path,
            program
        );

        struct stat st;

        if (stat(program_path, &st) != 0 ||
            !S_ISREG(st.st_mode))
        {
            printf("Program not found.\n");
            continue;
        }

        printf("\n");
        printf("====================================\n");
        printf("%s\n", program);
        printf("====================================\n\n");

        print_file(program_path);

        printf("\n====================================\n");
    }
}

static void usage(void)
{
    printf(
        "Catspeed - College Lab Program CLI\n\n"
        "Usage:\n"
        "  catspeed          Interactive mode\n"
        "  catspeed list     List semesters\n"
        "  catspeed path     Show data directory\n"
        "  catspeed help     Show help\n"
    );
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        interactive_mode();
        return 0;
    }

    if (strcmp(argv[1], "list") == 0)
    {
        list_directory(DATA_DIR);
        return 0;
    }

    if (strcmp(argv[1], "path") == 0)
    {
        printf("%s\n", DATA_DIR);
        return 0;
    }

    if (strcmp(argv[1], "help") == 0 ||
        strcmp(argv[1], "--help") == 0 ||
        strcmp(argv[1], "-h") == 0)
    {
        usage();
        return 0;
    }

    printf("Unknown command: %s\n\n", argv[1]);

    usage();

    return 1;
}
