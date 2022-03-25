$(OBJECTS)

# 會立即展開右邊的值 
:=
# 編譯之前，執行一些shell命令
SHELL_HACK := $(shell mkdir -p BUILD)

FOO ?= bar
CFLAGS = -Wall -g
CFLAGS += -O2

$@
$*

$<
$^

%.c

CC = gcc
OBJs = a.o b.o c.o

TARGET: dependencies

# 指定該項目為fake項目, 跳過檢查dependencies是否up-to-data
.PHONY: clean
