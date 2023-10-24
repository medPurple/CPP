SUBDIRS = CPP00 CPP01 CPP02 CPP03 CPP04

.PHONY: all clean fclean re $(SUBDIRS)

all:

clean:

fclean: $(SUBDIRS)

re: all

$(SUBDIRS):
	@echo "Cleaning in $@"
	@$(MAKE) -s -C $@ fclean

.PHONY: all clean fclean re
