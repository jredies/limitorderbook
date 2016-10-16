#!/bin/bash
cat logs/small.in | ./pricer 200 > logs/small_my.out.200
cat logs/pricer.in | ./pricer 1 > logs/pricer_my.out.1
cat logs/pricer.in | ./pricer 200 > logs/pricer_my.out.200
cat logs/pricer.in | ./pricer 10000 > logs/pricer_my.out.10000
