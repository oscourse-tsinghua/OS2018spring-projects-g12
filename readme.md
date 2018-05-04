this is a readme.md  
os.cs.tsinghua.edu.cn/oscourse/OS2018spring/projects/g12  
how to run makefile  

```shell
make O=out ARCH=arm64 defconfig  
make ARCH=arm64 > makeout.txt 2>&1

python run_all.py -l /dockershare/llvm_bitcode_out -a 1 -m /dockershare/ucore/makeout.txt -g ""gcc -n 2 -o /dockershare/ucore/out -k /dockershare/ucore -f /dockershare/dr_checker_out

```
