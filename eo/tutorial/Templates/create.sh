#! /bin/tcsh -f
if ($PWD:t != Templates) then
    echo You must be in the Template dir to run that script
    exit
endif

if ($#argv < 1) then
    echo "Usage $0 ApplicationName [TargetDirName]"
    echo "    will create ../TargetDirName if necessary"
    echo "    (default dir name = ApplicationName)," 
    echo "    and will put there all files that are strictly necessary"
    echo "    to compile and run you Application from there"
    exit
endif

echo " "   # we're going to do something

if ($#argv == 1) then
    set TargetDir = ../$1
else
    set TargetDir = ../$2
endif

if (! -e $TargetDir) then
    mkdir $TargetDir
endif

if ( (-f $TargetDir/eo$1.h) || (-f $TargetDir/eo$1Init.h) || (-f $TargetDir/eo$1EvalFunc.h) || (-f $TargetDir/eo$1Mutation.h) || (-f $TargetDir/eo$1QuadCrossover.h) || (-f $TargetDir/$1EA.cpp) || (-f $TargetDir/make_genotype_$1.h) || (-f $TargetDir/make_op_$1.h) ) then
    echo WARNING: some files already exist there. 
    echo -n "Overwrite ALL (yes/no)? "
    set REP = $<
    if ($REP != "yes") then
       echo Nothing done!
       exit
    endif
endif

if (-f $TargetDir/Makefile) then
    echo A Makefile already exists there.
    echo I'm creating Makefile.$1. You'll have to merge them both, 
    echo OR to call make -f Makefile.$1
    set MakeName = Makefile.$1
else
    set MakeName = Makefile
endif

echo Creating source files for application $1 in $TargetDir/

sed s/MyStruct/$1/g eoMyStruct.tmpl > $TargetDir/eo$1.h
sed s/MyStruct/$1/g init.tmpl > $TargetDir/eo$1Init.h
sed s/MyStruct/$1/g evalFunc.tmpl > $TargetDir/eo$1EvalFunc.h
sed s/MyStruct/$1/g mutation.tmpl > $TargetDir/eo$1Mutation.h
sed s/MyStruct/$1/g quadCrossover.tmpl > $TargetDir/eo$1QuadCrossover.h
sed s/MyStruct/$1/g MyStructEA.cpp > $TargetDir/$1EA.cpp
sed s/MyStruct/$1/g make_genotype_MyStruct.h > $TargetDir/make_genotype_$1.h
sed s/MyStruct/$1/g make_op_MyStruct.h > $TargetDir/make_op_$1.h
sed s/MyStruct/$1/g Makefile.tmpl > $TargetDir/$MakeName

echo Done!

