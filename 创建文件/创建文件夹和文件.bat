for /f %%a in (name.txt) do (if not exist "%%a" (md "%%a"&amp;&amp;echo.>"%%a\%%a.c"))
@echo 伍伊军超帅如果同意：
@pause