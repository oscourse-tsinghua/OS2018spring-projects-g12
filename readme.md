WIKI地址： os.cs.tsinghua.edu.cn/oscourse/OS2018spring/projects/g12  

文件夹dr_checker下为dr_checker的相关内容
- 其中docker/dockershare/dr_checker的代码
- 运行dr_checker

```shell
cd dr_checker/docker  
sudo docker-compose run main /bin/bash
进入docker之后
cd /dockershare/
sh build.sh #将dr_checker复制进去
cd /dr_checker/dr_checker/llvm_scripts
sh build.sh
cd /dr_checker/dr_checker/helper_scripts/runner_scripts
python run_all.py -l /dockershare/llvm_bitcode_out -a 5 -m /dockershare/ucore/makeout.txt -g \"\"gcc -n 2 -o /dockershare/ucore/out -k /dockershare/ucore -f /dockershare/dr_checker_out 
  可以通过 -skb -skl -skp -ske -ski 去跳过相应的步骤.  
```

文件夹ucore_plus为ucore_plus的代码(修改过部分makefile）
- 运行makefile
```shell
apt-get install libncurses5 libncurses5-dev
make O=out ARCH=amd64 defconfig  
make O=out ARCH=amd64 > makeout.txt 2>&1
```
