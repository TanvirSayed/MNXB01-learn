#!/bin/sh
#SBATCH -J "hw4"
#SBATCH --time=00:03:00 
#SBATCH -A lu2021-7-19

#echo "CPU info:"
#cat /proc/cpuinfo
#echo "memory details:"
#cat /proc/meminfo
echo "user:"
whoami
echo "current directory:"
pwd
echo 'hostname:'
hostname
echo 'uptime info:'
uptime
echo 'disk space usage:'
du -h
echo 'No of entries in /etc: '
ls /etc | wc -l
echo 'No of entries in /usr/bin directories'
ls /usr/bin | wc -l 

sleep 2m
