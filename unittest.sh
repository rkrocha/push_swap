#!/bin/bash

source assert.sh
make || exit 1

fail=0
optm=0
pass=0

test_ok()
{
	check="$(./push_swap $1 | ./checker_linux $1)"
	assert_eq $check "OK" "Fail with args '$1'" && ((++pass)) || ((++fail))
	if [ "$2" ]
	then
		(($(./push_swap $1 | wc -l) > $2)) && \
			echo ${YELLOW}"Case with args '$1' may need optimization" && \
			((++optm)) && ((--pass))
	fi
}


test_ok "0" 0
test_ok "1" 0
test_ok "-1" 0
test_ok "-2147483648" 0
test_ok "2147483647" 0


test_ok "0 1" 1
test_ok "1 0" 1
test_ok "1 -1" 1
test_ok "-1 1" 1
test_ok "2147483647 -2147483648" 1
test_ok "-2147483648 2147483647" 1


test_ok "1 2 3" 3
test_ok "1 3 2" 3
test_ok "2 3 1" 3
test_ok "2 1 3" 3
test_ok "3 1 2" 3
test_ok "3 2 1" 3


test_ok "1 2 3 4" 12
test_ok "1 2 4 3" 12
test_ok "1 3 2 4" 12
test_ok "1 3 4 2" 12
test_ok "1 4 2 3" 12
test_ok "1 4 3 2" 12
test_ok "2 1 3 4" 12
test_ok "2 1 4 3" 12
test_ok "2 3 1 4" 12
test_ok "2 3 4 1" 12
test_ok "2 4 1 3" 12
test_ok "2 4 3 1" 12
test_ok "3 1 2 4" 12
test_ok "3 1 4 2" 12
test_ok "3 2 1 4" 12
test_ok "3 2 4 1" 12
test_ok "3 4 1 2" 12
test_ok "3 4 2 1" 12
test_ok "4 1 2 3" 12
test_ok "4 1 3 2" 12
test_ok "4 2 1 3" 12
test_ok "4 2 3 1" 12
test_ok "4 3 1 2" 12
test_ok "4 3 2 1" 12


test_ok "1 2 3 4 5" 12
test_ok "1 2 3 5 4" 12
test_ok "1 2 4 3 5" 12
test_ok "1 2 4 5 3" 12
test_ok "1 2 5 3 4" 12
test_ok "1 2 5 4 3" 12
test_ok "1 3 2 4 5" 12
test_ok "1 3 2 5 4" 12
test_ok "1 3 4 2 5" 12
test_ok "1 3 4 5 2" 12
test_ok "1 3 5 2 4" 12
test_ok "1 3 5 4 2" 12
test_ok "1 4 2 3 5" 12
test_ok "1 4 2 5 3" 12
test_ok "1 4 3 2 5" 12
test_ok "1 4 3 5 2" 12
test_ok "1 4 5 2 3" 12
test_ok "1 4 5 3 2" 12
test_ok "1 5 2 3 4" 12
test_ok "1 5 2 4 3" 12
test_ok "1 5 3 2 4" 12
test_ok "1 5 3 4 2" 12
test_ok "1 5 4 2 3" 12
test_ok "1 5 4 3 2" 12
test_ok "2 1 3 4 5" 12
test_ok "2 1 3 5 4" 12
test_ok "2 1 4 3 5" 12
test_ok "2 1 4 5 3" 12
test_ok "2 1 5 3 4" 12
test_ok "2 1 5 4 3" 12
test_ok "2 3 1 4 5" 12
test_ok "2 3 1 5 4" 12
test_ok "2 3 4 1 5" 12
test_ok "2 3 4 5 1" 12
test_ok "2 3 5 1 4" 12
test_ok "2 3 5 4 1" 12
test_ok "2 4 1 3 5" 12
test_ok "2 4 1 5 3" 12
test_ok "2 4 3 1 5" 12
test_ok "2 4 3 5 1" 12
test_ok "2 4 5 1 3" 12
test_ok "2 4 5 3 1" 12
test_ok "2 5 1 3 4" 12
test_ok "2 5 1 4 3" 12
test_ok "2 5 3 1 4" 12
test_ok "2 5 3 4 1" 12
test_ok "2 5 4 1 3" 12
test_ok "2 5 4 3 1" 12
test_ok "3 1 2 4 5" 12
test_ok "3 1 2 5 4" 12
test_ok "3 1 4 2 5" 12
test_ok "3 1 4 5 2" 12
test_ok "3 1 5 2 4" 12
test_ok "3 1 5 4 2" 12
test_ok "3 2 1 4 5" 12
test_ok "3 2 1 5 4" 12
test_ok "3 2 4 1 5" 12
test_ok "3 2 4 5 1" 12
test_ok "3 2 5 1 4" 12
test_ok "3 2 5 4 1" 12
test_ok "3 4 1 2 5" 12
test_ok "3 4 1 5 2" 12
test_ok "3 4 2 1 5" 12
test_ok "3 4 2 5 1" 12
test_ok "3 4 5 1 2" 12
test_ok "3 4 5 2 1" 12
test_ok "3 5 1 2 4" 12
test_ok "3 5 1 4 2" 12
test_ok "3 5 2 1 4" 12
test_ok "3 5 2 4 1" 12
test_ok "3 5 4 1 2" 12
test_ok "3 5 4 2 1" 12
test_ok "4 1 2 3 5" 12
test_ok "4 1 2 5 3" 12
test_ok "4 1 3 2 5" 12
test_ok "4 1 3 5 2" 12
test_ok "4 1 5 2 3" 12
test_ok "4 1 5 3 2" 12
test_ok "4 2 1 3 5" 12
test_ok "4 2 1 5 3" 12
test_ok "4 2 3 1 5" 12
test_ok "4 2 3 5 1" 12
test_ok "4 2 5 1 3" 12
test_ok "4 2 5 3 1" 12
test_ok "4 3 1 2 5" 12
test_ok "4 3 1 5 2" 12
test_ok "4 3 2 1 5" 12
test_ok "4 3 2 5 1" 12
test_ok "4 3 5 1 2" 12
test_ok "4 3 5 2 1" 12
test_ok "4 5 1 2 3" 12
test_ok "4 5 1 3 2" 12
test_ok "4 5 2 1 3" 12
test_ok "4 5 2 3 1" 12
test_ok "4 5 3 1 2" 12
test_ok "4 5 3 2 1" 12
test_ok "5 1 2 3 4" 12
test_ok "5 1 2 4 3" 12
test_ok "5 1 3 2 4" 12
test_ok "5 1 3 4 2" 12
test_ok "5 1 4 2 3" 12
test_ok "5 1 4 3 2" 12
test_ok "5 2 1 3 4" 12
test_ok "5 2 1 4 3" 12
test_ok "5 2 3 1 4" 12
test_ok "5 2 3 4 1" 12
test_ok "5 2 4 1 3" 12
test_ok "5 2 4 3 1" 12
test_ok "5 3 1 2 4" 12
test_ok "5 3 1 4 2" 12
test_ok "5 3 2 1 4" 12
test_ok "5 3 2 4 1" 12
test_ok "5 3 4 1 2" 12
test_ok "5 3 4 2 1" 12
test_ok "5 4 1 2 3" 12
test_ok "5 4 1 3 2" 12
test_ok "5 4 2 1 3" 12
test_ok "5 4 2 3 1" 12
test_ok "5 4 3 1 2" 12
test_ok "5 4 3 2 1" 12
test_ok "2147483647 -1 0 1 -2147483648" 12

echo
norminette &>/dev/null || echo ${RED}Norme error!
echo ${RED}KO: $fail
echo ${YELLOW}OP: $optm
echo ${GREEN}OK: $pass