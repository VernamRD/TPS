@echo off

rem Engine params
set EnginePath_4.27=D:\JenkinsJobs\UE Source
set EnginePath_4.27_InstalledBuild=D:\JenkinsJobs\UE Source\UE_4.27_InstalledBuild

rem !!Engine version for packaging!!
set RunUATPath=%EnginePath_4.27_InstalledBuild%\Engine\Build\BatchFiles\RunUAT.bat

rem Project params
set ProjectRoot=E:\UE Projects\TPS
set ProjectName=TPS.uproject
set ProjectPath=%ProjectRoot%\%ProjectName%

rem Config
set Platform=Win64
set Configuration=Development