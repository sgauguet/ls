#!/bin/bash

compare() {

	./ft_ls "$@" >& test1 ;
	ls "$@" >& test2 ;
	diff -w test1 test2;
	#rm -rf test1 test2;
}

# Check arguments parsing
compare src;
compare src objs;
compare -R test/;
compare .. ;
compare -R auteur ft_ls Makefile test/ src objs/;
compare -R auteur ft_ls Makefile test/ src objs/ src/main.c src/sort.c ;
compare ;
compare . ;
compare -R libft src/ objs/ ;
compare . .. . .. . .. . .. ;

# Check -a option
compare -aR auteur ft_ls Makefile test/ src objs/;
compare -Ra auteur ft_ls Makefile test/ src objs/ src/main.c src/sort.c ;
compare -a . .. . .. . .. . .. ;

# Check -r option
compare -aRr auteur ft_ls Makefile test/ src objs/;
compare -Rar auteur ft_ls Makefile test/ src objs/ src/main.c src/sort.c ;
compare -ar . .. . .. . .. . .. ;
compare -rR src ;


# Check errors
#compare -R zDHEFQJ;
#compare -R /var/run;

# Check options
#compare -l libft;
#compare -aR;
#compare -r libft/;
#compare -t libft;
#compare -u libft/;
#compare -g libft/;
#compare -Rd;
#compare -d ..;
#compare -d src ../ft_ls objs/;

# Check multiple options
#compare -atu libft;
#compare -r -d -t libft;
#compare -al libft;
#compare -alrt libft;
#compare -ut libft;
#compare -udla libft;

#Check invalid option
#compare -+ ft_ls;

#Check big folder
#compare -R /usr/share/man/man3/;

exit 0;