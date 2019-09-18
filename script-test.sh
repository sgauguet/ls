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
compare -aR .. ;

# Check -r option
compare -aRr auteur ft_ls Makefile test/ src objs/;
compare -Rar auteur ft_ls Makefile test/ src objs/ src/main.c src/sort.c ;
compare -ar . .. . .. . .. . .. ;
compare -rR src ;
compare -rRa src ;
compare -rrrrRRRRrraaaaaaaa libft ;

#Check -t option
compare -t libft/;
compare -aRrt auteur ft_ls Makefile test/ src objs/;
compare -Rart auteur ft_ls Makefile test/ src objs/ src/main.c src/sort.c ;
compare -art . .. . .. . .. . .. ;
compare -rRt src ;
compare -rRat src ;
compare -rrrrRRRRrraaaaaaaatttttt libft;

#Check -d option
compare -dR libft/;
compare -dt libft/;
compare -adRrt auteur ft_ls Makefile test/ src objs/;
compare -Radrt auteur ft_ls Makefile test/ src objs/ src/main.c src/sort.c ;
compare -ardt . .. . .. . .. . .. ;
compare -rRdt src ;
compare -rRdat src ;
compare -rrdrrRRRRrraaaaaaadddddatttttddddt libft;

#Check -l option
compare -l src;
compare -l src/ objs auteur Makefile;
compare -laR libft ;
compare -laR /Users/sgauguet/Library/Containers/com.apple.CalendarAgent/Data/Library/Preferences/ByHost;

# Check multiple options
compare -at libft;
compare -r -d -t libft;
compare -al libft;
compare -alrt libft;
compare -t libft;
compare -dla libft;

#Check invalid option
compare -+ ft_ls;
compare -8525 src/;
compare -$$$$$$ -R libft;

# Check errors
compare -R zDHEFQJ;
#compare -R /Users/sgauguet/.DocumentRevisions-V100;

exit 0;
