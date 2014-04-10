echo POSTBUILDSTEP for $(ProjectName)

xcopy "$(TargetPath)" "$(SolutionDir)$(OutDir)$(TargetFileName)" /i /d /y /F

if errorlevel 1 goto BuildEventFailed

xcopy "$(TargetDir)$(TargetName).pdb" "$(SolutionDir)$(OutDir)$(TargetName).pdb" /i /d /y /F

if errorlevel 1 goto BuildEventFailed

REM Exit properly because the build will not fail

REM unless the final step exits with an error code

goto BuildEventOK

:BuildEventFailed

echo POSTBUILDSTEP for $(ProjectName) FAILED

exit 1

:BuildEventOK

echo POSTBUILDSTEP for $(ProjectName) COMPLETED OK