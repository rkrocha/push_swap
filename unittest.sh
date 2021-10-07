#!/bin/bash

source assert.sh
make || exit 1

succ=0
fail=0
optm=0

test_ok()
{
	ops=$(./push_swap $1)
	check="$(./push_swap $1 | ./checker_linux $1)"
	assert_eq $check "OK" "Fail with args '$1'" && ((succ++)) || ((fail++))
}


test_ok "0"
test_ok "1"
test_ok "-1"
test_ok "-2147483648"
test_ok "2147483647"


test_ok "0 1"
test_ok "1 0"
test_ok "1 -1"
test_ok "-1 1"
test_ok "2147483647 -2147483648"
test_ok "-2147483648 2147483647"


test_ok "1 2 3"
test_ok "1 3 2"
test_ok "2 3 1"
test_ok "2 1 3"
test_ok "3 1 2"
test_ok "3 2 1"


test_ok "1 2 3 4"
test_ok "1 2 4 3"
test_ok "1 3 2 4"
test_ok "1 3 4 2"
test_ok "1 4 2 3"
test_ok "1 4 3 2"
test_ok "2 1 3 4"
test_ok "2 1 4 3"
test_ok "2 3 1 4"
test_ok "2 3 4 1"
test_ok "2 4 1 3"
test_ok "2 4 3 1"
test_ok "3 1 2 4"
test_ok "3 1 4 2"
test_ok "3 2 1 4"
test_ok "3 2 4 1"
test_ok "3 4 1 2"
test_ok "3 4 2 1"
test_ok "4 1 2 3"
test_ok "4 1 3 2"
test_ok "4 2 1 3"
test_ok "4 2 3 1"
test_ok "4 3 1 2"
test_ok "4 3 2 1"


test_ok "1 2 3 4 5"
test_ok "1 2 3 5 4"
test_ok "1 2 4 3 5"
test_ok "1 2 4 5 3"
test_ok "1 2 5 3 4"
test_ok "1 2 5 4 3"
test_ok "1 3 2 4 5"
test_ok "1 3 2 5 4"
test_ok "1 3 4 2 5"
test_ok "1 3 4 5 2"
test_ok "1 3 5 2 4"
test_ok "1 3 5 4 2"
test_ok "1 4 2 3 5"
test_ok "1 4 2 5 3"
test_ok "1 4 3 2 5"
test_ok "1 4 3 5 2"
test_ok "1 4 5 2 3"
test_ok "1 4 5 3 2"
test_ok "1 5 2 3 4"
test_ok "1 5 2 4 3"
test_ok "1 5 3 2 4"
test_ok "1 5 3 4 2"
test_ok "1 5 4 2 3"
test_ok "1 5 4 3 2"
test_ok "2 1 3 4 5"
test_ok "2 1 3 5 4"
test_ok "2 1 4 3 5"
test_ok "2 1 4 5 3"
test_ok "2 1 5 3 4"
test_ok "2 1 5 4 3"
test_ok "2 3 1 4 5"
test_ok "2 3 1 5 4"
test_ok "2 3 4 1 5"
test_ok "2 3 4 5 1"
test_ok "2 3 5 1 4"
test_ok "2 3 5 4 1"
test_ok "2 4 1 3 5"
test_ok "2 4 1 5 3"
test_ok "2 4 3 1 5"
test_ok "2 4 3 5 1"
test_ok "2 4 5 1 3"
test_ok "2 4 5 3 1"
test_ok "2 5 1 3 4"
test_ok "2 5 1 4 3"
test_ok "2 5 3 1 4"
test_ok "2 5 3 4 1"
test_ok "2 5 4 1 3"
test_ok "2 5 4 3 1"
test_ok "3 1 2 4 5"
test_ok "3 1 2 5 4"
test_ok "3 1 4 2 5"
test_ok "3 1 4 5 2"
test_ok "3 1 5 2 4"
test_ok "3 1 5 4 2"
test_ok "3 2 1 4 5"
test_ok "3 2 1 5 4"
test_ok "3 2 4 1 5"
test_ok "3 2 4 5 1"
test_ok "3 2 5 1 4"
test_ok "3 2 5 4 1"
test_ok "3 4 1 2 5"
test_ok "3 4 1 5 2"
test_ok "3 4 2 1 5"
test_ok "3 4 2 5 1"
test_ok "3 4 5 1 2"
test_ok "3 4 5 2 1"
test_ok "3 5 1 2 4"
test_ok "3 5 1 4 2"
test_ok "3 5 2 1 4"
test_ok "3 5 2 4 1"
test_ok "3 5 4 1 2"
test_ok "3 5 4 2 1"
test_ok "4 1 2 3 5"
test_ok "4 1 2 5 3"
test_ok "4 1 3 2 5"
test_ok "4 1 3 5 2"
test_ok "4 1 5 2 3"
test_ok "4 1 5 3 2"
test_ok "4 2 1 3 5"
test_ok "4 2 1 5 3"
test_ok "4 2 3 1 5"
test_ok "4 2 3 5 1"
test_ok "4 2 5 1 3"
test_ok "4 2 5 3 1"
test_ok "4 3 1 2 5"
test_ok "4 3 1 5 2"
test_ok "4 3 2 1 5"
test_ok "4 3 2 5 1"
test_ok "4 3 5 1 2"
test_ok "4 3 5 2 1"
test_ok "4 5 1 2 3"
test_ok "4 5 1 3 2"
test_ok "4 5 2 1 3"
test_ok "4 5 2 3 1"
test_ok "4 5 3 1 2"
test_ok "4 5 3 2 1"
test_ok "5 1 2 3 4"
test_ok "5 1 2 4 3"
test_ok "5 1 3 2 4"
test_ok "5 1 3 4 2"
test_ok "5 1 4 2 3"
test_ok "5 1 4 3 2"
test_ok "5 2 1 3 4"
test_ok "5 2 1 4 3"
test_ok "5 2 3 1 4"
test_ok "5 2 3 4 1"
test_ok "5 2 4 1 3"
test_ok "5 2 4 3 1"
test_ok "5 3 1 2 4"
test_ok "5 3 1 4 2"
test_ok "5 3 2 1 4"
test_ok "5 3 2 4 1"
test_ok "5 3 4 1 2"
test_ok "5 3 4 2 1"
test_ok "5 4 1 2 3"
test_ok "5 4 1 3 2"
test_ok "5 4 2 1 3"
test_ok "5 4 2 3 1"
test_ok "5 4 3 1 2"
test_ok "5 4 3 2 1"
test_ok "2147483647 -1 0 1 -2147483648"

echo
echo $GREEN'OK:' $succ
echo $RED'KO:' $fail