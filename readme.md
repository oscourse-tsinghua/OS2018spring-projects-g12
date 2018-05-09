this is a readme.md  
os.cs.tsinghua.edu.cn/oscourse/OS2018spring/projects/g12  
how to run makefile  

```shell
apt-get install libncurses5 libncurses5-dev

make O=out ARCH=amd64 defconfig  
make O=out ARCH=amd64 > makeout.txt 2>&1

python run_all.py -l /dockershare/llvm_bitcode_out -a 5 -m /dockershare/ucore/makeout.txt -g \"\"gcc -n 2 -o /dockershare/ucore/out -k /dockershare/ucore -f /dockershare/dr_checker_out // 有问题

-skb -skl -skp -ske -ski
```
