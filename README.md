# YPP_Flag_Shoppes

Script to create a list of all stalls owned or managed by active flag members
The script accepts as many flag URLs as one wants, and needs the last argument to be where to save the list of businesse.

# Compiling

The script has been develoved on windows, using Visual Studio Code and Visual Studio 2019, through CMake.
It can also be compiled in Ubuntu with ease. However, CURL seems to get stuck while downloading and I can't spot the problem yet.

# External libraries

[libcurl](https://curl.haxx.se/libcurl/) library has been used in order to interact with the yppedia webpages containing the info. They are provided directly so no installation is needed.
You need to have [OpenSSL](https://slproweb.com/products/Win32OpenSSL.html) installed for the program to run.
