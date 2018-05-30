WIKI地址： os.cs.tsinghua.edu.cn/oscourse/OS2018spring/projects/g12  

文件夹dr_checker下为dr_checker的相关内容
- 其中docker/dockershare/dr_checker的代码
- 运行dr_checker

## 环境配置
推荐使用docker
### 安装Docker
如果已经有docker和docker-compose，可以忽略这一步。
```
cd <repo_path>/dr_checker/docker/
./install_docker.sh
```
### 下载镜像
```
cd <repo_path>/docker/
docker-compose pull
```

### 运行
要先将ucore_plus代码编译好，放入dockershare/文件夹中  
文件夹ucore_plus为ucore_plus的代码(修改过部分makefile）
- 运行makefile
```shell
apt-get install libncurses5 libncurses5-dev
make O=out ARCH=amd64 defconfig  
make O=out ARCH=amd64 > makeout.txt 2>&1
```

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

如何在本机运行？（可能会有点问题)

``` shell
sudo apt-get install cmake libxml2-dev

cd dr_checker/docker/dockershare/dr_checker/helper_scripts
python setup_drchecker.py -o drchecker_deps
自此环境理论上就已经安装完成了，但是由于机器的限制（build llvm需比较大的内存）我们没有测试过。。。

下面就是怎么运行：
dr_checker的代码在dr_checker/docker/dockershare/dr_checker下
cd <repo_path>/dr_checker/docker/dockershare/dr_checker

cd llvm_scripts
sh build.sh
cd ..

cd help_scripts/runner_scripts
运行run_all.py，可以参考docker的运行

```

How to run:
```
python run_all.py --help
usage: run_all.py [-h] [-l LLVM_BC_OUT] [-a CHIPSET_NUM] [-m MAKEOUT] [-g COMPILER_NAME] [-n ARCH_NUM] [-o OUT] [-k KERNEL_SRC_DIR] [-skb] [-skl] [-skp] [-ske] [-ski] [-f SOUNDY_ANALYSIS_OUT]

optional arguments:
  -h, --help            show this help message and exit
  -l LLVM_BC_OUT        Destination directory where all the generated bitcode files should be stored.
  -a CHIPSET_NUM        Chipset number. Valid chipset numbers are:
                        1(mediatek)|2(qualcomm)|3(huawei)|4(samsung)
  -m MAKEOUT            Path to the makeout.txt file.
  -g COMPILER_NAME      Name of the compiler used in the makeout.txt, This is
                        needed to filter out compilation commands. Ex: aarch64-linux-android-gcc
  -n ARCH_NUM           Destination architecture, 32 bit (1) or 64 bit (2).
  -o OUT                Path to the out folder. This is the folder, which
                        could be used as output directory during compiling
                        some kernels. (Note: Not all kernels needs a separate out folder)
  -k KERNEL_SRC_DIR     Base directory of the kernel sources.
  -skb                  Skip LLVM Build (default: not skipped).
  -skl                  Skip Dr Linker (default: not skipped).
  -skp                  Skip Parsing Headers (default: not skipped).
  -ske                  Skip Entry point identification (default: not
                        skipped).
  -ski                  Skip Soundy Analysis (default: not skipped).
  -f SOUNDY_ANALYSIS_OUT    Path to the output folder where the soundy analysis output should be stored.

```



