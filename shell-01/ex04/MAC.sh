#!/bin/bash
ifconfig -a link | grep ether | cut -f2 -d " "
