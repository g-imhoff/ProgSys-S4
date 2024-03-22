#include "base.h"
#include "cp_std.h"
#include "raler.h"

void cp_std(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "r");
    raler_null("n'as pas reussi à ouvrir le fichier1", (void*)f1);
    FILE* f2 = fopen(file2, "w");
    raler_null("n'as pas reussi à ouvrir le fichier2", (void*)f2);

    char buffer;
    size_t nbr_bytes_read;
    while ((nbr_bytes_read = fread(&buffer, sizeof(char), 1, f1)) >= 1) {
        raler("N'as pas reussi à lire", (int)nbr_bytes_read);
        size_t nbr_bytes_write = fwrite(&buffer, sizeof(char), 1, f2);
        raler("N'as pas reussi à écrire", (int)nbr_bytes_write);
    }

    fclose(f1);
    fclose(f2);
}