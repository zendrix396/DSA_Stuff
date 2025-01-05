#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <libgen.h>
void remove_exe_files(const char *self_name)
{
    DIR *dir;
    struct dirent *entry;
    char *ext;

    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Error opening current directory\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        ext = strrchr(entry->d_name, '.');

        if (ext && strcmp(ext, ".exe") == 0)
        {
            if (strcmp(entry->d_name, self_name) != 0)
            {
                printf("Removing: %s\n", entry->d_name);
                if (remove(entry->d_name) == 0)
                {
                    printf("Successfully removed %s\n", entry->d_name);
                }
                else
                {
                    printf("Failed to remove %s\n", entry->d_name);
                }
            }
            else
            {
                printf("Skipping self: %s\n", entry->d_name);
            }
        }
    }

    closedir(dir);
}
int main(int argc, char *argv[])
{
    char *self_name = basename(argv[0]);
    printf("Self name: %s\n", self_name);

    remove_exe_files(self_name);
    return 0;
}