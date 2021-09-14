#!/bin/bash

ARG=`ruby -e "puts (0.."$1").to_a.shuffle.join(' ')"`
echo $ARG
