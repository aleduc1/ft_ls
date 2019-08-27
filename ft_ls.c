/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:49:13 by aleduc            #+#    #+#             */
/*   Updated: 2018/07/18 18:16:28 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_devs(struct stat *buff, t_struct **data)
{
	(*data)->minor = minor(buff->st_rdev);
	(*data)->major = major(buff->st_rdev);
	(*data)->flag_dev = 1;
}

void	put_types(struct stat *buff, t_struct **data)
{
	if ((buff->st_mode & 0170000) == 0100000)
		(*data)->types = "Fichier";
	else if ((buff->st_mode & 0170000) == 0040000)
		(*data)->types = "Dossier";
	else if ((buff->st_mode & 0170000) == 0120000)
		(*data)->types = "SymLink";
	else if ((buff->st_mode & 0170000) == 0140000)
		(*data)->types = "Socket";
	else if ((buff->st_mode & 0170000) == 0060000)
	{
		(*data)->types = "SpecialBlock";
		put_devs(buff, data);
	}
	else if ((buff->st_mode & 0170000) == 0010000)
		(*data)->types = "FIFO";
	else if ((buff->st_mode & 0170000) == 0020000)
	{
		(*data)->types = "CharacSpecial";
		put_devs(buff, data);
	}
	else if ((buff->st_mode & 0170000) == 0160000)
		(*data)->types = "Whiteout";
}

void	put_modes(struct stat *buff, t_struct **data)
{
	(*data)->mode = ft_memalloc(sizeof(char) * 10);
	(*data)->mode[9] = '\0';
	(*data)->mode[0] = (buff->st_mode & S_IRUSR) ? 'r' : '-';
	(*data)->mode[1] = (buff->st_mode & S_IWUSR) ? 'w' : '-';
	(*data)->mode[2] = (buff->st_mode & S_IXUSR) ? 'x' : '-';
	(*data)->mode[3] = (buff->st_mode & S_IRGRP) ? 'r' : '-';
	(*data)->mode[4] = (buff->st_mode & S_IWGRP) ? 'w' : '-';
	(*data)->mode[5] = (buff->st_mode & S_IXGRP) ? 'x' : '-';
	(*data)->mode[6] = (buff->st_mode & S_IROTH) ? 'r' : '-';
	(*data)->mode[7] = (buff->st_mode & S_IWOTH) ? 'w' : '-';
	(*data)->mode[8] = (buff->st_mode & S_IXOTH) ? 'x' : '-';
	if (buff->st_mode & S_ISUID)
		(*data)->mode[2] = ((*data)->mode[2] == '-') ? 'S' : 's';
	if (buff->st_mode & S_ISGID)
		(*data)->mode[5] = ((*data)->mode[5] == '-') ? 'S' : 's';
	if (buff->st_mode & S_ISVTX)
		(*data)->mode[8] = ((*data)->mode[8] == '-') ? 'T' : 't';
}

void	put_data(struct stat *buff, t_struct **data, char *path, char *name)
{
	(*data)->path = ft_strdup(path);
	(*data)->name = ft_strdup(name);
	(*data)->minor = 0;
	(*data)->major = 0;
	(*data)->flag_dev = 0;
	(*data)->nlinks = (unsigned long)buff->st_nlink;
	(*data)->size = (unsigned long)buff->st_size;
	(*data)->blocks = (unsigned long)buff->st_blocks;
	(*data)->timestamp = buff->st_mtimespec.tv_sec;
}

int		put_uids(struct stat *buff, struct passwd **pwd, struct group **grp)
{
	*pwd = getpwuid(buff->st_uid);
	if (*pwd == NULL)
	{
		ft_putendl("mon pwd est null");
		return (2);
	}
	else
	{
		*grp = getgrgid(buff->st_gid);
		if (*grp == NULL)
		{
			ft_putendl("mon pwd est null");
			return (2);
		}
	}
	return (0);
}
