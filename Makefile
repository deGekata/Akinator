# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++

#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS = -g -std=c++17 -Wall -Wextra -Weffc++ -Wc++0x-compat -Wc++11-compat -Wc++14-compat 
CFLAGS += -Waggressive-loop-optimizations -Walloc-zero -Walloca -Walloca-larger-than=8192 -Warray-bounds 
CFLAGS += -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy 
CFLAGS += -Wdangling-else -Wduplicated-branches -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security 
CFLAGS += -Wformat-signedness -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Winline -Wlarger-than=8192 
CFLAGS += -Wvla-larger-than=8192 -Wlogical-op -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd 
CFLAGS += -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wrestrict -Wshadow -Wsign-promo 
CFLAGS += -Wstack-usage=8192 -Wstrict-null-sentinel -Wstrict-overflow=2 -Wstringop-overflow=4 
CFLAGS += -Wsuggest-attribute=noreturn -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum 
CFLAGS += -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-literal-suffix 
CFLAGS += -Wno-missing-field-initializers -Wnarrowing -Wno-old-style-cast -Wvarargs -Waligned-new 
CFLAGS += -Walloc-size-larger-than=1073741824 -Walloc-zero -Walloca -Walloca-larger-than=8192 -Wcast-align=strict 
CFLAGS += -Wdangling-else -Wduplicated-branches -Wformat-overflow=2 -Wformat-truncation=2 -Wmissing-attributes 
CFLAGS += -Wmultistatement-macros -Wrestrict -Wshadow=global -Wsuggest-attribute=malloc -fcheck-new 
CFLAGS += -fsized-deallocation -fstrict-overflow  
CFLAGS +=  -flto-odr-type-merging -fno-omit-frame-pointer


BuildF="Build/"

all: clean 1000-7



1000-7: Ghoulinator.o Ghoul_tools.o main.o
	$(CC) $(BuildF)Ghoulinator.o $(BuildF)main.o $(BuildF)Ghoul_tools.o -o Ghoul.out


Ghoul_tools.o: 
	$(CC) -c $(CFLAGS) src/Ghoul_tools.cpp -o  $(BuildF)Ghoul_tools.o


Ghoulinator.o: 
	$(CC) -c $(CFLAGS) src/Ghoulinator.cpp -o  $(BuildF)Ghoulinator.o

main.o:
	$(CC) -c $(CFLAGS) src/main.cpp -o  $(BuildF)main.o


clean:
	rm -rf $(BuildF)*.o

#ASSembler:
#	$(CC)  -lSDL2 -lSDL2main -o ASSembler

#g++ ASSembler/ASSembler.cpp ASSembler/Lexer.cpp ASSembler/main.cpp Shared/Shared.cpp Libs/StringLib/StringFileParser.cpp -o ASSembler.out