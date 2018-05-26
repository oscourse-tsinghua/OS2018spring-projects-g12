# 操作系统大实验设计文档

计52 2015011264 刘攀 

计52 2015011258 沈俊贤

实验wiki页面 http://os.cs.tsinghua.edu.cn/oscourse/OS2018spring/projects/g12

## 运行实验代码

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
### 可视化

在docker外面运行可视化，首先将ucore_plus的代码copy到/dockershare/，

然后将server/config.py中的RESULT_DIRS变量改为本机dr_checker_out的路径

然后运行

``` shell
python ./server/app.py
serve -s ./client/build
```

在浏览器中运行shell提示的网址即可


## 实验目标及计划

实验目标描述：尝试一些论文或者工具的方式来寻找ucore_plus的bug

1. 利用Dr.Checker，重现论文查找ucore_plus的driver的bug
2. 对前面进行扩展，利用论文的思想和方法来寻找ucore_plus的bug

## 实验细节

### Dr.Checker原理

![](https://github.com/oscourse-tsinghua/OS2018spring-projects-g12/blob/master/final_report/pictures/dr_checker.png)

#### 概述

Dr.Checker主要分成五个部分，在通过将操作系统内核生成的中间文件转化成llvm bitcode之后，会调用Driver link、Parse Headers和Entry Point Identifier生成要进行最终检查的函数入口。在最后进行的检查中，我们关注于

- Function local variables
- Dynamically allocated variables
- Global variables

三种变量，和llvm的

- Alloca
- binOp
- Load
- Store
- GetElementPtr

五种操作。在对核心代码进行SDTraversal遍历之后，我们通过对得到的有序的SCC进行分析，最后得到detector检测到的warnings

![](https://github.com/oscourse-tsinghua/OS2018spring-projects-g12/blob/master/final_report/pictures/traversal.png)


#### 编译操作系统内核并生成中间文件

操作系统将在make中间过程生成的代码文件

#### llvm bitcode generation

相关工具

<https://github.com/llvm-mirror/llvm>

 <https://github.com/llvm-mirror/clang> 其中的工具生成 llvm bitcode

####Driver link

driver link的作用是将需要检测的文件夹下的文件以llvm的形式链接起来，最后在所有目录文件夹下都生成索引

#### Parse Headers

parse headers的原作用是将kernel中引用的linux的库文件进行检测，对满足含有`op {}`或者`operation {}`的文件，检测其中的entry point

#### Entry Point Identifier

这部分是对所有指定文件夹下的文件进行entry point检测

#### Soundy Analysis Runner

这部分是工具的核心部分，通过对sdtraversal算法的运行，在运行过程中同时用client进行Detector进行检测。

## 在原有的代码中进行的改动

#### 编译操作系统内核并生成中间文件

将ucore plus的make生成结果输出到了makeout.txt当中，这个过程需要修改ucore_plus的makefile来修改产生makeout.txt  
1. 发现ucore_plus目录下的makefile有一些变量没什么用，疑似移植的残留，比如quiet，KBUILD_VERBOSE等 
2. 修改ucore_plus/ucore/src/kern-ucore/Makefile.subdir 
- 新增NOW_DIR = $(shell pwd) 
- $(OBJPATH)/%.ko: %.c 变成 $(OBJPATH)/%.ko: $(NOW_DIR)/%.c   
这样在makeout.txt输出的文件路径为绝对路径而不是相对makefile.subdir的相对路径，保证后面的分析能够根据输出信息找到对应的文件 

#### llvm bitcode generation

使用工具进行llvm bitcode的生成，选择忽略.S汇编文件

#### Driver link

将driver的范围扩大到所有的文件夹

#### Parse Headers

通过实验和比对，这部分的内容和driver更加相关，这让我们很难修改，同时通过对example的对比，我们发现这部分的主要作用本身在论文范围内的意义就不大，对我们所要进行的移植则没有意义，所以最后选择忽略。

#### Entry Point Identifier

在这部分中，更改了entrypoint的检测条件，最终能够产生105个entry，并增加了一种新的entry的类型作为普通的entry

#### Soundy Analysis Runner

在这部分中我们增加了四种detector的检测范围，让这四种detector中可以生成正确的结果。

## 实验分工

沈俊贤：
论文阅读以及代码分析  
llvm的学习  
完成llvm的build   
完成driver_linker的修改  
完成ParseHeaders的修改  
完成EntryPointIdentifier的修改  
核对验证找出来的warnings  

刘攀：
论文阅读以及代码分析  
llvm的学习  
ucore_plus的分析，修改部分makefile  
完成llvm的build  
完成SoundyAnalysisRunner的修改  
完成可视化工作  
核对验证找出来的warnings  

## 实验结果分析

一些细节需要后续把图片粘贴到这里

当前的总warning数量如下：

![](https://github.com/oscourse-tsinghua/OS2018spring-projects-g12/blob/master/final_report/pictures/warnings.png)

## 对bug的确认

在现在的状态下，有主要作用的是TLBD、GVRD、TAD这三种warning的报告，分别代表有可能被污染的数据作为循环边界、没有加锁的全局变量和有可能产生运算溢出的数据。  
这些detector主要是用于找到warning而不是用于寻找bug，比如说整数溢出，在静态代码分析是很难确定这是一个bug的，只是确定这个操作可能会出现问题。

找到的warning如下：


