CHCP 936
@ECHO OFF

SET DST_FILE=packet_normal.xml

:::::::::::::::::::::::::遍历resource文件夹 BEGIN::::::::::::::::::::::::::::::::
setlocal enabledelayedexpansion

SET rootdir=%cd%
:: 计算%rootdir%的长度，亦即要去掉的路径前缀的长度
SET tmp=%rootdir%'
SET cut=
:loop
IF NOT "!tmp!"=="" (
    SET /a cut += 1
    SET tmp=!tmp:~1!
    GOTO :loop
)

:: 遍历%rootdir%下的resource文件夹
FOR /R "resource" %%I IN (*) DO (
	:: 获取完整路径
    SET J=%%~fI
    :: 去掉前面cut个字符，获得相对路径（打包程序不支持绝对路径）
    SET J=!J:~%cut%!
    ECHO !J!
)
:::::::::::::::::::::::::遍历resource文件夹 END::::::::::::::::::::::::::::::::::
