# mkdeb
---------------------------------------------------------------
A bash script for making .deb-archives easier to build.
You can install it on Linux, by copying this one-liner into your terminal-emulator:
``` bash
curl https://raw.githubusercontent.com/666hwll/mkdeb/main/mkdeb >> mkdeb && chmod +x mkdeb && sudo mv mkdeb /usr/local/bin/
```

## There is also a newer C++-Version, if you are open to test it.
``` bash
curl https://raw.githubusercontent.com/666hwll/mkdeb/main/mkdeb.cpp >> mkdeb.cpp && g++ mkdeb.cpp -o mkdeb && sudo mv mkdeb /usr/local/bin/
```
