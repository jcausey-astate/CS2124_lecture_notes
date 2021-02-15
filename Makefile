.PHONY: check-git-clean
.PHONY: all
.PHONY: preview
.PHONY: drafts
.PHONY: push
.PHONY: build

all: build

build:
	@hugo

preview:
	hugo serve --buildDrafts

drafts:
	@hugo list drafts

push: build check-git-clean
	@echo "Pushing..."
	@git push origin master

check-git-clean: build
	@git diff --quiet || { echo; echo "Git tree not clean."; echo ; git status; echo; false; }
