@echo off
set MATLAB=C:\Program Files\MATLAB\R2007a
"%MATLAB%\rtw\bin\win32\gmake" -f NNEntradaRadom.mk  GENERATE_REPORT=0 ADD_MDL_NAME_TO_GLOBALS=1
