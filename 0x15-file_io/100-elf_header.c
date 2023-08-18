#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 64

void print_error(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

void display_elf_header(const Elf64_Ehdr *elf_header)
{
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x%c", elf_header->e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');
    }
    printf("  Class:                             ");
    switch (elf_header->e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("None\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown>\n");
    }
    printf("  Data:                              ");
    switch (elf_header->e_ident[EI_DATA])
    {
        case ELFDATANONE: printf("None\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n");
    }
    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        /* Add more OS/ABI values here as needed */
        default: printf("<unknown: %d>\n", elf_header->e_ident[EI_OSABI]);
    }
    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (elf_header->e_type)
    {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown>\n");
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[])
{
    const char *filename;
    int fd;
    Elf64_Ehdr elf_header;
    ssize_t read_bytes;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        print_error("Error opening file");
    }

    read_bytes = read(fd, &elf_header, sizeof(elf_header));
    if (read_bytes != sizeof(elf_header))
    {
        close(fd);
        print_error("Error reading ELF header");
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3)
    {
        close(fd);
        print_error("Not an ELF file");
    }

    display_elf_header(&elf_header);

    close(fd);
    return 0;
}
