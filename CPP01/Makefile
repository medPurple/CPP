SUBDIRS = ex00 ex01 ex02 ex03 ex04 ex05 ex06

.PHONY: all clean fclean re $(SUBDIRS)

all:

clean:

fclean: $(SUBDIRS)

re: all

$(SUBDIRS):
	@echo "Cleaning in $@"
	@$(MAKE) -s -C $@ fclean

.PHONY: all clean fclean re
