#!/bin/bash 

########################################################################
# 
# cityandyear.sh.pseudocode - MNXB01-2021 Homework 3
#Changed to cityandyear.sh
#
# Author: Florido Paganelli florido.paganelli@hep.lu.se 
#Modified by Tanvir Sayed
#
# Description: This script takes as input 
#                 - a directory where SMHI files are stored,
#                 - a Swedish city name 
#                 - a year
#              It finds the required data file and 
#              extracts only data for such city and year
#              The data extraction must be done using 
#              the case study smhicleaner.sh
#              The script is only compatible with a certain format
#              of SMHI csv files.
#			Note- The helperfunctions and smhicleaner.sh files should be in the
#			same directory as this cityandyear.sh script for the code to run properly
# Examples:
#        ./cityandyear.sh ~/mydata/ Ystad 1983
#
#
# Note: The slide numbers in the pseudocode below refer to Tutorial3
#       if not otherwise stated.
#
########################################################################

#### Evaluation of the score ######################################
# 
# The maximum points for this homework are 12.
# Each task shows how much points you can score with such task.
# 
# I will grade the homework based on this scale:
# Score 0-5: Grade 1, failed, not acceptable
# Score 6-8: Grade 2,  just above the acceptance limit, a very minimalistic solution
# Score 9-10: Grade 3, good solution, though not 100% correct
# Score 11-12: Grade 4,  perfect and complete solution of the task
# Grade 5 is possible if and only if you already scored Grade 4, see homework description
#
# If the homework is completed by the deadline you will be given a chance
# to improve your score based on tips.
#
# If the homework is submitted after the deadline there will be no chance.
#
# The deadline may change due to my workload, if I cannot correct your homework 
#  in order to give you proper feedback, I will postpone the deadline.
# The deadline is on Canvas.
#
########################################################################


# E1 (1 point) Store parameters in human-readable variables
# Store the arguments of the script in the variables below
# See Slides: 36, 40
DATAPATH=$1 # no spaces!
CITY=$2
YEAR=$3

# E2 (1 point) Load helper library
# Use the source command to load the provided helper library
#   helperfunctions
# Inspect the helper library to understand what the code does.
# See Slides: 51-74 and Environment clip
#echo $0
dirNAME=`dirname "$0"`
#echo $dirNAME
source $dirNAME/helperfunctions #The helperfunction 'sourced' from the same folder as the cityandyear.sh script

### DO NOT TOUCH OR MODIFY THIS CODE BELOW #############################
# this code will only work properly if you did E2 properly.
# The interpreter will show an error and stop the execution if any problem.

CHECKFUNCTIONS=$(type -t checkparameters)
if [[ $CHECKFUNCTIONS != 'function' ]]; then
	echo "Helper functions missing, please check your code in E2"
	exit 1
fi 

# Check the input parameters using the library loaded above
checkparameters

# check that the DATAPATH is a directory using the library
checkdir $DATAPATH

### END OF UNTOUCHABLE CODE ############################################

# E3 (4 points) Find the datafile containing the city
# E3.1 (2 points) Store the file path in a variable called CITYFILE
# use grep to find the file that contains the city name among those in DATAPATH.
# To make your life easier, find how to make grep printout just a filename.
# There is an option just for that, check `man grep` for "General Output Control".
# Make grep case insensitive, use the -i option so I can search for yStaD and find Ystad anyway.
# The best way to do this exercise is to run grep at the command line
# to check what the output looks like.
# Learn about these commands by looking at Slides 53, 84, smhicleaner.sh code, 
# and previous years homeworks solutions
Og=`pwd` #recording original directory where script is run
#echo $Og
cd $DATAPATH
CITYFILE="$DATAPATH/`grep -i -l -m 2 $CITY *`" # - m 2
#echo $CITYFILE
cd $Og

# E3.2 (2 points) Print an error and exit if the city is not found and exit with error.
# Hint: check the content of the CITYFILE variable.
# See Slides: 43-47
if [[ "x$CITYFILE" == "x$DATAPATH/" ]]; then
	echo "City $CITY not found, exiting"
	exit 1
fi

# DO NOT MODIFY. If the city is found we print out the path
# If your code prints out "found file" without a filename, something
# is wrong. check the code above again.
echo "found file $CITYFILE"

# DO NOT MODIFY. Now we can run the smhicleaner.sh script on the file to extract some
# data
echo "running smhicleaner on file $CITYFILE"

# E4 (2 points) Run the smhicleaner.sh script passing the CITYFILE as argument.
# Redirect both standard error and standard output to a file called
# shmicleaner.log
# Run the smhicleaner.sh at the command line to understand how to use it,
# what files it generates and what are the command line parameters.
# See manual section 5.2, Tutorial 2, and read about redirection here:
# https://www.gnu.org/software/bash/manual/html_node/Redirections.html

$dirNAME/smhicleaner.sh $CITYFILE > ./shmicleaner.log 2>&1

# E5 (1 point) Identify the generated rawfile_<datafile> generated by smhicleaner.sh
# use the basename command to extract just the filename of CITYFILE without the path
# Save the result in a variable RAWFILE
# To learn more about the basename command you can read the manpage and 
# this link: https://linuxize.com/post/basename-command-in-linux/
# the content of the variable should be like
#    smhi-opendata_1_52230_20210906_212532.csv
# or whatever is the original filename of the dataset that contains the info about the city.
RAWFILENAME=$(basename $CITYFILE)
#echo $RAWFILENAME

# DO NOT MODIFY. If the filename above has been correctly found, we can rewrite the content
# of the rawfile variable so that we can use smhicleaner output to complete
# the task:
RAWFILENAME="rawdata_${RAWFILENAME}"
echo "Found RAW data: $RAWFILENAME. Start processing with grep..."

# E6 (3 points) Extract the requested data
# E6.1 (1 point) Use grep to extract from RAWFILE the requested lines containing YEAR
# and print them on screen.
# # Learn about the grep command by looking at Slides 53, 84, smhicleaner.sh code, 
# and previous years homeworks solutions
#yearlines="`grep -h $YEAR $RAWFILENAME`"
#echo $yearlines
grep -h $YEAR $RAWFILENAME

#yearlines="`grep -h $YEAR $RAWFILENAME`" #all the output from grep goes into 1 line when I do this # dont need this

# E6.2 (2 points) If the year is not found, print an error message and exit with error.
# Hint: check the exit status of the grep command you ran above. 
# See Slides: 41-47
if [[ $? != 0 ]]; then
        echo "Year $YEAR not found, exiting"
        exit 1
fi

