#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

; Win+J to press Enter and await launch
#j::
    DllCall("QueryPerformanceFrequency", "Int64*", CounterFreq)
    DllCall("QueryPerformanceCounter", "Int64*", CounterBefore)
    Send, {Enter}
    WinWaitActive, GUI Sample Application
    DllCall("QueryPerformanceCounter", "Int64*", CounterAfter)
    MsgBox % (CounterAfter - CounterBefore)/CounterFreq . "s"
Return

; Win+M to click mouse1 and await launch
#m::
    DllCall("QueryPerformanceFrequency", "Int64*", CounterFreq)
    DllCall("QueryPerformanceCounter", "Int64*", CounterBefore)
    Click
    WinWaitActive, GUI Sample Application
    DllCall("QueryPerformanceCounter", "Int64*", CounterAfter)
    MsgBox % (CounterAfter - CounterBefore)/CounterFreq . "s"
Return
