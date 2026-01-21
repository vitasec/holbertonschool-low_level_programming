#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_ident(unsigned char *e_ident);
void print_osabi_type(unsigned char *e_ident, unsigned int e_type);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/**
 * check_elf - Faylın ELF olub olmadığını yoxlayır.
 * @e_ident: ELF identifikator massivi.
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' &&
		    e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_ident - Magic, Class, Data və Version çap edir.
 * @e_ident: ELF identifikator massivi.
 */
void print_ident(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("none\n");
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");
	printf("  Version:                           %d\n",
		e_ident[EI_VERSION]);
}

/**
 * print_osabi_type - OS/ABI və Fayl tipini çap edir.
 * @e_ident: ELF identifikator massivi.
 * @e_type: ELF tipi.
 */
void print_osabi_type(unsigned char *e_ident, unsigned int e_type)
{
	printf("  OS/ABI:                            ");
	if (e_ident[EI_OSABI] == ELFOSABI_NONE || e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (None)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);
}

/**
 * print_entry - Giriş nöqtəsinin ünvanını çap edir.
 * @e_entry: Ünvan.
 * @e_ident: ELF identifikator massivi.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * main - ELF başlığını oxuyur.
 * @argc: Arqument sayı.
 * @argv: Arqument massivi.
 * Return: 0.
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr *h;
	int fd, r;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	h = malloc(sizeof(Elf64_Ehdr));
	if (!h)
	{
		close(fd);
		exit(98);
	}
	r = read(fd, h, sizeof(Elf64_Ehdr));
	if (r < (int)sizeof(Elf64_Ehdr))
	{
		free(h);
		close(fd);
		exit(98);
	}
	check_elf(h->e_ident);
	printf("ELF Header:\n");
	print_ident(h->e_ident);
	print_osabi_type(h->e_ident, h->e_type);
	print_entry(h->e_entry, h->e_ident);
	free(h);
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
	return (0);
}
