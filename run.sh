#! /bin/bash

# check if the diretory exists
check_path_exists () {
  if [ ! -e $1 ]; then
    echo "'$1' doesn't exists" 
    exit 1
  fi
}


# check if the path argument is present
if [ $# -ne 1 ]; then
  echo -e "\e[31mPath argument is not present\e[0m"
  exit 1
fi

# check if the checkOutput executable is present
# if not present built it
checkOutFile="checkOutput.exe" # Executable 
checkOutCpp="checkOutput.cpp" # Source file

if [ ! -e $checkOutFile ]; then
  echo -e "\e[33mCheckOutput Executable is not present... Generating \e[0m"
  clang++ -o $checkOutFile ./checkOutput.cpp
fi

# path to the directory
path=$1

# check if the directory exists
check_path_exists $path

inputFile="$path/input.txt"
outputFile="$path/output.txt"
mainFile="$path/main.cpp"

# check if the all the files are present in the directory
check_path_exists $inputFile
check_path_exists $outputFile
check_path_exists $mainFile

echo -e "\e[32mCompiling the main file\e[0m"

executableFile="$path/main.exe"

# Compile the main.cpp file with clang
clang++ -o $executableFile $mainFile

echo -e "\e[34mCompiled!\e[0m"
echo -e "\e[32mRunning the $executableFile\e[0m\n\n"

# Run the executable with inputs
./$executableFile < $inputFile 
