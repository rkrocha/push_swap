#!/bin/bash

[ -z "$3" ] && iter=1 || iter="$3"

for i in $(seq 1 "$iter")
do
	ruby -e "puts ("$1".."$2").to_a.shuffle.join(' ')"
done
