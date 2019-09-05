#!/bin/bash

compare() {

	./ft_ls $@ > test1 ;
	ls $@ > test2 ;
	diff -w test1 test2;
	#rm -rf test1 test2;
}

#compare src;
#compare src objs;
#compare -R test/;
#compare .. ;
#compare -R zDHEFQJ;
#compare -R auteur ft_ls Makefile test/;
#compare test -Ra;

exit 0;