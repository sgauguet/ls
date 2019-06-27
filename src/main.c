/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/27 12:45:26 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	inspect_file(const char *filename) {
	t_stat buf;

	if (filename == NULL || ft_strlen(filename) == 0)
		return 1;
	if (stat(filename, &buf) != 0)
		return 1;
	printf("Type de fichier :");
	switch (buf.st_mode & S_IFMT) {
		case S_IFBLK:  printf("périphérique de bloc\n");      break;
		case S_IFCHR:  printf("périphérique de caractère\n"); break;
		case S_IFDIR:  printf("répertoire\n");                break;
		case S_IFIFO:  printf("FIFO/tube\n");                 break;
		case S_IFLNK:  printf("lien symbolique\n");           break;
		case S_IFREG:  printf("fichier ordinaire\n");         break;
		case S_IFSOCK: printf("socket\n");                    break;
		default:       printf("inconnu ?\n");                 break;
	}
	printf("Numéro d'inœud : %ld\n", (long) buf.st_ino);
	printf("Mode : %lo (octal)\n", (unsigned long) buf.st_mode);
	printf("Nombre de liens : %ld\n", (long) buf.st_nlink);
	printf("Propriétaires : UID=%ld   GID=%ld\n", (long) buf.st_uid, (long) buf.st_gid);
	printf("Taille de bloc d’E/S : %ld octets\n", (long) buf.st_blksize);
	printf("Taille du fichier : %lld octets\n", (long long) buf.st_size);
	printf("Blocs alloués : %lld\n", (long long) buf.st_blocks);
	printf("Dernier changement d’état : %s", ctime(&buf.st_ctime));
	printf("Dernier accès au fichier : %s", ctime(&buf.st_atime));
	printf("Dernière modification du fichier:  %s", ctime(&buf.st_mtime));
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc > 1) {
		inspect_file(argv[1]);
		ft_printf("%s\n", "Ok");
	}
	return (1);
}
