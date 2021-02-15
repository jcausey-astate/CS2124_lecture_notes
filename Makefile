all: 
	hugo

preview:
	hugo serve --buildDrafts

drafts:
	@hugo list drafts

push:
	@hugo
	@echo
	res="$$(git status -s)"

ifeq ($res,)
	@echo "Pushing"; git push origin master;
else
	@echo "Git tree not clean." ; echo ; git status;
endif

