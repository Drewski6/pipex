#!/usr/bin/bash
WORKING="../pipex_working/"
TESTING="../pipex_testing/"
ARGS="argument_testing_arguments.txt"

cd $WORKING
rm -f ${WORKING}valgrind.log
rm -f ${TESTING}valgrind.log
make fclean
make bonus

echo "hi" > file1
echo "lkjlkj" >> file1
echo "pipex testing" >> file1

# not enough arguments
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat wc &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat wc &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log

# 4 good commands, the 16 commands with errors
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "cat -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "catlkj -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "cat -e" "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "catlkj -e" "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 catlkj "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 catlkj "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "cat -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "catlkj -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "cat -e" wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 "catlkj -e" wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 catlkj wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 cat wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex_bonus file1 catlkj wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
# save as above but now with trace children
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "cat -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "catlkj -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "cat -e" "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "catlkj -e" "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 catlkj "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 catlkj "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "cat -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "catlkj -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "cat -e" wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 "catlkj -e" wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 catlkj wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 cat wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1 catlkj wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
# testing invalid infiles
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk cat "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "cat -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk cat wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "catlkj -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "cat -e" "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "catlkj -e" "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk cat "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk catlkj "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk cat "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk catlkj "/usr/bin/wclkj -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "cat -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "catlkj -e" wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "cat -e" wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk "catlkj -e" wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk cat wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk catlkj wc file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk cat wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log
rm -f file8 && valgrind --trace-children=yes --leak-check=full ./pipex_bonus file1lk catlkj wclkj file8 &>> valgrind.log && cat file8 &>> valgrind.log && echo "" &>> valgrind.log

#rm -f file8 && valgrind --track-fds=all --leak-check=full ./pipex file1lksjdlkfj "cat -e" "/usr/bin/wc -l" file8 &>> valgrind.log && cat file8 &>> valgrind.log

echo -n "Total runs		:---------------: " && cat valgrind.log | grep ^== | awk '{print $1}' | sort | uniq | wc -l
echo -n "Good Valgrind Runs	: Memory	: " && cat valgrind.log | grep "All heap blocks were freed" | wc -l
echo -n "Good Valgrind Runs	: fds		: " && cat valgrind.log | grep "FILE DESCRIPTORS: 0 open (0 std) at exit" | wc -l
echo -n "BAD Valgrind Runs	: fds		: " && cat valgrind.log | grep "Bad file descriptor" | wc -l
echo -n "BAD Valgrind Runs	: Cond J	: " && cat valgrind.log | grep "Conditional jump or move" | wc -l
echo -n "BAD Valgrind Runs	: SIG		: " && cat valgrind.log | grep "Process terminating" | wc -l

mv valgrind.log ${TESTING}
