#!/bin/bash
cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | rev | sed "s/.*\*://" | sort -r |sed -n '7, 15 p' | tr "\n" ", " | sed '$s/.$//' | sed 's/, */, /g' | tr "\n" "."
